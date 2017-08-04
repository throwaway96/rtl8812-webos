/******************************************************************************
 *
 * Copyright(c) 2007 - 2011 Realtek Corporation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 *
 ******************************************************************************/

#if 0
	/* ============================================================
	*  include files
	* ============================================================ */
#endif

#include "mp_precomp.h"
#include "../phydm_precomp.h"

#if (RTL8822B_SUPPORT == 1)


void
phydm_dynamic_switch_htstf_mumimo_8822b(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	/*if rssi > 40dBm, enable HT-STF gain controller, otherwise, if rssi < 40dBm, disable the controller*/
	/*add by Chun-Hung Ho 20160711 */
	if (p_dm_odm->rssi_min >= 40)
		odm_set_bb_reg(p_dm_odm, 0x8d8, BIT(17), 0x1);
	else if (p_dm_odm->rssi_min < 35)
		odm_set_bb_reg(p_dm_odm, 0x8d8, BIT(17), 0x0);

	ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("%s, rssi_min = %d\n", __func__, p_dm_odm->rssi_min));
}


static
VOID
_setTxACaliValue(
	struct PHY_DM_STRUCT		*p_dm_odm,
	IN u1Byte						eRFPath,
	IN u1Byte 						offset,
	IN u1Byte 						TxABiaOffset
	)
{
	u4Byte modiTxAValue = 0;
	u1Byte tmp1Byte = 0;
	BOOLEAN bMinus = FALSE;
	u1Byte compValue = 0;
	
		switch (offset) {
		case 0x0:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X10124);
			break;
		case 0x1:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X10524);
			break;
		case 0x2:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X10924);
			break;
		case 0x3:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X10D24);
			break;
		case 0x4:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X30164);
			break;
		case 0x5:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X30564);
			break;
		case 0x6:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X30964);
			break;
		case 0x7:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X30D64);
			break;
		case 0x8:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X50195);
			break;
		case 0x9:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X50595);
			break;
		case 0xa:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X50995);
			break;
		case 0xb:
			odm_set_rf_reg(p_dm_odm, eRFPath, 0x18, 0xFFFFF, 0X50D95);
			break;
		default:
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("Invalid TxA band offset...\n"));
			return;
			break;
	}

	/* Get TxA value */
	modiTxAValue = odm_get_rf_reg(p_dm_odm, eRFPath, 0x61, 0xFFFFF);
	tmp1Byte = (u1Byte)modiTxAValue&(BIT3|BIT2|BIT1|BIT0);

	/* check how much need to calibration */
		switch (TxABiaOffset) {
		case 0xF6:
			bMinus = TRUE;
			compValue = 3;
			break;
			
		case 0xF4:
			bMinus = TRUE;
			compValue = 2;
			break;
			
		case 0xF2:
			bMinus = TRUE;
			compValue = 1;
			break;
			
		case 0xF3:
			bMinus = FALSE;
			compValue = 1;
			break;
			
		case 0xF5:
			bMinus = FALSE;
			compValue = 2;	
			break;
			
		case 0xF7:
			bMinus = FALSE;
			compValue = 3;
			break;
			
		case 0xF9:
			bMinus = FALSE;
			compValue = 4;
			break;
		
		/* do nothing case */
		case 0xF0:
		default:
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("No need to do TxA bias current calibration\n"));
			return;
			break;
	}

	/* calc correct value to calibrate */
	if (bMinus) {
		if (tmp1Byte >= compValue) {
			tmp1Byte -= compValue;
			//modiTxAValue += tmp1Byte;
		} else {
			tmp1Byte = 0;
		}
	} else {
		tmp1Byte += compValue;
		if (tmp1Byte >= 7) {
			tmp1Byte = 7;
		}
	}

	/* Write back to RF reg */
	odm_set_rf_reg(p_dm_odm, eRFPath, 0x30, 0xFFFF, (offset<<12|(modiTxAValue&0xFF0)|tmp1Byte));
}

static
VOID
_txaBiasCali4eachPath(
	struct PHY_DM_STRUCT		*p_dm_odm,
	IN	u1Byte	 eRFPath,
	IN	u1Byte	 efuseValue
	)
{
	/* switch on set TxA bias */
	odm_set_rf_reg(p_dm_odm, eRFPath, 0xEF, 0xFFFFF, 0x200);

	/* Set 12 sets of TxA value */
	_setTxACaliValue(p_dm_odm, eRFPath, 0x0, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x1, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x2, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x3, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x4, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x5, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x6, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x7, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x8, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0x9, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0xa, efuseValue);
	_setTxACaliValue(p_dm_odm, eRFPath, 0xb, efuseValue);

	// switch off set TxA bias
	odm_set_rf_reg(p_dm_odm, eRFPath, 0xEF, 0xFFFFF, 0x0);
}

/* for 8822B PCIE D-cut patch only */
/* Normal driver and MP driver need this patch */

VOID
phydm_txcurrentcalibration(
	struct PHY_DM_STRUCT		*p_dm_odm
	)
{
	u1Byte			efuse0x3D8, efuse0x3D7;
	u4Byte			origRF0x18PathA = 0, origRF0x18PathB = 0;

	/* save original 0x18 value */
	origRF0x18PathA = odm_get_rf_reg(p_dm_odm, ODM_RF_PATH_A, 0x18, 0xFFFFF);
	origRF0x18PathB = odm_get_rf_reg(p_dm_odm, ODM_RF_PATH_B, 0x18, 0xFFFFF);
	
	/* define efuse content */
		efuse0x3D8 = p_dm_odm->efuse0x3d8;
		efuse0x3D7 = p_dm_odm->efuse0x3d7;
	
	/* check efuse content to judge whether need to calibration or not */
	if (0xFF == efuse0x3D7) {
		ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("efuse content 0x3D7 == 0xFF, No need to do TxA cali\n"));
		return;
	}

	/* write RF register for calibration */
	_txaBiasCali4eachPath(p_dm_odm, ODM_RF_PATH_A, efuse0x3D7);
	_txaBiasCali4eachPath(p_dm_odm, ODM_RF_PATH_B, efuse0x3D8);
	
	/* restore original 0x18 value */
	odm_set_rf_reg(p_dm_odm, ODM_RF_PATH_A, 0x18, 0xFFFFF, origRF0x18PathA);
	odm_set_rf_reg(p_dm_odm, ODM_RF_PATH_B, 0x18, 0xFFFFF, origRF0x18PathB);
}

void
phydm_somlrxhp_setting(
	struct 	PHY_DM_STRUCT		*p_dm_odm,
	boolean switch_soml
)
{
	if (switch_soml == true) {
		odm_set_bb_reg(p_dm_odm, 0x19a8, MASKDWORD, 0xd90a0000);
	/* Following are RxHP settings for T2R as always low, workaround for OTA test, required to classify */
		odm_set_bb_reg(p_dm_odm, 0xc04, (BIT(21)|BIT(18)), 0x0);
		odm_set_bb_reg(p_dm_odm, 0xe04, (BIT(21)|BIT(18)), 0x0);
	} else {
		odm_set_bb_reg(p_dm_odm, 0x19a8, MASKDWORD, 0x010a0000);
	}
	
	/* Dynamic RxHP setting with SoML on/off apply on all RFE type, except of QFN eFEM (1,6,7,9) */
	if ((switch_soml == false) && ((p_dm_odm->rfe_type == 1) || (p_dm_odm->rfe_type == 6) || (p_dm_odm->rfe_type == 7) || (p_dm_odm->rfe_type == 9))) {
		odm_set_bb_reg(p_dm_odm, 0x8cc, MASKDWORD, 0x08108000);
		odm_set_bb_reg(p_dm_odm, 0x8d8, BIT(27), 0x0);
	}
		
	if (*p_dm_odm->p_channel <= 14) {
		if ((switch_soml == true) && (!((p_dm_odm->rfe_type == 3) || (p_dm_odm->rfe_type == 5)))) {
			odm_set_bb_reg(p_dm_odm, 0x8cc, MASKDWORD, 0x08108000);
			odm_set_bb_reg(p_dm_odm, 0x8d8, BIT(27), 0x0);
		}
	} else if (*p_dm_odm->p_channel > 35) {
		if (switch_soml == true) {
			odm_set_bb_reg(p_dm_odm, 0x8cc, MASKDWORD, 0x08108000);
			odm_set_bb_reg(p_dm_odm, 0x8d8, BIT(27), 0x0);
		}
	}
}

void
phydm_dynamic_ant_weighting_8822b(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	u8 rssi_l2h = 43, rssi_h2l = 37;
	u8 reg_8;
	u8 set_result_nbi = SET_NO_NEED;

	if (p_dm_odm->is_disable_dym_ant_weighting)
		return;

	if (*p_dm_odm->p_channel <= 14) {
		if (p_dm_odm->rssi_min >= rssi_l2h) {
			odm_set_bb_reg(p_dm_odm, 0x98c, 0x7fc0000, 0x0);
			odm_set_bb_reg(p_dm_odm, 0x818, BIT(26), 0x0);
			odm_set_bb_reg(p_dm_odm, 0xc04, (BIT(18)|BIT(21)), 0x0);
			odm_set_bb_reg(p_dm_odm, 0xe04, (BIT(18)|BIT(21)), 0x0);
			/*equal weighting*/
			reg_8 = odm_get_bb_reg(p_dm_odm, 0xf94, BIT(0)|BIT(1)|BIT(2));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("Equal weighting ,rssi_min = %d\n, 0xf94[2:0] = 0x%x\n", p_dm_odm->rssi_min, reg_8));
		} else if (p_dm_odm->rssi_min <= rssi_h2l) {
			odm_set_bb_reg(p_dm_odm, 0x98c, MASKDWORD, 0x43440000);
			odm_set_bb_reg(p_dm_odm, 0x818, BIT(26), 0x1);
			odm_set_bb_reg(p_dm_odm, 0xc04, (BIT(18)|BIT(21)), 0x0);
			odm_set_bb_reg(p_dm_odm, 0xe04, (BIT(18)|BIT(21)), 0x0);	
			/*fix sec_min_wgt = 1/2*/
			reg_8 = odm_get_bb_reg(p_dm_odm, 0xf94, BIT(0)|BIT(1)|BIT(2));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("AGC weighting ,rssi_min = %d\n, 0xf94[2:0] = 0x%x\n", p_dm_odm->rssi_min, reg_8));
        	}
	} else {
			odm_set_bb_reg(p_dm_odm, 0x98c, MASKDWORD, 0x43440000);
			odm_set_bb_reg(p_dm_odm, 0x818, BIT(26), 0x1);
			odm_set_bb_reg(p_dm_odm, 0xc04, (BIT(18)|BIT(21)), 0x0);
			odm_set_bb_reg(p_dm_odm, 0xe04, (BIT(18)|BIT(21)), 0x0);
			reg_8 = odm_get_bb_reg(p_dm_odm, 0xf94, BIT(0)|BIT(1)|BIT(2));
			ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("AGC weighting ,rssi_min = %d\n, 0xf94[2:0] = 0x%x\n", p_dm_odm->rssi_min, reg_8));
		/*fix sec_min_wgt = 1/2*/
    	}

	if ((*p_dm_odm->p_channel == 6) && (p_dm_odm->rssi_min <= rssi_h2l) && (*p_dm_odm->p_band_width == ODM_BW20M)) {
		set_result_nbi = phydm_nbi_setting(p_dm_odm, NBI_ENABLE, *p_dm_odm->p_channel, 20, 2440, PHYDM_DONT_CARE);
	} else {
		set_result_nbi = phydm_nbi_setting(p_dm_odm, NBI_DISABLE, *p_dm_odm->p_channel, 20, 2440, PHYDM_DONT_CARE);
	}
	
	if ((*p_dm_odm->p_band_width == ODM_BW20M) && (*p_dm_odm->p_channel == 11) && (p_dm_odm->rfe_type == 3) && (p_dm_odm->RSSI_A < 40)) {
		odm_set_bb_reg(p_dm_odm, 0x830, BIT(13)|BIT(14)|BIT(15)|BIT(16), 0xa);
	} else {
		odm_set_bb_reg(p_dm_odm, 0x830, BIT(13)|BIT(14)|BIT(15)|BIT(16), 0x7);
	}

}


void
phydm_hwsetting_8822b(
	struct PHY_DM_STRUCT		*p_dm_odm
)
{
	if (p_dm_odm->bhtstfdisabled == false)
		phydm_dynamic_switch_htstf_mumimo_8822b(p_dm_odm);
	else
		ODM_RT_TRACE(p_dm_odm, ODM_COMP_COMMON, ODM_DBG_LOUD, ("Default HT-STF gain control setting\n"));
	
	phydm_dynamic_ant_weighting_8822b(p_dm_odm);
}

#endif	/* RTL8822B_SUPPORT == 1 */
