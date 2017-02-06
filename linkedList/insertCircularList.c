/*
    insert a new value in a sorted Circular Linked List (CLL)
    can be used to solve "Keep a list of integers sorted while new inputs are being entered."
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void sortedInsert(struct node **head_ref, struct node *new_node) {
    
    struct node *current = *head_ref;
    
    // case 1: if head is empty
    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    }
    
    // case 2: before the head
    else if (current->data >= new_node->data) {
        while (current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    
    // case 3: any position between the head to the last
    else {
        while (current->next != *head_ref &&
               current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current ->next;
        current->next = new_node;
    }
}


void printList(struct node *start) {
    struct node *tmp;
    if (start != NULL) {
        tmp = start;
        printf("\n");
        do {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        } while (tmp != start);
        printf("\n");
    }
}

int main() {
    int arr[] = {12, 56, 2, 11, 1, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;
    
    /* start with empty linked list */
    struct node *start = NULL;
    struct node *tmp;
    
    for (i = 0; i < size; ++i) {
        tmp = (struct node *) malloc(sizeof(struct node));
        tmp->data = arr[i];
        sortedInsert(&start, tmp);
    }
    printList(start);
    return 0;
}