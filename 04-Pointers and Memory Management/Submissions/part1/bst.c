/* Ali Al-Musawi
 * Assignment 4
 */

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned int array of size+1 for member free_nodes
// set member size to ’size’;
// set entry free_nodes[i] to i
// set member top to 1;
// set member root to 0;
BStree bstree_ini(int size) {
    BStree bstree = (BStree) malloc(sizeof(BStree_struct));
    bstree->tree_nodes = (Node *) malloc((size + 1)*sizeof(Node));
    bstree->free_nodes = (unsigned int *) malloc((size + 1)*sizeof(unsigned int));
    bstree->size = size;
    for(int i = 0; i <= size; i++) bstree->free_nodes[i] = i;
    bstree->top = 1;
    bstree->root = 0;
    return bstree;
}

// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, Data data) {
    if (bst->top == 1) {
        bst->tree_nodes[1] = (Node) {.key = key, .data = data, .left = 0, .right = 0};
        bst->free_nodes[1] = -1; // This tells us that tree_nodes[1] stores a key
        bst->top++;
    }
    else if (bst->top <= bst->size) {
        int position = get(bst, 1, key);
        if (position != -1) {
            bst->tree_nodes[position].key = key;
            bst->tree_nodes[position].data = data;
            bst->tree_nodes[position].left = bst->tree_nodes[position].right = 0;
            bst->free_nodes[position] = -1; // This tells us that tree_nodes[position] stores a key
            bst->top++;
        }
    }
    else printf("Invalid entry: The tree is full.\n");
}

// Input: ’bst’: a binary search tree
// ’root’: the root of the current subtree
// ’key’: a pointer to Key
// Output: The index on bst.tree_nodes[] of where given key should be. 
// if ’key’ is already in ’bst’, return -1.
int get(BStree bst, int root, Key *key) {
    if (root == bst->top) return root;
    else {
        if (key_comp(key, bst->tree_nodes[root].key) < 0) {
            if ((bst->tree_nodes[root].left) == 0) { // the left child is null
                bst->tree_nodes[root].left = bst->top; // therefore the new key should be stored in the left child
                return get(bst, bst->top, key);
            }
            else return get(bst, bst->tree_nodes[root].left, key); // the left child isn't null, so go further.
        }
        else if (key_comp(key, bst->tree_nodes[root].key) > 0) {
            if ((bst->tree_nodes[root].right) == 0) {  // the right child is null
                bst->tree_nodes[root].right = bst->top; // therefore the new key should be stored in the right child
                return get(bst, bst->top, key);
            }
            else return get(bst, bst->tree_nodes[root].right, key); // the right child isn't null, so go further.
        }
        else return -1;
    }
}

// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    if (bst->top >= 1) inorder_print(bst, 1); // no point in traversing an empty tree
}


// Input: ’bst’: a binary search tree
// 'root': the root of the current subtree
// Effect: print all the nodes in bst using in order traversal
void inorder_print(BStree bst, int root) {
    if (root == 0) {;}
    else {
        inorder_print(bst, bst->tree_nodes[root].left);
        print_node(bst->tree_nodes[root]);
        inorder_print(bst, bst->tree_nodes[root].right);
    }
}


// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {
    keys_free(bst, 1); // recursive algorithm, frees keys post-order.
    free(bst->tree_nodes);
    free(bst->free_nodes);
    free(bst);  
}

// Input: 'bst': a binary search tree
// Effect: deallocating memory for every key stored in a BS Tree Node.
void keys_free(BStree bst, int root) {
    if (bst->free_nodes[root] != -1) {;} // root does not store anything
    else {
        keys_free(bst, bst->tree_nodes[root].left);
        keys_free(bst, bst->tree_nodes[root].right);
        free(bst->tree_nodes[root].key->name);
        free(bst->tree_nodes[root].key);
    }
}
