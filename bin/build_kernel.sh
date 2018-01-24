#!/bin/bash


LOGPATH=${MYPATH%%bin}/logs

BUILDPATH=~/git_kernel/linux

echo "Building Kernel" > $LOGPATH/kernel_build.log
echo "***********************************">$LOGPATH/kernel_build.log


cp /boot/config-$(uname-r) $BUILDPATH/.config

make defconfig

make modules_install

make install


echo "Building Kernel Complete" > $LOGPATH/kernel_build.log
echo "***********************************">$LOGPATH/kernel_build.log



