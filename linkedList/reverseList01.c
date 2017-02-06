Node* reverseList_recursive(Node *head)
{
    // meet the last node or single-node list or empty list
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node *result, *nextNode;    
    nextNode = head->next;      // save the next node
    head->next = NULL;          // make next of current node null
    result = reverseList_recursive(nextNode);   // recursion util find the last
    nextNode->next = head;      // connect from the reverse direction
    
    return result;
}