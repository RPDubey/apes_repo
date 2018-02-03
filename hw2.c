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
/*
struct timespec start, end;
uint32_t timediff_nsec;

// ret = syscall(SYS_mysyscall2);
//printf("System Call2 returned %ld\n",ret);


ret = syscall(SYS_mysyscall1);
printf("System Call1 returned %ld\n",ret);


char inbuf[50] = "Hello World"; //{'a','s','d'};
char outbuf[50] ;//= {'t','t','t'};

clock_gettime(CLOCK_MONOTONIC,&start);
ret = syscall(SYS_mysyscall,inbuf,strlen(inbuf),outbuf);
clock_gettime(CLOCK_MONOTONIC,&end);

timediff_nsec=(end.tv_sec-start.tv_sec)*1000000000 + (end.tv_nsec-start.tv_nsec);

printf("System Call1 returned %ld\n",ret);

printf("returned characters:%s\n",outbuf);

printf("TIme in systemcall in nanosecs: %d\n",timediff_nsec);
*/

node_info* node_info_inst1 = (node_info*)(malloc(sizeof(node_info)));
if (node_info_inst1 == NULL) {
printf("node instatntiation failed\n");
return 0;}

node_head* return_head;
return_head = insert_at_position(&node_info_inst1->this_node_head,10,0);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-1);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-2);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );



return_head = insert_at_position(&node_info_inst1->this_node_head,10,-3);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );

return_head = insert_at_position(&node_info_inst1->this_node_head,10,-4);
printf("Head returned:%p\n",return_head);
printf("size:%ld\n",size(return_head) );


/*

//printf("size:%ld\n",size(&node_info_inst1->this_node_head) );
return_head = insert_at_position(&node_info_inst1->this_node_head,10,0);
printf("Head returned:%p\n",return_head);

//printf("size:%ld\n",size(return_head ));
return_head = insert_at_position(&node_info_inst1->this_node_head,20,-1);
printf("Head returned:%p\n",return_head);


return_head = insert_at_position(&node_info_inst1->this_node_head,20,1);
printf("Head returned:%p\n",return_head);

return_head = insert_at_position(&node_info_inst1->this_node_head,20,2);
printf("Head returned:%p\n",return_head);

return_head = insert_at_position(&node_info_inst1->this_node_head,20,-2);
printf("Head returned:%p\n",return_head);

return_head = insert_at_position(&node_info_inst1->this_node_head,20,-1);
printf("Head returned:%p\n",return_head);

return_head = insert_at_position(&node_info_inst1->this_node_head,20,-1);
printf("Head returned:%p\n",return_head);

//return_head = insert_at_position(return_head,20,1);
//printf("size:%ld\n",size(return_head ));
//return_head = insert_at_position(&node_info_inst1->this_node_head,20,1);


printf("%p\n",&node_info_inst1->this_node_head);
//printf("%p\n",(&node_info_inst1->this_node_head)->prev);
printf("%p\n",return_head);
printf("%p\n",return_head->next);
printf("%p\n",return_head->next->next);
printf("%p\n",return_head->next->next->next);
//printf("%p\n",return_head->next->next->next->next);
*/



//printf("size:%ld\n",size( return_head ) );
//printf("size:%ld\n",size( &node_info_inst1->this_node_head ) );
//printf("size:%ld\n",size( (&node_info_inst1->this_node_head)->prev ) );
/*
insert_at_end(&node_info_inst1->this_node_head,30);

printf("size:%ld\n",size( &(node_info_inst1->this_node_head) ) );

insert_at_end(&node_info_inst1->this_node_head,30);

printf("size:%ld\n",size( &(node_info_inst1->this_node_head) ) );

insert_at_end(&node_info_inst1->this_node_head,30);

printf("size:%ld\n",size( &(node_info_inst1->this_node_head) ) );
printf("size:%ld\n",size( node_info_inst1->this_node_head.next ) );
printf("size:%ld\n",size( node_info_inst1->this_node_head.next->next ) );
printf("size:%ld\n",size( node_info_inst1->this_node_head.next->next->next ) );
printf("size:%ld\n",size( node_info_inst1->this_node_head.next->next->next->next ) );*/

//printf("node_info1_data:%d\n",node_info_inst1->data);
/*
//printf("node_info1_head-next:%p\n",&node_info_inst1->this_node_head.next);
insert_at_position(&node_info_inst1->this_node_head,30,-1);
insert_at_position(&node_info_inst1->this_node_head,40,2);
insert_at_position(&node_info_inst1->this_node_head,50,-2);
insert_at_position(&node_info_inst1->this_node_head,60,2);
insert_at_position(&node_info_inst1->this_node_head,70,2);

printf("size:%ld\n",size(&node_info_inst1->this_node_head) );
//node_head* return_head = delete_from_end(&node_info_inst1->this_node_head);

//return_head = delete_from_end(return_head);
//printf("size:%ld\n",size((&node_info_inst1->this_node_head)->next) );
//delete_from_end(return_head);
//printf("size:%ld\n",size((&node_info_inst1->this_node_head)->next->next) );
//free(node_info_inst1);
//printf("size:%ld\n",size((&node_info_inst1->this_node_head)->next->next) );
*/
return ret;

}
