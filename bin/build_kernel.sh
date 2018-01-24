#!/bin/bash


LOGPATH=${MYPATH%%bin}/logs

BUILDPATH=~/git_kernel/linux

echo "Building Kernel" > $LOGPATH/kernel_build.log
echo "***********************************">>$LOGPATH/kernel_build.log


sudo cp /boot/config-$(uname -r) $BUILDPATH/.config >>$LOGPATH/kernel_build.log

sudo make >>$LOGPATH/kernel_build.log

sudo make modules_install >>$LOGPATH/kernel_build.log

sudo make install >>$LOGPATH/kernel_build.log


echo "*************** EOF ***************">>$LOGPATH/kernel_build.log



