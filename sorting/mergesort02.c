
#include <stdio.h>
#include <stdlib.h>

// 2:37 - 2:55
typedef struct Node {
    struct Node *next;
    int val;
} Node;

Node* newNode(int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}
/* find the second head and disconnect the two halves */
Node* findSecondHead(Node *head)
{
    Node *runner, *walker, *secondHead;
    runner = walker = head;
    
    while (runner->next != NULL && runner->next->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
    }
    secondHead = walker->next;
    walker->next = NULL;
    return secondHead;
}


Node* merge(Node *head1, Node *head2)
{
    Node *p1 = head1, *p2 = head2;
    Node *dummy = newNode(0);
    Node *p;
    p = dummy;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->val <= p2->val) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    
    if (p1 != NULL) {
        p->next = p1;
    } else {
        p->next = p2;
    }
    
    return dummy->next;
}

Node* mergesort(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *secondHead = findSecondHead(head);
    
    return merge(mergesort(head), mergesort(secondHead));
}

void printList(Node *head)
{
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void push(Node* *head_ref, int val)
{
    Node *new_node = newNode(val);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int main()
{
    Node *head = NULL;
    push(&head, 2);
    push(&head, 1);
    push(&head, 11);
    push(&head, 9);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    
    printList(head);
    
    Node *newHead = mergesort(head);
    
    printList(newHead);
    
    return 0;
}