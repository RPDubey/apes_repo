#!/bin/bash


LOGPATH=${MYPATH%%bin}/logs

BUILDPATH=/usr/src/linux-4.15

date &> $LOGPATH/kernel_build.log
echo "Building Kernel" >> $LOGPATH/kernel_build.log
echo "***********************************">>$LOGPATH/kernel_build.log

#sudo cp /boot/config-$(uname -r) $BUILDPATH/.config &>>$LOGPATH/kernel_build.log

#sudo make defconfig &>>$LOGPATH/kernel_build.log

sudo make &>>$LOGPATH/kernel_build.log

sudo make modules_install &>>$LOGPATH/kernel_build.log

sudo make install &>>$LOGPATH/kernel_build.log

sudo grub-mkconfig -o /boot/grub/grub.cfg

echo "*************** EOF ***************">>$LOGPATH/kernel_build.log



