#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"
static unsigned int size; // the size of the memory system
static int count = 1; // this is a safety check to prevent core dump/segmentation fault.
int signal = 0; // sentinel for I/O control
int main(void) {
    printf("Hello! Please enter the size (in bytes) of your memory system: ");
    do {
    scanf("%d", &size);
    if (size < 32) printf("Please ensure the size is at least 32 to store the linked list and one node.\n");
    }
    while (size < 32);
    mem_ini(size);
    List list = list_ini();
    int x; // a helpful integer for preventing core dump.
    if (size - 16*(size/16) >= 4) x = 0; 
    else x = 1; // for the program to function the user may not use the last 4 bytes.
    printf("To accomodate your choice of size (%d), you may enter a maximum of %d distinct integers.\n", size, (size/16) - 2 - x);
    printf("\nEnter integers separated by a new line.");
    printf("\nTo terminate input, press CTRL+D (*nix) or CTRL+Z (Windows):\n");
    Key key; // key to add to the linked list.
    Data data; // data to add to the linked list.
    int input; // the input read from a file or stdin.
    while(signal != EOF) {
        signal = scanf("%d", &input);
        if(signal != EOF) {
            if (list_search(list, input) != NULL) {
                key = input;
                data = (*list_search(list, key))+1;
                list_delete(list, key);
            }
            else {
                if (count >= (size/16) - 1 - x) break;
                key = input;
                data = 1;
                count++;
            }
            list_add(list, key, data);
        }
    }
    printf("\nIn the following print-out, key refers to the input integers,");
    printf("\nand data refers to the number of occurences of the input integers.\n");
    list_print(list);
    list_free(list);
    mem_free();
    return 0;
}

    
