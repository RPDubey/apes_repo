/********************************************************************************
@Filename:dlink_list.c
@Brief:This file implements double linked list functions

@Author:Ravi Dubey
@Date:1/30/2018
********************************************************************************/
#include<stdio.h>

#include <stdint.h>
#include "dlink_list.h"


#define OFFSET(type,member)	((size_t)(&(((type*)0)->member)))	
#define GET_LIST_CONTAINER(addr,type,member)   ( (type*) ( ((char*)addr) - OFFSET(type,member) ) )

node_head* destroy(node_head* head){

if(head == NULL) return NULL;
}


node_head* insert_at_begining(node_head* head, uint32_t node_data ){

//null head
if(head == NULL) return NULL;

//if no head exists
else if(head->next == NULL){
head->next = head;//next pointer of the "Head" node_head points to itself 
head->prev = NULL;
node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
this_node_info->data = node_data;

}

//if head exists, create a new node

else{
node_info* new_node = (node_info*)malloc(sizeof(node_info));
if(new_node == NULL) return NULL;
new_node->this_node_head.prev = NULL ;// this node is now the head
new_node->this_node_head.next = head;
head->prev = &(new_node->this_node_head);
new_node->data = node_data; 
}

return head;

}
/********************************************************************************/
node_head* insert_at_end(node_head* head, uint32_t node_data ){

//null head
if(head == NULL) return NULL;

//if no head exists
else if(head->next == NULL){
head->next = head;//next pointer of the "Head" node_head points to itself 
head->prev = NULL;
node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
this_node_info->data = node_data;
}

//if head exists, create a new node
else{
node_info* new_node = (node_info*)malloc(sizeof(node_info));
if(new_node == NULL) return NULL;

node_head* list_head = head;//saving the head in another variable
//transverse from head to the last node. When we exit from while, head pointer 
//contains the tail node_head
while(head->next != NULL) head = head->next;

head->next = &(new_node->this_node_head);
(new_node->this_node_head).next = NULL;
(new_node->this_node_head).prev = head;
new_node->data = node_data;

head = list_head;
}

return head;

}

/********************************************************************************/
node_head* insert_at_position(node_head* head,uint32_t data,size_t index){}


/*
*@brief:Implements deleting nodes at the head of dll
*Delete a node at the beginning of the linked list 
*@param:the head node pointer
*@return:Pointer to the head of the linked 
*/
node_head* delete_from_begining(node_head* head){}

/*
*@brief:Implements deleting nodes at the tail of dll
*Delete a node at the end of the linked list 
*@param:the head node pointer
*@return:Pointer to the head of the linked
*/
node_head* delete_from_end(node_head* head){}

/*
*@brief:Implements deleting a node at the given position in linked list
*Delete a node at a given position of the linked list
*@param:a base node pointer and the index of where to add the data
*@return:Pointer to the head of the linked li
*/
node_head* delete_from_position(node_head* head,size_t index){}

/*
@brief:
Return the data from the linked list item at a given position
@param:A base node pointer and the index to where to get data from
@return:The data of the item pointer you 
*/
//peek_value(){}


/*
*@brief:Implements calculation of number of nodes in dll
*Determine the number of links in your linked list
*@param:a node pointer
*@return:size of linked list in node
*/
size_t size(node_head* head){}




