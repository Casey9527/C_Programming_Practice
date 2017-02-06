/*
    find the k th node from the end in the linked list
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

node* getNthFromLast(node *head, int k) {
    if (head == NULL || k <= 0)
        return (NULL);
    int i = 0;
    node *ptr = head;
    node *ptr_ref = head;
    
    while (i + 1 < k && ptr_ref->next != NULL) {
        ptr_ref = ptr_ref->next;
        i++;
    }
    if (i + 1 < k) {
        return (NULL);
    } else {
        while (ptr_ref->next != NULL) {
            ptr_ref = ptr_ref->next;
            ptr = ptr->next;
        }
    }
    return ptr;
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
    int k = 0;
    scanf("%d", &k);
    node *target = getNthFromLast(head, k);
    if (target == NULL)
        printf("k larger than size of list, or k <= 0, or list is empty\n");
    else
        printf("The %dth node from the end is: %d\n", k, target->data);
    return 0;
}