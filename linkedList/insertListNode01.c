
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

void addFront(Node **head_ref, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

Node* newNode(int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

/* insert a node to a sorted linked list */
void sortedInsert(Node **head_ref, Node *new_node) {
    Node *dummy = (Node *) malloc(sizeof(Node));
    dummy->data = 0;
    dummy->next = *head_ref;
    Node *p;
    p = dummy;
    
    while (p->next) {
        if (p->next->data >= new_node->data) {
            new_node->next = p->next;
            p->next = new_node;
            break;
        }
        p = p->next;
    }
    if (!p->next && p->data < new_node->data)
        p->next = new_node;
    *head_ref = dummy->next;
}

void printList(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int k = 0;
    Node *head =  NULL;
    addFront(&head, 5);
    addFront(&head, 5);
    addFront(&head, 4);
    addFront(&head, 3);
    addFront(&head, 2);
    addFront(&head, 1);
    addFront(&head, 1);
    
    printList(head);
    scanf("%d", &k);
    Node *new_node = newNode(k);
    sortedInsert(&head, new_node);

    printList(head);
    return 0;
}
