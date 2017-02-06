/*
    implement a double linked list using a single linked list
    you are given only data and one pointer in
    struct node {
        int data;
        struct node *ptr;
    };
    you should be able to traverse in both directions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct node {
  int data;
  struct node *npx;
};

struct node* XOR(struct node *a, struct node *b) {
    return (struct node *)(uintptr_t)((uintptr_t)(a) ^ (uintptr_t)(b));
}

void insert(struct node **head_ref, int val) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = val;
    
    new_node->npx = XOR(*head_ref, NULL);
    
    if (*head_ref != NULL) {
        struct node *next = XOR((*head_ref)->npx, NULL);
        (*head_ref)->npx = XOR(next, new_node);
    } 
    // change head
    *head_ref = new_node;
}

void printList(struct node *head) {
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
    printf("Traversing the XOR linked list...\n");
    while (curr != NULL) {
        printf("%d ", curr->data);
        next = XOR(curr->npx, prev);
        // update
        prev = curr;
        curr = next;
    }
    printf("\n");
}


int main () {
    /* Create following Doubly Linked List
       head-->40<-->30<-->20<-->10   */
    struct node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
 
    // print the created list
    printList (head);
 
    return (0);
}