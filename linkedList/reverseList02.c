Node* reverseList_iterative(Node *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    Node *p1, *p2, *tmp;
    p1 = head;
    p2 = head->next;
    
    while (p1 != NULL && p2 != NULL) {
        tmp = p2->next;     // save the next
        p2->next = p1;      // p1 <--- p2
        p1 = p2;            // switch to next pair
        p2 = tmp;           
    }
    head->next = NULL;
    return p1;
}