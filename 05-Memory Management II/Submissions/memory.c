#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

// Input: 'size': the size of the total available memory for the user.
// Effect: Create a memory array of size 'size', storing unsigned char.
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

// Input: 'size': the size of a memory chunk requested by the user.
// Effect: allocate memory on bst and return a pointer to the requested memory on the array 'memory'.
void *simu_malloc(unsigned int size) {
    // find the index on memory that has enough size.
    Key key = *bstree_data_search(bst, size+4);
    // retrieve the total size of the chunk with key 'key'. 
    Data data = *bstree_search(bst, key);
    // store the user-requested memory size.
    memory[key] = size;
    // delete the free node stored in the tree.
    bstree_delete(bst, key);
    // insert a new node storing the new free node in the tree:
    Key newKey = key + size + 4;
    Data newData = data - size - 4;
    if (newData > 4) bstree_insert(bst, newKey, newData);
    // return a pointer to the user-requested memory on the memory array.
    return (void *) (&memory[key+4]);
}

// Input: 'ptr': a pointer to the chunk of memory used that the user wants to free.
// Effect: memory on bst is freed.
void simu_free(void *ptr) {
    // cast the pointer to the appropriate type.
    unsigned char * nptr = (unsigned char *) ptr;
    // insert a new node on the bst to store the new freed up node:
    Key key = (int) (nptr - &memory[0] - 4);
    Data data = memory[key] + 4;
    bstree_insert(bst, key, data);
}

// Effect: Traverse the tree and print all the nodes.
void mem_print(void) {
    bstree_traversal(bst);
}

// Effect: Free up memory used by the tree and the array.
void mem_free(void) {
    bstree_free(bst);
    free(memory);
}
