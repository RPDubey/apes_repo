/********************************************************************************
@Filename:dlink_list.h
@Brief: An abstraction for double linked list operations implemented in 
dlink_list.c

This file declares double linked list(Henceforth dll) functions and external
structures for dlink_list.h

@Author:Ravi Dubey
@Date:1/30/2018
********************************************************************************/

#ifndef DLINK_LIST_H
#define DLINK_LIST_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>



/*
*@brief:structure to hold link list nodes
*This structure holds the pointer to the previous and next nodes. It dosent hold 
data or pointer to data.
*/
typedef struct node_head{
	struct node_head* prev;
	struct node_head* next;
}node_head;

/*
*@brief:structure to hold node info
*This structure is where the data is stored
*/
typedef struct {
	uint32_t data;
	struct node_head this_node_head;
}node_info;

/*
*@brief:Implements destroying all nodes of doulbe linked list(dll) 
*Destroys all nodes in the linked list by freeing the memory
*@param: a linked list data structure pointer
*@return: pointer to the head of the linked list
*/
node_head* destroy(node_head*);


/*
*@brief:Implements adding node at the head of dll
*Add a node to the beginning of the linked list. Should add head node if it
*does not exist.
*@param: the head node pointer and the data to add
*@return:Pointer to the head of the linked 
*/
node_head* insert_at_begining(node_head*,uint32_t);


/*
*@brief:Implements adding node at the end of dll
*Add a node to the end of the linked list. Should add head node if it does not
*exist.
*@param: the head node pointer and the data to add
*@return: Pointer to the head of the linked
*/
node_head* insert_at_end(node_head*, uint32_t );


/*
*@brief:Implements adding node at a given position in dll
*Add a node to a given position of the linked list.

*@param:a base node pointer, data to add, and the index of where to add the data
*@return:Pointer to the head of the linked
*/
node_head* insert_at_position(node_head*,uint32_t,size_t);


/*
*@brief:Implements deleting nodes at the head of dll
*Delete a node at the beginning of the linked list 
*@param:the head node pointer
*@return:Pointer to the head of the linked 
*/
node_head* delete_from_begining(node_head*);

/*
*@brief:Implements deleting nodes at the tail of dll
*Delete a node at the end of the linked list 
*@param:the head node pointer
*@return:Pointer to the head of the linked
*/
node_head* delete_from_end(node_head*);

/*
*@brief:Implements deleting a node at the given position in linked list
*Delete a node at a given position of the linked list
*@param:a base node pointer and the index of where to add the data
*@return:Pointer to the head of the linked li
*/
node_head* delete_from_position(node_head*,size_t);

/*
@brief:
Return the data from the linked list item at a given position
@param:A base node pointer and the index to where to get data from
@return:The data of the item pointer you 
*/
//peek_value();


/*
*@brief:Implements calculation of number of nodes in dll
*Determine the number of links in your linked list
*@param:a node pointer
*@return:size of linked list in node
*/
size_t size(node_head*);


#endif


