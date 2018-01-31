/********************************************************************************
@Filename:syscalls.c
@Brief:FUnction Declaration for syscalls

This file declares functions for sytem calls. The functions and their respective 
systemcalls have been declared in the syscall_64.tbl in directory linux/arch/x86/
entry/syscalls

@Author:Ravi Dubey
@Date:1/28/2018
********************************************************************************/
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sort.h>
#include <linux/types.h>


int compare(const void* lhs, const void* rhs){

if ( *(const char*)lhs >  *(const char*)rhs )  return 1;
if ( *(const char*)lhs <  *(const char*)rhs ) return -1;
if ( *(const char*)lhs == *(const char*)rhs )  return 0;
}


SYSCALL_DEFINE3(mysyscall,char *,inbuf,size_t,len,char*,outbuf){

	printk(KERN_INFO "Entering mysyscall\n");
	char* buf = (char*) kmalloc(len,GFP_USER);
	if(buf == NULL) return -EFAULT;
	printk(KERN_INFO "Buffer Created\n");
	long copied = copy_from_user(buf,inbuf,len);
	if(copied < 0) return -EFAULT;	
	printk(KERN_INFO "Copy to kernel space from userspace succesful\n");
	
	sort(buf,len,sizeof(char),&compare,NULL);
	printk(KERN_INFO "Sorting of characters done\n");
	

	copied = copy_to_user(outbuf,buf,len) ;
	if(copied < 0) return -EFAULT;	
	printk(KERN_INFO "Copy from kernel space to userspace succesful\n");
	
	printk(KERN_INFO "Exiting mysyscall\n");
	return 0;
}



SYSCALL_DEFINE0(mysyscall1){

	printk(KERN_INFO "Entering mysyscall1\n");
	return 0;
	}

