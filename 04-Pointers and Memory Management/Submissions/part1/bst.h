#include "data.h"
typedef struct {
    Node *tree_nodes;
    unsigned int *free_nodes;
    int size;
    int top;
    int root;
    } BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, Data data);
int get(BStree bst, int root, Key *key);
void bstree_traversal(BStree bst);
void inorder_print(BStree bst, int root);
void bstree_free(BStree bst);
void keys_free(BStree bst, int root);