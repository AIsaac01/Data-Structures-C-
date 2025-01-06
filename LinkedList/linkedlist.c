#include <stdlib.h>
#include "linkedlist.h"

void insert_front(LinkedList* list, int val) {

    // initialize new node
    Node* new_node = (Node*) malloc( sizeof(Node) );
    new_node->value = val;

    // check if list is empty
    if (list->len == 0) {
        list->head = new_node;  // set head to new node
        list->tail = new_node;  // set tail to new node
        new_node->next = NULL;  // new node's 'next' does not point to anything, so it becomes NULL
    }
    // non-empty list
    else {
        Node* first = list->head;   // grab temporary reference to first node already in list
        list->head = new_node;      // set head to point to new node
        new_node->next = first;     // set new node's 'next' to point to previously first node
        first->prev = new_node;     // set the now second node's 'prev' to new first node
    }

    new_node->prev = NULL;  //set new node's 'prev' to NULL, since it is at the front of the list
    list->len++;            // increment list length
}

void insert_end(LinkedList* list, int val) {

    // initialize new node
    Node* new_node = (Node*) malloc( sizeof(Node) );
    new_node->value = val;

    // check if list is empty
    if (list->len == 0) {
        list->head = new_node;  // set head to new node
        list->tail = new_node;  // set tail to new node
        new_node->prev = NULL;  // new node's 'next' does not point to anything, so it becomes NULL
    }
    // non-empty list
    else {
        Node* last = list->tail;    // grab temporary reference to last node already in list
        list->tail = new_node;      // set tail to point to new node
        new_node->prev = last;      // set new node's 'prev' to point to previously last node
        last->next = new_node;      // set the now second to last node's 'next' to new last node
    }

    new_node->next = NULL;  //set new node's 'prev' to NULL, since it is at the front of the list
    list->len++;            // increment list length
}

int remove_front(LinkedList* list) {

    if (list->len == 0) {
        // Empty list
        return -1;
    }

    Node* temp = list->head;        // 'temp' is the node to be removed
    int popped_val = temp->value;   // keep value of first node so that it can be returned


    Node* second = temp->next;      // 'second' is the second node in the list, which is soon to be the first

    // second node is NULL if there is only one item in list
    // if list has more than one item, then set the second item's 'prev' to NULL
    // NOTE: if 'second' is NULL, then the operation 'second->prev' attempts to dereference a null
    // pointer, which results in a segmentation faul
    if (second != NULL) {
        second->prev = NULL;
    }
    // one item in list remaining
    else {
        list->tail = NULL;  // set tail to NULL, since the last and only item is being freed
    }

    list->head = second;            // set head to the 2nd node in list, skipping over the 1st node
    free(temp);                     // free first node

    list->len--;            // decrement list length
    return popped_val;      // return value of removed node
}

int remove_end(LinkedList* list) {

     if (list->len == 0) {
        // Empty list
        return -1;
    }

    Node* temp = list->tail;        // 'temp' is the node to be removed
    int popped_val = temp->value;   // keep value of first node so that it can be returned


    Node* second_to_last = temp->prev;      // 'second' is the second to last node in the list, which is soon to be the first

    // second to last node is NULL if there is only one item in list
    // if list has more than one item, then set the second item's 'prev' to NULL
    // NOTE: if 'second' is NULL, then the operation 'second->prev' attempts to dereference a null
    // pointer, which results in a segmentation faul
    if (second_to_last != NULL) {
        second_to_last->next = NULL;
    }
    // one item in list remaining
    else {
        list->head = NULL;  // set head to NULL, since the first and only item is being freed
    }

    list->tail = second_to_last;    // set tail to the 2nd to last node in list, skipping over the last node
    free(temp);                     // free last node

    list->len--;            // decrement list length
    return popped_val;      // return value of removed node
}

void clear_list(LinkedList* list) {

    Node* cur_node = list->head; // get pointer to list head

    // set head and tail to NULL
    list->head = NULL;
    list->tail = NULL;

    // iterate through list and free all nodes
    while ( cur_node != NULL ) {
        Node* to_be_freed = cur_node;   // set 'to_be_freed' to 'cur' so that it can be freed
        cur_node = cur_node->next;      // set 'cur' to next node
        free(to_be_freed);              // free 'prev'
    }

    list->len = 0;  // reset list length
}