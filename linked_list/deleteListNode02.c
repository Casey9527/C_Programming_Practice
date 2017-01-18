/*
    delete a node in int type linked list without knowing the head
*/

void deleteNode(Node *node)
{
    if (node == NULL || node->next == NULL) {
        return;
    }
    
    Node *tmp = node->next;
    node->data = tmp->data;
    node->next = tmp->next;
    free(tmp);
}





