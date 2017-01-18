#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct circularList {
    struct node *head;
    struct node *tail;
} cirList;

/* print out a circular list */
void printList(cirList *list) {
    node *p = list->head;
    while (p && p != list->tail) {
        printf("%d ", p->data);
        p = p->next;
    }
    if (list->tail)
        printf("%d ", list->tail->data);
    
    printf("\n");
}


/* insert into sorted list */
void sortedInsert(cirList *list, int val);
/* delete the first node */
void deleteFirst(cirList *list);
/* return the node with minimum value */
void printMin(cirList *list);

/* create a circular list */
cirList* createList() {
    cirList *new_list = (cirList *) malloc(sizeof(cirList));
    new_list->head = NULL;
    new_list->tail = NULL;
    return new_list;
}

/* insert a node before head */
void insertFirst(cirList *list, int val) {
    // new node
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    if (list->tail == NULL) {
        list->tail = new_node;
    }
    new_node->next = list->head;
    list->head = new_node;
    list->tail->next = new_node;
    printf("head: %d;", list->head->data);
    printf(" tail: %d;\n", list->tail->data);
}

/* delete a node from head */
void deleteFirst(cirList *list) {
    /* for empty list */
    if (!list->head) return;
    /*  */
    node *last_head = list->head;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        printf("list becomes empty!\n");
        return;
    } else {
        list->head = list->head->next;
        list->tail->next = list->head;
    }
    free(last_head);
    
    printf("head: %d;", list->head->data);
    printf(" tail: %d;\n", list->tail->data);    
}

/* insert into sorted list */
void sortedInsert(cirList *list, int val) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = val;
    
    node *p = list->head;
    
    if (!p) {                       /* empty list */
        list->head = new_node;
        list->tail = new_node;
        list->tail->next = list->head;
    } 
    else if (p->data >= val) {      /* val <= head */
            new_node->next = list->head;
            list->head = new_node;
            list->tail->next = list->head;
    } 
    else {                          /* val > head */              
        while (p->next && p->next->data < val) {
            p = p->next;
        }
        new_node->next = p->next;
        p->next = new_node;
    }
    printList(list);
}

void printMin(cirList *list) {
    int min = INT_MAX;
    node *p = list->head;
    while (p && p->next != list->tail) {
        if (min > p->data)
            min = p->data;
        p = p->next;
    }
    if (p && min > p->data)
        min = p->data;
    printf("min: %d\n", min);
}


int main() {
    cirList *list;
    list = createList();
    /*
    insertFirst(list, 4);
    insertFirst(list, 3);
    insertFirst(list, 2);
    insertFirst(list, 1);
    */
    sortedInsert(list, 5);
    printMin(list);
    sortedInsert(list, 2);
    printMin(list);
    sortedInsert(list, 4);
    printMin(list);
    sortedInsert(list, 3);
    printMin(list);
    
    printList(list);
    
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    
    return 0;
}


