// 9:45pm - 10:07pm

// detect the loop in a linked list and remove the circle

// -1: no loop, 1: loop exists
int detectLoop(Node *head, Node* *meetNode_ref)
{
    if (head == NULL) {
        return -1;
    }
    Node *walker, *runner;
    walker = runner = head;
    while (runner->next != NULL && runner->next->next != NULL) {
        walker = walker->next;
        runner = runner->next->next;
        if (runner == walker) {
            *meetNode_ref = runner;
            return 1;
        }
    }
    return -1;
}

void removeCircle(Node *head)
{
    if (head == NULL) {
        return;
    }
    Node *meetNode = NULL;
    if (!detectLoop(head, &meetNode)) { // loop doesn't exist
        return;
    }
    // else, we remove circle
    
    Node *p1 = head;
    Node *p2 = meetNode;
    
    while (p2->next != p1->next) {
        p2 = p2->next;
        p1 = p1->next;
    }
    
    // remove circle
    p1->next = NULL;
}

// http://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/