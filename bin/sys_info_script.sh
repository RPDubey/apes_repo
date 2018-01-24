#!/bin/bash

#MYPATH is enviorment variable path to bin. ${MYPATH%%bin} expands to one folder below bin
LOGPATH=${MYPATH%%bin}/logs/

#sending both stderr and stdout to log file by using "&"

echo "#################################################" >$LOGPATH/system_info.log
echo "System Specifications" &>>$LOGPATH/system_info.log
echo "#################################################" &>>$LOGPATH/system_info.log

#User Info
echo "User Info" &>>$LOGPATH/system_info.log
id -un &>>$LOGPATH/system_info.log
id &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log

#Operating System Info
echo "OS Info" >>$LOGPATH/system_info.log
uname --all &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log

#OS Distribution
echo "OS Distribution" >>$LOGPATH/system_info.log
lsb_release -a &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log


#OS Version
echo "OS Version" >>$LOGPATH/system_info.log
cat /etc/issue.net &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log


#Kernel Version
#User WHo built kernel and location
#Version of GCC compiler
#Type of Kernel
#Kernel Build Time
echo "Kernel Info" >>$LOGPATH/system_info.log
cat /proc/version &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log

	
#System Architecture Info
echo "System Architecture:" >>$LOGPATH/system_info.log
lscpu &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log

#Information on File System Memory
echo "Information on File system and Memory:" >>$LOGPATH/system_info.log
df -h &>>$LOGPATH/system_info.log
echo "*************************************************" >>$LOGPATH/system_info.log

echo "####################  EOF  ######################" >>$LOGPATH/system_info.log

