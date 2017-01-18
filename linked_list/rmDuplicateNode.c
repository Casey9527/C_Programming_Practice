
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void push(node **head_ref, int val) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void removeDuplicate(node *head) {
    node *p = head;
    node *begin_node;
    node *tmp;
    while (p && p->next) {
        if (p->data == p->next->data) {   
            tmp = p->next;
            p->next = p->next->next;
            free(tmp);
        } else {
            p = p->next;
        }
    }
}

int main() {
    node *head = NULL;
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    
    printf("BEFORE: \n");
    printList(head);
    
    removeDuplicate(head);
    
    printf("AFTER: \n");
    printList(head);
    return 0;
}
