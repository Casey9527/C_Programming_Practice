/*
 *  Implement a LRU cache 
 *  two data structures are used:
 *  1. a double-linked list to store activities of each page
 *  2. an array to lookup the page
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct pageNode {
    int pageNum;
    struct pageNode *prev, *next;
    // struct page *pg;
} pageNode;
 
typedef struct hash {
    int size;
    int len;
    pageNode **a;
} hash;

pageNode* createPageNode(int pageNum)
{
    pageNode *pg = (pageNode *) malloc(sizeof(pageNode));
    if (pg == NULL) {
        printf("page allocated failed\n");
        exit(0);
    }
    pg->prev = pg->next = NULL;
    pg->pageNum = pageNum;
    return pg;
}

typedef struct pageList {
    pageNode *front, *rear;
} pageList;


void insert_list(hash *h, pageList *list, int pageNum)
{
    pageNode *pg = h->a[pageNum];
    /* insert a new pg or a pre-existed pg (access again) */
    if (pg == NULL) {
        pg = createPageNode(pageNum);
        h->a[pageNum] = pg;
    }
    pg->prev = list->rear;
    if (list->rear)
        list->rear->next = pg;
    list->rear = pg;
    if (list->front == NULL) {
        list->front = pg;
    }
    h->len++;
}

void delete_list(hash *h, pageList *list, int pageNum)
{
    if (list->front == NULL || list->rear == NULL) 
        return;
    
    pageNode *pg = h->a[pageNum];
    
    if (pg->prev) {
        pg->prev->next = pg->next;
    } else {
        list->front = pg->next;
    }
    
    if (pg->next) {
        pg->next->prev = pg->prev;
    } else {
        list->rear = pg->prev;
    }
    
    pg->next = pg->prev = NULL;
    
    h->a[pageNum] = NULL;
    h->len--;
}

pageNode* referencePage(hash *h, pageList *list, int pageNum)
{
    /* check if the pageNum is beyond the limit */
    if (pageNum < 0 && pageNum >= 10) {
        printf("invalid pageNum\n");
        return NULL;
    }
    
    pageNode *pg = h->a[pageNum];
    pageNode *delete_node;
    
    /* hit or miss */
    if (pg == NULL) { /* cache miss */
        if (h->len < h->size) { /* cache is not full*/ 
        /* store new page */
            insert_list(h, list, pageNum);
        } else { /* cache is full */
        /* evict the LR page, store new page */
            delete_node = list->front;
            delete_list(h, list, delete_node->pageNum);
            free(delete_node);
            insert_list(h, list, pageNum);
        }
    } else { /* cache hit */
        /* adjust the activities */
        if (pg != list->rear) {
            /* delete the existed pg, rearrange it to rear */
            delete_node  = pg;
            delete_list(h, list, pageNum);
            h->a[pageNum] = delete_node;
            insert_list(h, list, pageNum);
        }
        
    }
    return h->a[pageNum];
}

void printList(pageList *list)
{
    if (list->front)
        printf("front: %d, ", list->front->pageNum);
    if (list->rear)
        printf("rear: %d\n", list->rear->pageNum);
    
    pageNode *pg = list->front;
    while(pg) {
        printf("%d ", pg->pageNum);
        pg = pg->next;
    }
    printf("\n");
}

int main()
{
    /* create hash */
    hash *h = (hash *) malloc(sizeof(hash));
    h->size = 5;
    h->len = 0;
    h->a = (pageNode **) malloc(sizeof(pageNode *) * 10);
    int i;
    for (i = 0; i < 10; i++)
        h->a[i] = NULL;
    
    /* create list */
    pageList *list = (pageList *) malloc(sizeof(pageList));
    list->front = list->rear = NULL;
    
    /* add new pg 0, 1, 2 */
    referencePage(h, list, 0);
    referencePage(h, list, 1);
    referencePage(h, list, 2);
    printList(list);

    /* not full, reference rear 2 */
    referencePage(h, list, 2);
    printList(list);
    
    /* not full, reference old pg 1 (not rear) */
    referencePage(h, list, 1);
    printList(list);
    
    /* add new pgs til full */
    referencePage(h, list, 3);
    referencePage(h, list, 4);
    printList(list);
    
    /* when full, replace old pg */
    referencePage(h, list, 5);
    printList(list);
    
    /* when full, replace old pg */
    referencePage(h, list, 6);
    printList(list);
    
    /* when full, reference rear pg 6 */
    referencePage(h, list, 6);
    printList(list);
    
    /* when full ,reference old pg (not rear) 3*/
    referencePage(h, list, 3);
    printList(list);
    
    return 0;
}
