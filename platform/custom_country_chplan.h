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
	COUNTRY_CHPLAN_ENT("AU", 0x22, 1, 0x1FB), /* Australia */
	COUNTRY_CHPLAN_ENT("BO", 0x23, 1, 0x1F1), /* Bolivia */
	COUNTRY_CHPLAN_ENT("BZ", 0x24, 1, 0x000), /* Brazil, Peru, Philippines */
	COUNTRY_CHPLAN_ENT("CH", 0x25, 1, 0x1FB), /* Hong Kong, China */
	COUNTRY_CHPLAN_ENT("CL", 0x26, 1, 0x1F1), /* Chile, Paraguay, Uruguay */
	COUNTRY_CHPLAN_ENT("DC", 0x27, 1, 0x1FB), /* LGE Default CE */
	COUNTRY_CHPLAN_ENT("DC", 0x28, 1, 0x1FB), /* LGE Default v1 FCC */
	COUNTRY_CHPLAN_ENT("EC", 0x29, 1, 0x1F1), /* Ecuador */
	COUNTRY_CHPLAN_ENT("EG", 0x25, 0, 0x1F1), /* Egypt */
	COUNTRY_CHPLAN_ENT("EU", 0x2a, 1, 0x1FB), /* Germany */
	COUNTRY_CHPLAN_ENT("HK", 0x2b, 1, 0x1FB), /* Lebanon, Jordan, Srilanka */
	COUNTRY_CHPLAN_ENT("HN", 0x19, 1, 0x1F1), /* Honduras */
	COUNTRY_CHPLAN_ENT("ID", 0x2c, 0, 0x1F3), /* Indonesia */
	COUNTRY_CHPLAN_ENT("IR", 0x2d, 1, 0x1F3), /* Iran */
	COUNTRY_CHPLAN_ENT("JP", 0x2e, 1, 0x1FF), /* Japan- Telec */
	COUNTRY_CHPLAN_ENT("KR", 0x2f, 1, 0x1FB), /* South Korea */
	COUNTRY_CHPLAN_ENT("KR", 0x2f, 1, 0x1FB), /* South Korea v1 */
	COUNTRY_CHPLAN_ENT("KZ", 0x21, 1, 0x100), /* Kazakhstan */
	COUNTRY_CHPLAN_ENT("MM", 0x20, 1, 0x000), /* Burma (Myanmar) */
	COUNTRY_CHPLAN_ENT("MR", 0x31, 1, 0x1F1), /* Morocco */
	COUNTRY_CHPLAN_ENT("MX", 0x32, 1, 0x1F1), /* Mexico */
	COUNTRY_CHPLAN_ENT("MY", 0x25, 1, 0x1F1), /* Malaysia */
	COUNTRY_CHPLAN_ENT("NP", 0x33, 1, 0x1FB), /* Nepal */
	COUNTRY_CHPLAN_ENT("NZ", 0x30, 1, 0x1FB), /* New Zealand */
	COUNTRY_CHPLAN_ENT("PK", 0x34, 1, 0x1F1), /* Pakistan */
	COUNTRY_CHPLAN_ENT("RU", 0x35, 1, 0x1FB), /* Russia(fac/gost), Kaliningrad */
	COUNTRY_CHPLAN_ENT("RU", 0x35, 1, 0x1FB), /* Russia(fac/gost), Kaliningrad v1 */
	COUNTRY_CHPLAN_ENT("RU", 0x2f, 1, 0x1FB), /* Russia(fac/gost), Kaliningrad v2 */
	COUNTRY_CHPLAN_ENT("SA", 0x02, 1, 0x1F1), /* South Africa */
	COUNTRY_CHPLAN_ENT("SU", 0x36, 1, 0x1FB), /* Saudi Arabia */
	COUNTRY_CHPLAN_ENT("TW", 0x37, 1, 0x1FF), /* Taiwan */
	COUNTRY_CHPLAN_ENT("UA", 0x38, 1, 0x1FB), /* Ukraine */
	COUNTRY_CHPLAN_ENT("US", 0x39, 1, 0x1FF), /* United States of America (USA) */
};

