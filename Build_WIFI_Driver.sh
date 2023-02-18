export PLATFORM=WEBOS
export SDK_PATH=$PWD
export CROSS_COMPILE=$SDK_PATH/sysroots/x86_64-starfishsdk-linux/usr/bin/aarch64-starfish-linux/aarch64-starfish-linux-
export LINUX_SRC=$SDK_PATH/K8LP_kernel
export PKG_CONFIG_SYSROOT_DIR=$SDK_PATH/K8LP_kernel/kernel-source
export CHIP_NAME=k8
export ARCH=arm64
aarch=arm64

cd wifidrv-rtk
make clean
make -j4
