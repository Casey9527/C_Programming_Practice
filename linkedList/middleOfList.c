

Node* middleOfList(Node* head)
{
    if (head == NULL)
        return NULL;
    Node *runner, *walker;
    runner = walker = head;
    
    while (runner->next != NULL && runner->next->next != NULL) {
        runner = runner->next->next;
        walker = walker->next;
    }
    return walker;
}

