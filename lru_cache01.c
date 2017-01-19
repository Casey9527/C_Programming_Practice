#include <stdio.h>
#include <stdlib.h>

/** A double linked-list to record pages cached 
 *  
 *         pageN-1--> ...    page1-->     page0--> nil
 *  nil <--               <--          <--
 *          |                              |
 *          |                              |
 *		    most-recently-used page        least-recently-used page
 *
 */
typedef struct page {
    int num;
    struct page *prev, *next;
} page;

page* create_page(int num)
{
    page * p = (page *)malloc(sizeof(page));
    p->num = num;
    p->next = p->prev = NULL;
    return p;
}

typedef struct page_list {
    page *oldest;   // address of least-recently-used page
    page *newest;   // address of  most-recently-used page
    int len;		// actually cache size
    int size;		// cache capacity
} page_list;

page_list* create_page_list(int size)
{
    page_list *plist = (page_list *) malloc(sizeof(page_list));
    plist->oldest = plist->newest = NULL;
    plist->len = 0;
    plist->size = size;
    return plist;
}

void print_page_list(page_list *plist)
{
    page *p = plist->newest;
    
    printf("newest: %d , ", plist->newest->num);
    printf("oldest: %d , ", plist->oldest->num);
    printf("newest -> oldest: ");
    
    while (p != NULL && p != plist->oldest) {
        printf("%d ", p->num);
        p = p->next;
    }
    // print the last one
    if (p != NULL)
        printf("%d\n", p->num);
}

/**
 * Mappings: page number --> its cache line address (page address)
 *
 */
typedef struct hash {
    page* *pages;		// pointer array storing page addresses
    int cache_size;     // in pages
} hash;

hash* create_hash(int cache_size)
{
    hash *h = (hash *) malloc(sizeof(hash));
    h->cache_size = cache_size;
    h->pages = (page* *) malloc(sizeof(page *) * h->cache_size);
    
    int i;
    for (i = 0; i < h->cache_size; i ++)
        h->pages[i] = NULL;
    return h;
}

/**
 * page_access:	access a page
 * 
 * @plist: 				page list recording the pages cached
 * @h:					page address lookup
 * @access_page_num:	page number
 * 
 * return the address of page requested
 */
void
page_access(page_list *plist, hash *h, int access_page_num)
{
    printf("/*\n");
    if (h->pages[access_page_num] != NULL) {	/* cache hit */
        printf("page <%d> cached before.\n", access_page_num);
        page* p = h->pages[access_page_num];
        
        if (p == plist->oldest) {					/* if access the oldest one */
            printf("this page is the oldest\n");
            plist->newest->prev = plist->oldest;
            plist->oldest->next = plist->newest;
            
            plist->newest = plist->oldest;
            plist->oldest = plist->oldest->prev;
            
            plist->newest->prev = NULL;
            plist->oldest->next = NULL;
        }
        else if (p != plist->newest) {				/* if not the oldest one */
            printf("this page is not the newest\n");
            p->prev->next = p->next;
            p->next->prev = p->prev;
            p->prev = NULL;
            p->next = plist->newest;
            plist->newest->prev = p;
            plist->newest = p;
        }
        
        goto ret;
    }
    else {										/* cache miss */
        printf("page <%d> is not cached.\n", access_page_num);
        
        page *p = create_page(access_page_num);
        
        if (plist->len < plist->size) {				/* cache is not full: insert it as the newest */
            printf("cache is not full\n");
            if (plist->len == 0) {
                printf("this is the first page cached\n");
                plist->oldest = plist->newest = p;
            } else {
                printf("this is not the first page\n");
                p->next = plist->newest;
                plist->newest->prev = p;
                plist->newest = p;
            }
            plist->len ++;
        }
        else {										/* cache is full: evict the oldest */
            printf("cache is full\n");
            page *orig_oldest = plist->oldest;
            plist->oldest = orig_oldest->prev;
            
            plist->oldest->next = NULL;
            
            free(orig_oldest);
            
            p->next = plist->newest;
            plist->newest->prev = p;
            plist->newest = p;
        }
        
        h->pages[access_page_num] = p;
    }

  ret:
      printf("*/\n\n");
      return;

}

/**
 * testcases design:
 * 
 * cache is full: 0 1 2 3 4
 *  - access the page already cached: 4/3/2/1/0
 *  - access new page: 5, 6, 7, 8, 9
 * 
 * 
 * cache is not full: 0 1 2 3
 *  - access a new page: 4
 *  - access pages already cached: 3/2/1/0
 * 
 * */
int
main()
{
    // access range: 0 ~ 9
    hash *h = create_hash(10);
    
    // cache size: 5 pages
    page_list *plist = create_page_list(5);
    
    page_access(plist, h, 0);
    page_access(plist, h, 1);
    page_access(plist, h, 2);
    page_access(plist, h, 3);
    page_access(plist, h, 4);

    page_access(plist, h, 0);
    print_page_list(plist);

    page_access(plist, h, 5);
    print_page_list(plist);

 
    page_access(plist, h, 6);
    print_page_list(plist);
    
    page_access(plist, h, 7);
    print_page_list(plist);
    
    page_access(plist, h, 8);
    print_page_list(plist);
    
    page_access(plist, h, 9);
    print_page_list(plist);
    
    return 0;
}
