#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void) {
BStree bst;
unsigned int size = 0; // tree size
char keyName[1000]; // buffer for key->name
int keyID, data;
int signal = 0; // sentinel for I/O control

printf("\nPlease select a non-negative integer for the tree size: ");
scanf("%d", &size);
bst = bstree_ini(size);
printf("\nTo insert nodes to your tree, enter a triplet separated by white space.\n");
printf("The triplet is of the form: string int int. For instance: ali 3 21.\n");
printf("To terminate input, press Ctrl+D followed by new line. Receiving Input...: \n");

while(signal != EOF) {
    signal = scanf("%s %d %d", keyName, &keyID, &data);
    if (signal != EOF)
        bstree_insert(bst, key_construct(keyName, keyID), data);
}
printf("Input Terminated. Dispaying the contents of the tree in order...:\n\n");
bstree_traversal(bst);
printf("\nClearing the tree...\n");
bstree_free(bst);
printf("\nExiting...\n");
return 0;
}
