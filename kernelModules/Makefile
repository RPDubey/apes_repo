#********************************************************************************
#@Filename:Makefile
#@Brief:Makefile for timer kernel Module
#@Author:Ravi Dubey
#@Date:2/3/2018
#********************************************************************************

obj-m += timer.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
