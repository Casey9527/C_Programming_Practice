// 9:01
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void addFront(Node **head_ref, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node *head) {
    Node *p = head;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void split(Node *head, Node **h1_ref, Node **h2_ref) {
    if (!head || !head->next)
        return;
    Node *runner = head;
    Node *walker = head;
    while (runner->next && runner->next->next) {
        walker = walker->next;
        runner = runner->next->next;
    }
    
    *h1_ref = head;
    *h2_ref = walker->next;
    walker->next = NULL;
}

void merge(Node ***head_ref_ref, Node *h1, Node *h2) {
    
    Node *dummy = (Node *) malloc(sizeof(Node));
    Node *p = dummy;

    while (h1 && h2) {
        if (h1->data <= h2->data) {
            p->next = h1;
            h1 = h1->next;
        } else {
            p->next = h2;
            h2 = h2->next;
        }
        p = p->next;
    }
    if (h1) {       /* the remaining part */
        p->next = h1;
    } else {
        p->next = h2;
    }
    *(*head_ref_ref) = dummy->next;
    free(dummy);
}

void mergeSort(Node **head_ref) {
    Node ***head_ref_ref = &head_ref;
    if (!(*head_ref) || !(*head_ref)->next)
        return;

    Node *h1 = NULL;
    Node *h2 = NULL;
    
    split(*head_ref, &h1, &h2);
    mergeSort(&h1);
    mergeSort(&h2);
    merge(head_ref_ref, h1, h2);
}

int main() {
    Node *head =  NULL;
    addFront(&head, 7);
    addFront(&head, 8);
    addFront(&head, 6);
    addFront(&head, 5);
    addFront(&head, 2);
    addFront(&head, 10);
    addFront(&head, 1);
    
    printList(head);
    mergeSort(&head);
    printList(head);
    return 0;
}

/*
// let merge() return "Node *" can avoid using triple pointer
Node* merge(Node *h1, Node *h2) {
    Node *newHead = (Node *) malloc(sizeof(Node));
    Node *p = newHead;
    Node *ret;
    while (h1 && h2) {
        if (h1->data <= h2->data) {
            p->next = h1;
            h1 = h1->next;
        } else {
            p->next = h2;
            h2 = h2->next;
        }
        p = p->next;
    }
    if (h1) {
        p->next = h1;
    } else {
        p->next = h2;
    }
    ret = newHead->next;
    free(newHead);
    return ret;
}

void mergeSort(Node **head_ref) {
    if (!(*head_ref) || !(*head_ref)->next)
        return;

    Node *h1 = NULL;
    Node *h2 = NULL;
    
    split(*head_ref, &h1, &h2);
    mergeSort(&h1);
    mergeSort(&h2);
    (*head_ref) = merge(h1, h2);
}

*/