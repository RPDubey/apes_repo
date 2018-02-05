/*******************************************************************************
@Filename:prob2.c
@Brief:src file for implementing prob2 of hw2

This file executes the implementations for prob2

@Author:Ravi Dubey
@Date:2/4/2018
*******************************************************************************/


#define _GNU_SOURCE
#include<stdio.h>
#include<stdint.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>

#define length	(100)

int main(){

//Print to standard out an interesting string using printf
printf("Covfefe!\n");

//Create a file, Permission to write, open the file
FILE* fp = fopen("prob2.log","w");

//Write a character to the file
fprintf(fp,"A");

//Close the file
fclose(fp);

//Open the file (in append mode)
fp=fopen("prob2.log","a");

//Dynamically allocate an array of memory
char* in_string = (char*)malloc(length);

//Read and input string from the command line and write to the string
printf("Enter String:");
gets(in_string);

//Write the string to the file
fputs(in_string,fp);

//Flush file output
fflush(fp);

//Close the file
fclose(fp);

//Open the file (for reading)
fp=fopen("prob2.log","r");

//Read a single character (getc)
char c= fgetc(fp);
printf("%c\n",c);

//Read a string of characters (gets)
char s[length]; 
fgets(s,length,fp);
printf("%s\n",s);

//Close the file
fclose(fp);

//Free the memo
free(in_string);

return 0;

}
