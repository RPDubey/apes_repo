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

if ( *(const int32_t*)lhs >  *(const int32_t*)rhs )  return -1;
if ( *(const int32_t*)lhs <  *(const int32_t*)rhs ) return 1;
if ( *(const int32_t*)lhs == *(const int32_t*)rhs )  return 0;
}


SYSCALL_DEFINE3(mysyscall,int32_t *,inbuf,size_t,len,int32_t*,outbuf){

	printk(KERN_INFO "Entering mysyscall\n");
	printk(KERN_INFO "Buffer Size is:%ld bytes\n",len*sizeof(int32_t) );
	if(inbuf == NULL || outbuf == NULL || len < 1) return -EFAULT;
	
	int32_t* buf = (int32_t*) kmalloc(len*sizeof(int32_t),GFP_USER);
	if(buf == NULL) return -EFAULT;
	printk(KERN_INFO "Buffer Created\n");
	long copied = copy_from_user(buf,inbuf,len*sizeof(int32_t));
	if(copied < 0) return -EFAULT;	
	printk(KERN_INFO "Copy to kernel space from userspace succesful\n");
	
	printk(KERN_INFO "Starting Sort\n");
	sort(buf,len,sizeof(int32_t),&compare,NULL);
	printk(KERN_INFO "Sorting done\n");
	

	copied = copy_to_user(outbuf,buf,len*sizeof(int32_t)) ;
	if(copied < 0) return -EFAULT;	
	printk(KERN_INFO "Copy from kernel space to userspace succesful\n");
	
	printk(KERN_INFO "Exiting mysyscall\n");
	return 0;
}


/*Not used for this problem*/
SYSCALL_DEFINE0(mysyscall1){
	
	printk(KERN_INFO "Entering mysyscall1\n");
	return 0;
	}

