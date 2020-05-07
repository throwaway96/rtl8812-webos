/******************************************************************************
 *
 * Copyright(c) 2013 - 2017 Realtek Corporation.
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
 *****************************************************************************/

#ifndef LGE_PRIVATE
#error "You have defined CONFIG_CUSTOMIZED_COUNTRY_CHPLAN_MAP to use a customized map of your own instead of the default one"
#error "Before removing these error notifications, please make sure regulatory certification requirements of your target markets"
#else
static const struct country_chplan CUSTOMIZED_country_chplan_map[] = {
/* COUNTRY_CHPLAN_ENT2(_alpha2, _chplan, _bw, _en_11ac, _def_module_flags, _wififreq, _ver) */
	COUNTRY_CHPLAN_ENT2("AU", 0x22, 0x20, 1, 0x1FB, 17, 1), /* Australia */
	COUNTRY_CHPLAN_ENT2("BO", 0x23, 0x20, 1, 0x1F1, 26, 1), /* Bolivia */
	COUNTRY_CHPLAN_ENT2("BZ", 0x24, 0x20, 1, 0x000,  7, 1), /* Brazil, Peru, Philippines */
	COUNTRY_CHPLAN_ENT2("CH", 0x25, 0x20, 1, 0x1FB,  3, 1), /* Hong Kong, China */
	COUNTRY_CHPLAN_ENT2("CL", 0x26, 0x20, 1, 0x1F1, 18, 1), /* Chile, Paraguay, Uruguay */
	COUNTRY_CHPLAN_ENT2("CU", 0x3c, 0x00, 0, 0x1F1, 28, 1), /* Cuba */
	COUNTRY_CHPLAN_ENT2("DC", 0x27, 0x20, 1, 0x1FB, 30, 3), /* LGE Default CE */
	COUNTRY_CHPLAN_ENT2("DC", 0x28, 0x20, 1, 0x1FB, 31, 4), /* LGE Default v1 FCC */
	COUNTRY_CHPLAN_ENT2("EC", 0x29, 0x20, 1, 0x1F1,  5, 1), /* Ecuador */
	COUNTRY_CHPLAN_ENT2("EG", 0x31, 0x00, 0, 0x1F1, 21, 1), /* Egypt */
	COUNTRY_CHPLAN_ENT2("EU", 0x2a, 0x20, 1, 0x1FB, 12, 1), /* Germany */
	COUNTRY_CHPLAN_ENT2("HK", 0x2b, 0x20, 1, 0x1FB, 14, 1), /* Lebanon, Jordan, Srilanka */
	COUNTRY_CHPLAN_ENT2("HN", 0x19, 0x20, 1, 0x1F1, 24, 1), /* Honduras */
	COUNTRY_CHPLAN_ENT2("ID", 0x2c, 0x00, 0, 0x1F3, 20, 1), /* Indonesia */
	COUNTRY_CHPLAN_ENT2("IR", 0x2d, 0x20, 1, 0x1F3, 25, 1), /* Iran */
	COUNTRY_CHPLAN_ENT2("JP", 0x2e, 0x20, 1, 0x1FF, 11, 1), /* Japan- Telec */
	COUNTRY_CHPLAN_ENT2("KR", 0x3a, 0x20, 1, 0x1FB, 10, 1), /* South Korea */
	COUNTRY_CHPLAN_ENT2("KZ", 0x21, 0x20, 1, 0x100, 23, 1), /* Kazakhstan */
	COUNTRY_CHPLAN_ENT2("MM", 0x20, 0x20, 1, 0x000,  0, 1), /* Burma (Myanmar) */
	COUNTRY_CHPLAN_ENT2("MR", 0x31, 0x20, 1, 0x1F1, 13, 1), /* Morocco */
	COUNTRY_CHPLAN_ENT2("MX", 0x32, 0x20, 1, 0x1F1, 15, 1), /* Mexico */
	COUNTRY_CHPLAN_ENT2("MY", 0x25, 0x20, 1, 0x1F1,  6, 1), /* Malaysia */
	COUNTRY_CHPLAN_ENT2("NP", 0x33, 0x20, 1, 0x1FB, 27, 1), /* Nepal */
	COUNTRY_CHPLAN_ENT2("NZ", 0x30, 0x20, 1, 0x1FB, 16, 1), /* New Zealand */
	COUNTRY_CHPLAN_ENT2("PK", 0x34, 0x20, 1, 0x1F1,  1, 1), /* Pakistan */
	COUNTRY_CHPLAN_ENT2("RU", 0x3b, 0x20, 1, 0x1FB, 22, 1), /* Russia(fac/gost), Kaliningrad */
	COUNTRY_CHPLAN_ENT2("SA", 0x02, 0x20, 1, 0x1F1,  2, 1), /* South Africa */
	COUNTRY_CHPLAN_ENT2("SU", 0x36, 0x20, 1, 0x1FB,  4, 1), /* Saudi Arabia */
	COUNTRY_CHPLAN_ENT2("TW", 0x37, 0x20, 1, 0x1FF,  9, 1), /* Taiwan */
	COUNTRY_CHPLAN_ENT2("UA", 0x38, 0x20, 1, 0x1FB, 19, 1), /* Ukraine */
	COUNTRY_CHPLAN_ENT2("US", 0x39, 0x20, 1, 0x1FF,  8, 1), /* United States of America (USA) */
};
#endif /* LGE_PRIVATE */

