#========================================
# How to compile the wifidrv-rtk
#========================================

#----------------------------------------
@@. The order to compile codes
#----------------------------------------
1) Download toolchain, starfish-sdk-x86_64-aarch64-toolchain-7.0.0.sh, on your working directory.
2) Download rtk_8812_wifi_driver.tar.gz on your working directory.
-----------------------------------------
3) tar xzf rtk_8812_wifi_driver.tar.gz
4) cp starfish-sdk-x86_64-aarch64-toolchain-7.0.0.sh ./rtk_8812_wifi_driver
5) cd rtk_8812_wifi_driver
6) ./starfish-sdk-x86_64-aarch64-toolchain-7.0.0.sh
- Enter target directory for SDK (default: /opt/starfish-sdk-x86_64/5.0.0-20191125): .
- You are about to install the SDK to {"DIRECTORY"}. Proceed[Y/n]? y
7) . {"DIRECTORY"}/environment-setup-ca9v1-starfishmllib32-linux-gnueabi
8) ./Build_WIFI_Driver.sh
9) Confirm 8812bu.ko file in wifidrv-rtk
