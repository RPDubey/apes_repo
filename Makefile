#********************************************************************************
#@Filename:Makefile
#@Brief:Makefile for src file
#@Author:Ravi Dubey
#@Date:1/30/2018
#********************************************************************************

hw2.elf:hw2.c dlink_list.o
	gcc -Werror -o hw2.elf hw2.c dlink_list.o

dlink_list.o:./DataStructure/dlink_list.c ./DataStructure/dlink_list.h
	gcc -Werror -c -o $@ $< 
