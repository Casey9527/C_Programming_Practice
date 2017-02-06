#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

void addFirst(node **head_ref, int val) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = *head_ref;
    
    if ((*head_ref))
        (*head_ref)->prev = new_node;
    *head_ref = new_node;
}

void printList(node *head) {
    node *p = head;
    while (p) {
        printf("<%d, ", p->data);
        if (p->next)
            printf("next: %d, ", p->next->data);
        if (p->prev)
            printf("prev: %d", p->prev->data);
        printf("> ");
        p = p->next;
    }
    printf("\n");
}

void reverse(node **head_ref) {
    node *p = *head_ref;
    node *tmp;
    while (p) {
        tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        if (!tmp)
            break;
        else
            p = tmp;
    }
    *head_ref = p;
}

int main() {
    node *head = NULL;
    addFirst(&head, 1);
    addFirst(&head, 2);
    addFirst(&head, 3);
    addFirst(&head, 4);
    printList(head);
    
    reverse(&head);
    printList(head);
    return 0;
}
