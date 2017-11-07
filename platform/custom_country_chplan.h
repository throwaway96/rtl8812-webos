/******************************************************************************
 *
 * Copyright(c) 2013 Realtek Corporation. All rights reserved.
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

//#error "You have defined CONFIG_CUSTOMIZED_COUNTRY_CHPLAN_MAP to use a customized map of your own instead of the default one"
//#error "Before removing these error notifications, please make sure regulatory certification requirements of your target markets"

static const struct country_chplan CUSTOMIZED_country_chplan_map[] = {
	COUNTRY_CHPLAN_ENT2("AU", 0x22, 1, 0x1FB, 0), /* Australia */
	COUNTRY_CHPLAN_ENT2("BO", 0x23, 1, 0x1F1, 0), /* Bolivia */
	COUNTRY_CHPLAN_ENT2("BZ", 0x24, 1, 0x000, 0), /* Brazil, Peru, Philippines */
	COUNTRY_CHPLAN_ENT2("CH", 0x25, 1, 0x1FB, 0), /* Hong Kong, China */
	COUNTRY_CHPLAN_ENT2("CL", 0x26, 1, 0x1F1, 0), /* Chile, Paraguay, Uruguay */
	COUNTRY_CHPLAN_ENT2("DC", 0x27, 1, 0x1FB, 0), /* LGE Default CE */
	COUNTRY_CHPLAN_ENT2("DC", 0x28, 1, 0x1FB, 1), /* LGE Default v1 FCC */
	COUNTRY_CHPLAN_ENT2("EC", 0x29, 1, 0x1F1, 0), /* Ecuador */
	COUNTRY_CHPLAN_ENT2("EG", 0x25, 0, 0x1F1, 0), /* Egypt */
	COUNTRY_CHPLAN_ENT2("EU", 0x2a, 1, 0x1FB, 0), /* Germany */
	COUNTRY_CHPLAN_ENT2("HK", 0x2b, 1, 0x1FB, 0), /* Lebanon, Jordan, Srilanka */
	COUNTRY_CHPLAN_ENT2("HN", 0x19, 1, 0x1F1, 0), /* Honduras */
	COUNTRY_CHPLAN_ENT2("ID", 0x2c, 0, 0x1F3, 0), /* Indonesia */
	COUNTRY_CHPLAN_ENT2("IR", 0x2d, 1, 0x1F3, 0), /* Iran */
	COUNTRY_CHPLAN_ENT2("JP", 0x2e, 1, 0x1FF, 0), /* Japan- Telec */
	COUNTRY_CHPLAN_ENT2("KR", 0x3a, 1, 0x1FB, 0), /* South Korea */
	COUNTRY_CHPLAN_ENT2("KR", 0x3a, 1, 0x1FB, 1), /* South Korea v1 */
	COUNTRY_CHPLAN_ENT2("KZ", 0x21, 1, 0x100, 0), /* Kazakhstan */
	COUNTRY_CHPLAN_ENT2("MM", 0x20, 1, 0x000, 0), /* Burma (Myanmar) */
	COUNTRY_CHPLAN_ENT2("MR", 0x31, 1, 0x1F1, 0), /* Morocco */
	COUNTRY_CHPLAN_ENT2("MX", 0x32, 1, 0x1F1, 0), /* Mexico */
	COUNTRY_CHPLAN_ENT2("MY", 0x25, 1, 0x1F1, 0), /* Malaysia */
	COUNTRY_CHPLAN_ENT2("NP", 0x33, 1, 0x1FB, 0), /* Nepal */
	COUNTRY_CHPLAN_ENT2("NZ", 0x30, 1, 0x1FB, 0), /* New Zealand */
	COUNTRY_CHPLAN_ENT2("PK", 0x34, 1, 0x1F1, 0), /* Pakistan */
	COUNTRY_CHPLAN_ENT2("RU", 0x35, 1, 0x1FB, 0), /* Russia(fac/gost), Kaliningrad */
	COUNTRY_CHPLAN_ENT2("RU", 0x35, 1, 0x1FB, 1), /* Russia(fac/gost), Kaliningrad v1 */
	COUNTRY_CHPLAN_ENT2("RU", 0x30, 1, 0x1FB, 2), /* Russia(fac/gost), Kaliningrad v2 */
	COUNTRY_CHPLAN_ENT2("SA", 0x02, 1, 0x1F1, 0), /* South Africa */
	COUNTRY_CHPLAN_ENT2("SU", 0x36, 1, 0x1FB, 0), /* Saudi Arabia */
	COUNTRY_CHPLAN_ENT2("TW", 0x37, 1, 0x1FF, 0), /* Taiwan */
	COUNTRY_CHPLAN_ENT2("UA", 0x38, 1, 0x1FB, 0), /* Ukraine */
	COUNTRY_CHPLAN_ENT2("US", 0x39, 1, 0x1FF, 0), /* United States of America (USA) */
};

