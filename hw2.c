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

#include<time.h>
#include<string.h>

#include"./DataStructure/dlink_list.h"

#define SYS_mysyscall  (333)
#define SYS_mysyscall1 (334)
#define SYS_mysyscall2 (335)

int main(){

long ret;

node_info* node_info_inst1 = (node_info*)(malloc(sizeof(node_info)));
if (node_info_inst1 == NULL) {
printf("node instatntiation failed\n");
return 0;}

node_head* return_head;
return_head = insert_at_position(&node_info_inst1->this_node_head,10,0);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,1);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-1);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-1);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-1);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = destroy(return_head->next->next);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size((return_head) );

return ret;

}
