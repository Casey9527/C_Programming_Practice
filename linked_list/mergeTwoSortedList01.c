/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
    Node *p1 = headA, *p2 = headB;
    Node *newHead = (Node *) malloc(sizeof(Node));
    newHead->data = 0;
    newHead->next = NULL;
    Node *p = newHead;
    
    while (p1 && p2) {
        if (p1->data <= p2->data) {
            p->next = p1;
            p1 = p1->next;
        } else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1 == NULL)
        p->next = p2;
    else if (p2 == NULL)
        p->next = p1;
    return newHead->next;    
}
