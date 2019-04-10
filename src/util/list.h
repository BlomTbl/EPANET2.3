/*
 ******************************************************************************
 Project:      OWA EPANET
 Version:      2.2
 Module:       util/list.h
 Description:  Generic list
               https://gist.github.com/pseudomuto/6334796#file-list-h
               Accessed: April 9, 2019
 Authors:      David Muto, Modified by Michael E. Tryby
 Copyright:    see AUTHORS
 License:      see LICENSE
 Last Updated: 04/09/2019
 ******************************************************************************
*/

#ifndef LIST_H
#define LIST_H


#include <stdbool.h>

#if defined(__cplusplus)
extern "C" {
#endif

// a common function used to free malloc'd objects
typedef void(*freeFunction)(void *);
typedef bool(*listIterator)(void *);


typedef struct list_node_s {
    void *data;
    struct list_node_s *next;
} list_node_t;


typedef struct {
    int logicalLength;
    size_t elementSize;
    list_node_t *head;
    list_node_t *tail;
    freeFunction freeFn;
} list_t;


/**
@brief Initializes a linked list to store elements of elementSize and to call
freeFunction for each element when destroying a list.
*/
list_t *create_list(size_t elementSize, freeFunction freeFn);

/**
@brief Frees dynamically allocated nodes and optionally calls freeFunction
with each node’s data pointer.
*/
void delete_list(list_t *list);

/**
@brief Adds a node to the head of the list.
*/
void prepend_list(list_t *list, void *element);

/**
@brief Adds a node to the tail of the list.
*/
void append_list(list_t *list, void *element);

/**
@brief Returns the number of items in the list.
*/
int size_list(list_t *list);

/**
@brief Calls the supplied iterator function with the data element of each
node (iterates over the list).
*/
void for_each_list(list_t *list, listIterator iterator);

/**
@brief Returns the head of the list (optionally removing it at the same time).
*/
void *head_list(list_t *list, bool removeFromList);

/**
@brief Returns the tail of the list.
*/
void *tail_list(list_t *list);


#if defined(__cplusplus)
}
#endif

#endif /* LIST_H */
