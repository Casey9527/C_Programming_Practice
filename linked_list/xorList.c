
/*
    implement a xor style double-linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Node {
    int data;
    struct Node* npx;
} Node;

Node* XOR(Node* a, Node* b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

Node* insert_before(Node *head, int data)
{
    Node* node = (Node *) malloc(sizeof(Node));
    node->data = data;
    
    node->npx = XOR(NULL, head);
    if (head) {
        head->npx = XOR(head->npx, node);
    }
    
    return node;    // node becomes new head
}

void printList(Node* head)
{
    Node* prev = NULL;
    Node* curr = head;
    Node* next;
    
    while (curr != NULL) {
        printf("%d ", curr->data);
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    printf("\n");
}


int main()
{
    Node *head = NULL;
    head = insert_before(head, 10);
    head = insert_before(head, 20);
    head = insert_before(head, 30);
    head = insert_before(head, 40);
    head = insert_before(head, 50);
    head = insert_before(head, 60);
    
    printList(head);
    return 0;
}




