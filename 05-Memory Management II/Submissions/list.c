#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

// Effect: allocate memory for a linked list (pointer to pointer to node).
// Output: a linked list.
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

// Input: 'list': a linked list.
//        'key': the key used to search the linked list.
// Output: a pointer to the data in the node that has the key 'key'.
Data *list_search(List list, Key key) {
    List_node *head = list->next;
    while(head!=NULL) {
        if (head -> key == key) return &(head -> data);
        head = head -> next;
    }
    return NULL;     
}

// Input: 'list': a linked list.
//        'key': the key of a node to add to a linked list.
//        'data': the data of a node to add to a linked list.
// Effect: Memory is allocated for a new node and its value is updated.    
void list_add(List list, Key key, Data data) {
    if (list_search(list, key)!=NULL) return;
    List_node *newNode = (List_node *) simu_malloc( sizeof(List_node) );
    newNode -> key = key;
    newNode -> data = data;
    newNode -> next = list -> next;
    list -> next = newNode;
}

// Input: 'list': a linked list.
//        'key': the key of a node to delete from the linked list.
// Effect: The link list has one less node. The deleted node has its memory retrieved.
void list_delete(List list, Key key) {
    if (list_search(list, key)==NULL) return;
    List_node *prev = list;
    List_node *curr = prev->next;
    while(curr->next!=NULL) {
        if (curr -> key == key) break;
        prev = curr;
        curr = curr -> next;
    }
    prev -> next = curr -> next;
    simu_free(curr);
}

// Input: 'list': a linked list
// Effect: Print to standard output the contents of all nodes in the list.
void list_print(List list) {
    List_node *curr = list->next;
    while (curr!=NULL) {
        print_list_node(curr);
        curr = curr->next;
    }
}

// Input: 'list': a linked list
// Effect: Dynamically de-allocate memory for the nodes in the linked list.
void list_free(List list) {
    if (list!=NULL) {
        list_free(list->next);
        simu_free(list);
    }
}
