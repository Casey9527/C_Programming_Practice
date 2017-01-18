

int isCyclic(Node* head, Node* *meetNode)
{
    if (head == NULL) {
        return 0;
    }
    
    Node *walker, *runner;
    walker = runner = head;
    while (runner->next != NULL && runner->next->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
        if (runner == walker) {
            *meetNode = runner;
            return 1;
        }
    }
    return 0;
}

void removeCycle(Node* head)
{
    Node *meetNode = NULL;
    if (!isCyclic(head, &meetNode))
        return;
    
    // how many nodes in the cycle
    int nodesInCycleMinusOne = 0;
    Node *p = meetNode;
    while (p->next != meetNode) {
        nodesInCycleMinusOne++;
        p = p->next;
    }
    
    // get begin node in the cycle
    Node *p1, *p2;
    p1 = meetNode;
    p2 = head;
    
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // move to the node before the end node
    while (nodesInCycleMinusOne > 0) {
        p1 = p1->next;
        nodesInCycleMinusOne--;
    }
    p1->next = NULL;
}

