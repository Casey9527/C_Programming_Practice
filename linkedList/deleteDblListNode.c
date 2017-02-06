#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

void push(Node **head_ref, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

void printList(Node *node) {
    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void deleteNode(Node **head_ref, Node *del) {
    if (*head_ref == NULL || del == NULL)
        return;
    if (*head_ref == del)   /* if it is head node */
        *head_ref = del->next;
    if (del->next)          /* change next only if del is NOT the last node */
        del->next->prev = del->prev;
    if (del->prev)          /* change prev only if del is NOT the first node */
        del->prev->next = del->next;
    free(del);
    return;
}


int main() {
    Node *head = NULL;
    
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    
    printList(head);
    
    deleteNode(&head, head);
    deleteNode(&head, head->next);
    deleteNode(&head, head->next);
    
    printList(head);
    return 0;
}