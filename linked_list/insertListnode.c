// Below is the declaration of "Listnode" structure; please write a program to insert a node into sorted linklist ("data" value from low to high).

   typedef struct Listnode {
      struct Listnode *next;
      int data;
   } Listnode;
   
    // Below is the declaration of "Listnode" structure; please write a program to insert a node into sorted linklist ("data" value from low to high).

   typedef struct Listnode {
      struct Listnode *next;
      int data;
   } Listnode;
   
   Listnode* sortedInsert(Listnode *head, Listnode *node) {
       
       // main idea: find the correct position for the inserted node
       // corner case: when head is null, or node is inserted at the end
       if (head == NULL) {
           return node;
       }
       
       if (node == NULL) {
           return head;
       }
       
       if (node->data <= head->data) {
           node->next = head;
           return ndoe;
       }
       Listnode *p = head, *tmp;
       while (p->next) {
           if (p->next->data >= node->data) {
               temp = p->next;
               p->next = node;
               node->next = temp;
               break;
           }
           p = p->next;
       }
       // for head is null or node is inserted at the end
       if (!p->next) {
           p->next = node;
       }
       return head;
   }
   
   
   /*
   Listnode* sortedInsert(Listnode *head, Listnode *node) {
       
       // main idea: find the correct position for the inserted node
       // corner case: when head is null, or node is inserted at the end
       if (head == NULL) {
           return node;
       }
       Listnode *dummy = (Listnode *) malloc(sizeof(Listnode));
       dummy->data = 0;
       dummy->next = head;
       
       Listnode *p = dummy;
       Listnode *temp;
       // check p and its next 
       
       // 0->1->2->3->4 insert 1
       
       
       // p->(p->next)(first node larger or equal to insert node)
       while (p->next) {
           if (p->next->data >= node->data) {
               temp = p->next;
               p->next = node;
               node->next = temp;
               break;
           }
           p = p->next;
       }
       // for head is null or node is inserted at the end
       if (p->next) {
           p->next = node;
       }
       return dummy->next;
   }   