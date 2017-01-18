// 6:40 - 7:10

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *a;
    int len;
    int size;
} heap_t;

void insert_heap(heap_t *h, int key)
{
    if (h->len + 1 > h->size) {
        printf("insert failed heap is full\n");
        return;
    }
    
    h->len++;
    int i = h->len;
    int j = i / 2;
    
    while (j >= 1 && h->a[j] < key) {
        h->a[i] = h->a[j];
        i = j;
        j = i / 2;
    }
    h->a[i] = key;
}

int remove_top(heap_t *h)
{
    if (h->len == 0) {
        printf("remove failed heap is empty\n");
        return -1;
    }
    
    int result = h->a[1];       // get the result
    
    int i = 1;
    int j = i * 2;
    int maxChildIndex;
    int last = h->a[h->len];
    h->len--;
    
    while (1) {
        if (j + 1 <= h->len) {      // j+1, j both exist
            maxChildIndex = (h->a[j] >= h->a[j + 1]) ? j : j + 1;
        } else if (j <= h->len)  {  // only j exist
            maxChildIndex = j;
        } else {                    // no child exist
            maxChildIndex = -1;
        }
        
        if (maxChildIndex == -1) 
            break;
        
        if (last < h->a[maxChildIndex]) {   // update i as its biggest child
            h->a[i] = h->a[maxChildIndex];
            i = maxChildIndex;
            j = i * 2;
        } else {
            break;
        }
    }
    h->a[i] = last;
    
    return result;
}

void printHeap(heap_t *h)
{
    int i;
    for (i = 1; i <= h->len; i++)
        printf("%d ", h->a[i]);
    printf("\n");
}

int findKthLargest(int arr[], int n, int k)
{
    // create a binary maximum heap
    heap_t *h = (heap_t *) malloc(sizeof(heap_t));
    h->len = 0;
    h->size = n;
    h->a = (int *) malloc(sizeof(int) * (n + 1));
    
    // insert all array elements into heap
    int i;
    for (i = 0; i < n; i++) {
        insert_heap(h, arr[i]);
        //printHeap(h);
    }
    /*
    for (i = 0; i < n; i++) {
        remove_top(h);
        printHeap(h);
    }
    return 1;
    */
    // remove top elements one by one
    int prev = remove_top(h);
    int result = prev;
    for (i = 0; i < k - 1; i++) {
        result = remove_top(h);
        if (result == prev) {
            i--;
        } else {
            prev = result;
        }
    }
    return result;
}

int main()
{
    int a[] = {5, 5, 6, 7, 4, 3, 2, 1, 8, 10, 9};
    int n = sizeof a / sizeof a[0];
    int k;
    
    scanf("%d", &k);
    printf("%dth largest is: %d\n", k, findKthLargest(a, n, k));
    return 0;
}




