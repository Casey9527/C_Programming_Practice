
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node node;

void push(struct node ** head_ref, int new_data) {
    
    node *new_node = (node *) malloc(sizeof(node));
    if (new_node == NULL) {
        printf("failed to allocate new node\n");
        getchar();
        exit(0);
    }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void printNthFromLast(node *head, int n) {
    node *main_ptr = head;
    node *ref_ptr = head;
    int count = 0;
    if (head != NULL) {
        while (count < n) {
            if (ref_ptr == NULL) {
                printf("%d is greater than size of list\n", n);
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        while (ref_ptr != NULL) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        printf("Node no. %d from last is %d\n", n, main_ptr->data);
    }
}

int main() {
    node *head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    
    int n = 0;
    scanf("%d", &n);
    
    printNthFromLast(head, n);
    return 0;
}