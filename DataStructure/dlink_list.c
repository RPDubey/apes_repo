/********************************************************************************
@Filename:dlink_list.c
@Brief:This file implements double linked list functions

@Author:Ravi Dubey
@Date:1/30/2018
*******************************************************************************/
#include<stdio.h>

#include <stdint.h>
#include "dlink_list.h"


#define OFFSET(type,member)	((size_t)(&(((type*)0)->member)))

#define GET_LIST_CONTAINER(addr,type,member)  \
                          ( (type*) ( ((char*)addr) - OFFSET(type,member) ) )

/******************************************************************************/
node_head* destroy(node_head* head){

if(head == NULL) return NULL;
}

/******************************************************************************/
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
  printf("No head\n");
head->next = head;//next pointer of the "Head" node_head points to itself
head->prev = NULL;
node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
this_node_info->data = node_data;
}

//if head exists, create a new node
else{
    printf("head Exists\n");
node_info* new_node = (node_info*)malloc(sizeof(node_info));
if(new_node == NULL) return NULL;
node_head* list_head = head;//saving the head in another variable
//transverse from head to the last node. When we exit from while, head pointer
//contains the tail node_head
while( (head->next != NULL) && (head->next != head) ){ head = head->next;}
head->next = &(new_node->this_node_head);
(new_node->this_node_head).next = NULL;
(new_node->this_node_head).prev = head;
new_node->data = node_data;

head = list_head;
}

return head;

}

/********************************************************************************/
node_head* insert_at_position(node_head* base_node_head,uint32_t node_data,size_t index){
  //null head
  if(base_node_head == NULL) return NULL;

  node_head* list_head;

  //if no head exists, then the passed base pointer will be made the list Head if
  //index is o. If index is not 0 for no head case, then return null
 if(base_node_head->next == NULL){
  if(index != 0) return NULL;
  list_head = base_node_head;
  base_node_head->next = base_node_head;
  base_node_head->prev = NULL;
  node_info* this_node_info = GET_LIST_CONTAINER(base_node_head,
                                                  node_info,this_node_head);
  this_node_info->data = node_data;

  }
//in case only one node exists
  else if(base_node_head->next == base_node_head){
  if(index == 1) {
    list_head = base_node_head;
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    new_node->this_node_head.prev = base_node_head ;// this node is now the head
    new_node->this_node_head.next = NULL;
    base_node_head->next = &new_node->this_node_head;
    base_node_head->prev = NULL;
    new_node->data = node_data;
  }
  else if(index==-1){
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    list_head = &new_node->this_node_head;
    new_node->this_node_head.prev = NULL ;// this node is now the head
    new_node->this_node_head.next = base_node_head;
    base_node_head->next =NULL;
    base_node_head->prev = &new_node->this_node_head;
    new_node->data = node_data;
  }
  else{
    return NULL;
  }

  }


  //in case more than one node exists
  else{

    node_head* base_node_head_copy = base_node_head;
    base_node_head = base_node_head_copy;

    //locate and save the head pointer, and no. of nodes on the required side.
    while( (base_node_head->prev != NULL) ){ base_node_head = base_node_head->next;}
    list_head = base_node_head;

int i;
if(index == 0) { return NULL;}
else if(index>0){
  for(i=0;i<index;i++){
    base_node_head=base_node_head->next;
    if(base_node_head->next == NULL) break;
  }

  if( (base_node_head->next == NULL) && (i == index -1) ) {
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    base_node_head->next = &(new_node->this_node_head);
    (new_node->this_node_head).next = NULL;
    (new_node->this_node_head).prev = base_node_head;
    new_node->data = node_data;

  }
//  index is gretaer than length of dll from base node to tail
  else if( (base_node_head->next == NULL) && (i < index -1) ) {return NULL;}

  else if(base_node_head->next != NULL){
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    (new_node->this_node_head).next = base_node_head->next;
    base_node_head->next->prev = &new_node->this_node_head;
    base_node_head->next = &(new_node->this_node_head);
    (new_node->this_node_head).prev = base_node_head;
    new_node->data = node_data;


  }
}
else if(index <0){
  index = index * -1;
  for(i=0;i<index;i++){
    base_node_head=base_node_head->prev;
    if(base_node_head->prev == NULL) break;
  }

  if( (base_node_head->prev == NULL) && (i == index -1) ) {
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    base_node_head->prev = &(new_node->this_node_head);
    (new_node->this_node_head).next = base_node_head;
    (new_node->this_node_head).prev = NULL;
    new_node->data = node_data;
  }
  else if( (base_node_head->prev == NULL) && (i < index -1) ) {return NULL;}
  else if(base_node_head->prev != NULL){
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;
    (new_node->this_node_head).prev = base_node_head->prev;
    base_node_head->prev->next = &new_node->this_node_head;
    base_node_head->prev = &(new_node->this_node_head);
    (new_node->this_node_head).next = base_node_head;
    new_node->data = node_data;
  }
}

  }

  return list_head;

}

/********************************************************************************/
node_head* delete_from_begining(node_head* head){
if(head == NULL) return NULL;

//if only HEAD node is present
if(head->next == head){

node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
free(this_node_info);
return NULL;
}

//if 2 or more nodes present in linked list
else{

  head->next->prev = NULL;
  //if only 2 nodes then the remaining one would be the head and the only node.
  if(head->next->next == NULL) {
    head->next->next = head->next ;}
  //store pointer to next node for return before deleting the nodes
  node_head* new_head = head->next;
  free(GET_LIST_CONTAINER(head,node_info,this_node_head));
  return new_head;
  }

}


/******************************************************************************/
node_head* delete_from_end(node_head* head){

  if(head == NULL) return NULL;

  //if only HEAD node is present
  if(head->next == head){


  node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
  free(this_node_info);
  return NULL;
  }

  //if 2 or more nodes present in linked list
  else{
    node_head* list_head = head;//saving the head in another variable
    //if only 2 nodes then the remaining one would be the head and the only node.
    if(head->next->next == NULL) {


      free(GET_LIST_CONTAINER(head->next,node_info,this_node_head));
      head->next = head;}
      //If more than two nodes
    else{


      //transverse from head to the last node. When we exit from while, head pointer
      //contains the tail node_head
      while( (head->next != NULL) ){ head = head->next;}
      //make second last node points to null
      head->prev->next = NULL;
      free(GET_LIST_CONTAINER(head,node_info,this_node_head));
}
    return list_head;
    }


}

/********************************************************************************/
node_head* delete_from_position(node_head* base_node_head,size_t index){
  //null head
  if(base_node_head == NULL) return NULL;

  node_head* list_head;

    //in case only one node exists
  if(base_node_head->next == base_node_head){
  if(index == 0) {
    free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
  return NULL;//after deleting the only node, NO head remains
  }
  return NULL; //error condition of non zero index.

  }


  //in case more than one node exists
  else{

    node_head* base_node_head_copy = base_node_head;
    base_node_head = base_node_head_copy;

    //locate and save the head pointer, and no. of nodes on the required side.
    while( (base_node_head->prev != NULL) ){ base_node_head = base_node_head->next;}
    list_head = base_node_head;

  int i;
  if(index == 0) { return NULL;}
  else if(index>0){
  for(i=0;i<index;i++){
    base_node_head=base_node_head->next;
    if(base_node_head->next == NULL) break;
  }

  if( (base_node_head->next == NULL) && (i == index -1) ) {
  //delete last element
  if(base_node_head->prev->prev == NULL){//case of only two nodes
  base_node_head->prev->next = base_node_head->prev;}
  else base_node_head->prev->next = NULL;
  free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
  }
  //  index is gretaer than length of dll from base node to tail
  else if( (base_node_head->next == NULL) && (i < index -1) ) {return NULL;}

  else if(base_node_head->next != NULL){
base_node_head->prev->next = base_node_head->next;
base_node_head->next->prev = base_node_head->prev;
free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
}
  }
  else if(index <0){
  index = index * -1;
  for(i=0;i<index;i++){
    base_node_head=base_node_head->prev;
    if(base_node_head->prev == NULL) break;
  }

  if( (base_node_head->prev == NULL) && (i == index -1) ) {
//deleting from head
if(base_node_head->next->next == base_node_head->next){//case of only two nodes
base_node_head->next->next = base_node_head->next;}
else base_node_head->next->prev = NULL;
free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));

  }
  else if( (base_node_head->prev == NULL) && (i < index -1) ) {return NULL;}
  else if(base_node_head->prev != NULL){
    base_node_head->next->prev = base_node_head->prev;
    base_node_head->prev->next = base_node_head->next;
    free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));

      }
  }

  }

  return list_head;

}


/*******************************************************************************/
size_t size(node_head* head){
  if(head == NULL) return 0;
  if(head->next == head) return 1;

  size_t i =1;
  node_head* head_copy = head;

  while(head->next != NULL){
    i++;
    head=head->next;
  }
  head = head_copy;
  while(head->prev != NULL){
    i++;
    head=head->prev;
  }
return i;

}
