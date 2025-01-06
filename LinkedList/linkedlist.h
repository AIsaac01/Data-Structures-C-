// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// defines the Node struct to be used in the linked list
typedef struct {
    int value;          // node data
    // NOTE: the keyword 'struct' is typed out again here because the TYPE Node doesn't exist yet
    struct Node* next;  // pointer to next node
    struct Node* prev;  // pointer to previous node
} Node;

// defines the entire Linked List
typedef struct {
    Node* head;         // pointer to first node
    Node* tail;         // pointer to last node
    unsigned int len;   // total length of list
} LinkedList;

// inserts node to front of the list
void insert_front(LinkedList* list, int val);

// inserts node to end
void insert_end(LinkedList* list, int val);

// removes first node in list and returns its value, returns -1 if list is impty
// NOTE: returning -1 for empty list is NOT a good way to deal with that issue
int remove_front(LinkedList* list);

// removes the last node and returns its value
int remove_end(LinkedList* list);

// clears the entire list and frees memory of all nodes
// NOTE: YOU MUST FREE ALL NODES BEFORE FREEING LINKED LIST STRUCT
//       This can be done using the remove functions for each node,
//       or by calling clear_list
void clear_list(LinkedList* list);

#endif