#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
} List;

void addLast(List **list_ref, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->val = val;
    if ((*list_ref)->head == NULL) {
        (*list_ref)->head = new_node;
        (*list_ref)->tail = new_node;
    } else {
        (*list_ref)->tail->next = new_node;
        (*list_ref)->tail = new_node;
    }
}

void reverseLast2(List *list) {
    if (list == NULL || list->head == NULL || list->head->next == NULL)
        return;
    Node *dummy = (Node *) malloc(sizeof(Node));
    dummy->next = list->head;
    
    Node *p1 = dummy;               // dummy->1->2->nil
    Node *p2 = list->head->next;    // p1->dummy, p2->2
    Node *tmp;
    while (p2->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    tmp = p1->next;
    tmp->next = NULL;
    
    p1->next = p2;
    p2->next = tmp;
    list->tail = tmp;
    list->head = dummy->next;
}

void printList(List *list) {
    Node *p = list->head;
    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}

int main() {
    
    List *list = (List *) malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    addLast(&list, 5);

    addLast(&list, 4);
    
//    addLast(&list, 3);
//    addLast(&list, 2);
//    addLast(&list, 1);
    
    printList(list);
    
    reverseLast2(list);
    
    printList(list);
    
    free(list);
    return 0;
}