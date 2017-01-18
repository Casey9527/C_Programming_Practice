// Below is the declaration of "Listnode" structure; suppose both "data" and "Listnode" were allocated from heap, please write a program to destroy the entire link list.
   typedef struct Listnode {
      struct Listnode *next;
      char *data;
   } Listnode;
 
   void destroy_list(Listnode *head) {
      /* Implement the function. */
      
      // iterate each node and free the space of each node
      
      if (head == NULL) return;
      
      Listnode *p = head;
      Listnode *last_node;
      // iterate the whole list
      while (p) {
          last_node = p;            // save the reference to the current node
          p = p->next;              // change p to its next
          if (last_node->data)
            free(last_node->data);    // free data area of node
          free(last_node);          // free the space of current node
      }
      
   }   
   
 