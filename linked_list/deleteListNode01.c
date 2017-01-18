#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *next;
};

struct node* createNode(int val) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("failed to allocate new node\n");
        getchar();
        exit(0);
    }
    new_node->next = NULL;
    new_node->data = val;
    return new_node;
}


struct node* deleteNode(struct node *head, int val) {
    
    struct node *dummy = createNode(0);
    dummy->next = head;
    
    struct node *p = dummy;
    struct node *tmp;
    while (p->next) {
        if (p->next->data == val) {
            tmp = p->next->next;    /* keep the next */
            free(p->next);          /* free the delete node */
            p->next = tmp;          /* link the two pieces */
            break;
        }
        p = p->next;
    }
    return dummy->next;
}

void printList(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    //struct node *head = NULL;
    
    struct node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    int k;
    scanf("%d", &k);
    
    printList(head);
    printList(deleteNode(head, k));
    return 0;
}