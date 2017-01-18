/*
    find the second node in the linked list
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

node *newNode(int val) {
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("failed to allocate new node!\n");
        getchar();
        exit(0);
    }
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

node* getSecondFromLast(node *head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    node *p = head;
    while (p->next != NULL && p->next->next != NULL)
        p = p->next;
    return p;
}

void printList(node *head) {
    node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printList(head);
    node *target = getSecondFromLast(head);
    if (target == NULL)
        printf("list is empty or only has one element\n");
    else
        printf("The last second is: %d\n", target->data);
    return 0;
}