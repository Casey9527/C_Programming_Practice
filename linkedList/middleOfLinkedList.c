
/*
    find the middle of the linked list
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

node* getMiddle(node *head) {
    if (head == NULL || head->next == NULL)
        return head;
    node *walker = head;
    node *runner = head;
    while (runner->next != NULL && runner->next->next != NULL) {
        walker = walker->next;
        runner = runner->next->next;
    }
    return walker;
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
    printf("The middle is: %d\n", getMiddle(head)->data);
    return 0;
}