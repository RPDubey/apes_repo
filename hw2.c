/********************************************************************************
@Filename:HW2.c
@Brief:src file for HW2

This file executes the implementations for HW2

@Author:Ravi Dubey
@Date:1/30/2018
********************************************************************************/


#define _GNU_SOURCE
#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<stdint.h>

#include<time.h>
#include<string.h>

#define SYS_mysyscall  333
#define SYS_mysyscall1 334
#define SYS_mysyscall2 335

int main(){

long ret;
struct timespec start, end;
uint32_t timediff_nsec;

// ret = syscall(SYS_mysyscall2);
//printf("System Call2 returned %ld\n",ret);

/*
ret = syscall(SYS_mysyscall1);
printf("System Call1 returned %ld\n",ret);

*/
char inbuf[50] = "Hello World"; //{'a','s','d'};
char outbuf[50] ;//= {'t','t','t'};

clock_gettime(CLOCK_MONOTONIC,&start);
ret = syscall(SYS_mysyscall,inbuf,strlen(inbuf),outbuf);
clock_gettime(CLOCK_MONOTONIC,&end);

timediff_nsec = (end.tv_sec - start.tv_sec)*1000000000 + (end.tv_nsec - start.tv_nsec);

printf("System Call1 returned %ld\n",ret);

printf("returned characters:%s\n",outbuf);

printf("TIme in systemcall in nanosecs: %d\n",timediff_nsec);


return ret;

}
