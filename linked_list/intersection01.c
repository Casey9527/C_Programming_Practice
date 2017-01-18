/**
 * 
 * find the intersections of two linked-lists
 * 
 * */
 
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int val;
    struct listnode * next;
} listnode;

listnode* create_node(int val)
{
    listnode * node = (listnode *) malloc(sizeof(listnode));
    node->val = val;
    node->next = NULL;
    return node;
}

int get_count(listnode *h)
{
    int size = 0;
    while (h != NULL) {
        size ++;
        h = h->next;
    }
    return size;
}

void print_list(listnode *h)
{
    while (h) {
        printf("%d ", h->val);
        h = h->next;
    }
    printf("\n");
}

listnode* get_intersection(listnode *h1, listnode *h2)
{
    if (h1 == NULL || h2 == NULL) {
        return NULL;
    }
    
    // calculate count c1, c2
    int c1 = get_count(h1);
    int c2 = get_count(h2);
    int abs_diff = (c1 > c2) ? (c1 - c2) : (c2 - c1);
    
    listnode *longer = (c1 > c2) ? h1 : h2;
    listnode *shorter = (longer == h1) ? h2 : h1;
    
    // positioning on the longer list at offset abs(c1 - c2)
    while (abs_diff --) {
        longer = longer->next;
    }
    
    while (longer != NULL && longer != shorter) {
        longer = longer->next;
        shorter = shorter->next;
    }
    
    if (longer == NULL) {
        printf("No intersection\n");
        return NULL;
    }
    else {
        return longer;
    }
}


int
main()
{
    listnode *h1_1 = create_node(1);
    listnode *h1_2 = create_node(2);
    listnode *h1_3 = create_node(3);
    listnode *h1_4 = create_node(4);
    
    h1_1->next = h1_2;
    h1_2->next = h1_3;
    h1_3->next = h1_4;

    listnode *h2_1;

    h2_1 = create_node(5);
//    h2_1 = NULL;  
//    h2_1 = h1_1;
//    h2_1 = h1_2;
//    h2_1 = h1_3;
//    h2_1 = h1_1;
    
    printf("list1: \n");
    print_list(h1_1);
    printf("list2: \n");
    print_list(h2_1);
    
    
    listnode *inter = get_intersection(h1_1, h2_1);
    
    printf("intersection: \n");
    print_list(inter);
    
    return 0;
}