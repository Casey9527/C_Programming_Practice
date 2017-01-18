void detectAndRemoveLoop(Node *head)
{
    
    if (head == NULL) {
        return;
    }
    
    Node *fast, *slow;
    fast = slow = head;
    
    while (fast && fast->next) {
        slow = fast;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }
    
    Node *meetNode = slow;
    Node *p1, *p2;
    // remove
    if (fast == slow) {
        p1 = head;
        while (1) {
            p2 = meetNode;
            
            while (p2->next != meetNode && p2->next != p1)
                p2 = p2->next;
            
            if (p2->next == p1)
                break;

            p1 = p1->next;
        }        
        p2->next = NULL;   
    }
}