#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LinkedList/linkedlist.h"

int main(int argc, char** argv) {
	// Uncomment to debug input variables
	// for (int i = 0; i < argc; i++) {
	// 	printf("Argument %d : %s\n", i, argv[i]);
	// }

	// inialize linked list
	// NOTE: I am using calloc instead of malloc because calloc() returns a zeroed buffer,
	// 		 malloc() does not garuntee that.
	LinkedList* list = (LinkedList*) calloc(1, sizeof(LinkedList) );

	insert_front(list, 1);
	insert_front(list, 2);
	insert_front(list, 3);

	// head ->  3  ->  2  ->  1  ->  tail

	assert( remove_front(list) == 3 );
	assert( remove_front(list) == 2 );
	assert( remove_front(list) == 1 );

	assert( remove_end(list) == -1 ); // check for empty list

	printf("SUCCESS!\n");

	// ALWAYS, ALWAYS, ALWAYS free heap-allocated memory.
	// If a head-allocated variable, such as our linked list, holds pointers to other portions of heap-allocated
	// memory, then those portions must be freed.  Here, the function clear_list() does that for us.
	clear_list(list);
	free(list);
}