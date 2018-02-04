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
node_head* destroy(node_head* head) {

    if(head == NULL) return NULL;
//cae of memory alloted but node uninitialized
    if(head->prev == NULL && head->next == NULL) {
        free(GET_LIST_CONTAINER(head,node_info,this_node_head));
        return NULL;
    }
    node_head* list_head = return_head(head);
    size_t length = size(list_head);
    for(int i =0; i<length; i++ ) {
        list_head = delete_from_end(list_head);
    }

    return list_head;
}


/******************************************************************************/
node_head* insert_at_begining(node_head* head, uint32_t node_data ) {

//null head
    if(head == NULL) return NULL;

//if no head exists
    else if(head->next == NULL) {
        head->next = head;//next pointer of the "Head" node_head points to itself
        head->prev = NULL;
        node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
        this_node_info->data = node_data;
    }
//if head exists, create a new node
    else {

        node_info* new_node = (node_info*)malloc(sizeof(node_info));
        if(new_node == NULL) return NULL;

        new_node->this_node_head.prev = NULL ;// this node is now the head
        new_node->this_node_head.next = head;
        head->prev = &(new_node->this_node_head);
        new_node->data = node_data;
        head = &new_node->this_node_head;//new head for list

//case when added node is second element
        if(head->next->next == head->next) {
            head->next->next = NULL;
        }

    }

    return head;
}
/********************************************************************************/
node_head* insert_at_end(node_head* head, uint32_t node_data ) {

//null head
    if(head == NULL) return NULL;

//if no head exists
    else if(head->next == NULL) {

        head->next = head;//next pointer of the "Head" node_head points to itself
        head->prev = NULL;
        node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
        this_node_info->data = node_data;
    }

//if head exists, create a new node
    else {

        node_info* new_node = (node_info*)malloc(sizeof(node_info));
        if(new_node == NULL) return NULL;
        node_head* list_head = head;//saving the head in another variable
//transverse from head to the last node. When we exit from while, head pointer
//contains the tail node_head
        while( (head->next != NULL) && (head->next != head) ) {
            head = head->next;
        }
        head->next = &(new_node->this_node_head);
        (new_node->this_node_head).next = NULL;
        (new_node->this_node_head).prev = head;
        new_node->data = node_data;

        head = list_head;
    }

    return head;

}
/*******************************************************************************/
node_head* return_head(node_head* node) {

    if(node == NULL) return NULL;
    if( (node->next == NULL) && (node->prev == NULL) ) return NULL;

    size_t list_length = size(node);

    if(list_length == 1) return node;

    if(list_length == 2) {

        if( (node->prev == NULL) &&(node->next != NULL) ) return node;
        if( (node->next == NULL) &&(node->prev != NULL) ) return node->prev;
        return NULL;
    }
    if(list_length >  2) {
        while(node->prev != NULL) node = node->prev;
        return node;
    }
    else return NULL;
}
/*******************************************************************************/
node_head* insert_between(node_head* node1,node_head* node2, uint32_t node_data) {

    if(node1 == NULL || node2 == NULL) return NULL;
    node_info* new_node = (node_info*)malloc(sizeof(node_info));
    if(new_node == NULL) return NULL;

    node1->next = &new_node->this_node_head;
    node2->prev = &new_node->this_node_head;
    (new_node->this_node_head).prev = node1;
    (new_node->this_node_head).next = node2;
    new_node->data = node_data;

    return return_head(node1);

}

/*******************************************************************************/
size_t distance_head(node_head* node) {
    if(node == NULL) return -1;
    if( (node->next == NULL) && (node->prev == NULL) ) return -1;
    if( (node->next == node) && (node->prev == NULL) ) return  0;
    if( (node->prev == NULL) ) {
        if(node->next->next == NULL) return 0;
    }

    if( (node->next == NULL) ) {
        if(node->prev->prev == NULL) return 1;
    }

    size_t i = 0;

    while(node->prev != NULL) {
        i++;
        node=node->prev;
    }
    return i;
}

/*******************************************************************************/
size_t distance_tail(node_head* node) {
    if(node == NULL) return -1;
    if( (node->next == NULL) && (node->prev == NULL) ) return -1;
    if( (node->next == node) && (node->prev == NULL) ) return  0;
    if( (node->prev == NULL) ) {
        if(node->next->next == NULL) return 1;
    }

    if( (node->next == NULL) ) {
        if(node->prev->prev == NULL) return 0;
    }

    size_t i = 0;

    while(node->next != NULL) {
        i++;
        node=node->next;
    }
    return i;
}



/*******************************************************************************/
node_head* insert_at_position(node_head* base_node_head,\
                              uint32_t node_data,\
                              int index) {

    if(base_node_head == NULL) return NULL;

//if no head exists, then the passed base pointer will be made the list Head if
//index is o. If index is not 0 for no head case, then return null
    if( (base_node_head->next == NULL) && (base_node_head->prev == NULL) ) {
        if(index != 0) return NULL;
        return insert_at_begining(base_node_head, node_data);
    }

    size_t list_length = size(base_node_head);

    if(list_length == 1) {
        if(index == 1) return insert_at_end(base_node_head,node_data);
        if(index == -1) return insert_at_begining(base_node_head,node_data);
        return NULL;
    }

    if(list_length == 2) {
        if( (base_node_head->prev == NULL) && (base_node_head->next != NULL) ) {
            if(index == -1) return insert_at_begining(base_node_head,node_data);
            if(index ==  1) return insert_between(base_node_head,base_node_head->next,node_data);
            if(index ==  2) return insert_at_end(base_node_head,node_data);
            return NULL;
        }
        else if( (base_node_head->next == NULL) && (base_node_head->prev != NULL) ) {


            if(index == -1) return insert_between(base_node_head->prev,base_node_head,node_data);
            if(index ==  1) return insert_at_end(base_node_head->prev,node_data);
            if(index == -2) return insert_at_begining(base_node_head->prev,node_data);
            else return NULL;
        }
        else return NULL;
    }

    if(list_length > 2) {
        if(index == 0) return NULL;
        if(index > 0) {
            size_t tail_length = distance_tail(base_node_head);
            if( (index > tail_length+1) || (tail_length < 0) ) return NULL;
            if( index == tail_length + 1 ) return insert_at_end(return_head(base_node_head),node_data);
            for(int i = 0; i< index-1; i++) base_node_head = base_node_head->next;
            return insert_between(base_node_head,base_node_head->next,node_data);
        }
        if(index < 0) {

            index *= -1;
            size_t head_length = distance_head(base_node_head);
            if( (index > head_length+1) || (head_length < 0) ) return NULL;
            if( index == head_length + 1 ) return insert_at_begining(return_head(base_node_head),node_data);

            for(int i = 0; i< index-1; i++) {
                base_node_head = base_node_head->prev;
            }


            return insert_between(base_node_head->prev,base_node_head,node_data);


        }
    }

    return NULL;

}

/********************************************************************************/
node_head* delete_from_begining(node_head* head) {
    if(head == NULL) return NULL;

//if only HEAD node is present
    if(head->next == head) {

        node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
        free(this_node_info);
        return NULL;
    }

//if 2 or more nodes present in linked list
    else {

        head->next->prev = NULL;
        //if only 2 nodes then the remaining one would be the head and the only node.
        if(head->next->next == NULL) {
            head->next->next = head->next ;
        }
        //store pointer to next node for return before deleting the nodes
        node_head* new_head = head->next;
        free(GET_LIST_CONTAINER(head,node_info,this_node_head));
        return new_head;
    }

}


/******************************************************************************/
node_head* delete_from_end(node_head* head) {

    if(head == NULL) return NULL;

    //if only HEAD node is present
    if(head->next == head) {


        node_info* this_node_info = GET_LIST_CONTAINER(head,node_info,this_node_head);
        free(this_node_info);
        return NULL;
    }

    //if 2 or more nodes present in linked list
    else {
        node_head* list_head = head;//saving the head in another variable
        //if only 2 nodes then the remaining one would be the head and the only node.
        if(head->next->next == NULL) {


            free(GET_LIST_CONTAINER(head->next,node_info,this_node_head));
            head->next = head;
        }
        //If more than two nodes
        else {


            //transverse from head to the last node. When we exit from while, head pointer
            //contains the tail node_head
            while( (head->next != NULL) ) {
                head = head->next;
            }
            //make second last node points to null
            head->prev->next = NULL;
            free(GET_LIST_CONTAINER(head,node_info,this_node_head));
        }
        return list_head;
    }


}

/********************************************************************************/
node_head* delete_from_position(node_head* base_node_head,int index) {
    //null head
    if(base_node_head == NULL) return NULL;
    //memory alloted for node but uninitialized
    if((base_node_head->next == NULL) && (base_node_head->prev == NULL) ) {
        if(index != 0) return NULL;
        free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
        return NULL;
    }
    size_t list_length = size(base_node_head);

    if(list_length == 1) {
        if(index != 0) return NULL;
        free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
        return NULL;
    }
    if(list_length == 2) {

        if( (base_node_head->prev == NULL) && (base_node_head->next != NULL) ) {
            if(index ==  0) return delete_from_begining(base_node_head);
            if(index ==  1) return delete_from_end(base_node_head);
            else return NULL;
        }
        else if( (base_node_head->next == NULL) && (base_node_head->prev != NULL) ) {
            if(index == 0) return delete_from_end(base_node_head->prev);
            if(index == -1) return delete_from_begining(base_node_head->prev);
            else return NULL;
        }
        else return NULL;
    }


    if(list_length > 2) {
        node_head* list_head = return_head(base_node_head);
        if(index == 0) {
            base_node_head->prev->next = base_node_head->next;
            base_node_head->next->prev = base_node_head->prev;
            free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
            return list_head;
        }
        if(index > 0) {
            size_t tail_length = distance_tail(base_node_head);
            if( (index > tail_length) || (tail_length < 0) ) return NULL;
            if( index == tail_length) return delete_from_end(list_head);
            for(int i = 0; i< index; i++) base_node_head = base_node_head->next;
            base_node_head->prev->next = base_node_head->next;
            base_node_head->next->prev = base_node_head->prev;
            free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
            return list_head;
        }
        if(index < 0) {
            index *= -1;
            size_t head_length = distance_head(base_node_head);
            if( (index > head_length) || (head_length < 0) ) return NULL;
            if( index == head_length ) return delete_from_begining(list_head);
            for(int i = 0; i< index; i++) {
                base_node_head = base_node_head->prev;
            }
            base_node_head->prev->next = base_node_head->next;
            base_node_head->next->prev = base_node_head->prev;
            free(GET_LIST_CONTAINER(base_node_head,node_info,this_node_head));
            return list_head;
        }
    }

}

/*******************************************************************************/
size_t size(node_head* node) {

    if(node == NULL) return -1;

    if( (node->next == NULL) && (node->prev == NULL) ) return 0;

    if( node->next == node ) {
        return 1;
    }

    if( (node->prev == NULL) ) {
        if(node->next->next == NULL) return 2;
    }

    if( (node->next == NULL) ) {
        if(node->prev->prev == NULL) return 2;
    }

    size_t i = 0;

    node_head* node_copy = node;

    while(node->next != NULL) {
        i++;
        if(i>6) break;
        node=node->next;
    }

    node = node_copy;
    while(node->prev != NULL) {
        i++;
        node=node->prev;
    }
    return i+1 ;

}
