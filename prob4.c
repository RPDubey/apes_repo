/*******************************************************************************
@Filename:HW2.c
@Brief:src file for HW2

This file executes the implementations for HW2

@Author:Ravi Dubey
@Date:1/30/2018
*******************************************************************************/


#define _GNU_SOURCE
#include<unistd.h>
#include<sys/syscall.h>
#include<stdio.h>
#include<stdint.h>
#include<errno.h>

#include<time.h>
#include<string.h>

#include"./DataStructure/dlink_list.h"

#define SYS_mysyscall  (333)
#define SYS_mysyscall1 (334)
#define SYS_mysyscall2 (335)

#define len (256)

int main(){

//printing process id, user id, date& time for problem4

FILE *fp =fopen("prob4.log","w");
fprintf(fp,"PID:%d\n",getpid());
fprintf(fp,"UID:%d\n",getuid());

time_t t = time(NULL);
struct tm *tm =localtime(&t);
fprintf(fp,"%s\n",asctime(tm));

//systemcall from problem3

long ret;
struct timespec start, end;
uint32_t timediff_nsec;

//create a buffer of more than 256 char
int32_t inbuf[len];
int32_t outbuf[len];
srand(time(0));
fprintf(fp,"\t\tInput Buffer\n");
for(int i=0;i<len;i++){
inbuf[i] = rand()%100;
if(i%20 == 0) fprintf(fp,"\n");
fprintf(fp,"%d ",inbuf[i]);
}
clock_gettime(CLOCK_MONOTONIC,&start);
ret = syscall(SYS_mysyscall,inbuf,len,outbuf);
clock_gettime(CLOCK_MONOTONIC,&end);

if(ret != 0) {
fprintf(fp,"\nError: %s\n",strerror(errno));
return ret;}

timediff_nsec=(end.tv_sec-start.tv_sec)*1000000000 + (end.tv_nsec-start.tv_nsec);

fprintf(fp,"\n\n\t\tOutput Buffer\n");
for(int i=0;i<len;i++){
if(i%20 == 0) fprintf(fp,"\n");
fprintf(fp,"%d ",outbuf[i]);
}

fprintf(fp,"\n\nTIme spent in systemcall in nanosecs: %d\n",timediff_nsec);

fclose(fp);

return ret;

}
