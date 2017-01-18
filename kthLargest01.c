// 9:39
// find the kth largest element in an array

#include <stdio.h>
#include <stdlib.h>

typedef struct heap {
    int *arr;
    int capacity;
    int size;           // initial size = -1
} maxheap;

maxheap* newHeap(int size)
{
    maxheap *h = (maxheap *) malloc(sizeof(maxheap));
    if (h == NULL) {
        printf("allocate heap failed\n");
        return NULL;
    }
    h->size = -1;
    h->capacity = size;
    h->arr = (int *) malloc(sizeof(int) * size);
    return h;
}

int getParentIndex(int index)
{
    if (index <= 0) {
        return -1;
    }
    return (index % 2) ? (index / 2) : (index / 2 - 1);
}

void swap(int arr[], int index1, int index2)
{
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;
}

void insert_heap(maxheap *h, int key)
{
    if (h->size >= h->capacity - 1) {
        printf("heap is full\n");
        return;
    }
    
    h->size++;
    h->arr[h->size] = key;

    int currentIndex = h->size;
    int parentIndex = getParentIndex(currentIndex);
    while (parentIndex >= 0) {
        if (h->arr[parentIndex] < h->arr[currentIndex]) {
            swap(h->arr, parentIndex, currentIndex);
            currentIndex = parentIndex;
            parentIndex = getParentIndex(currentIndex);
        } else {
            break;
        }
    }
}

int removeMax_heap(maxheap *h)
{
    if (h->size == -1) {
        printf("heap is empty\n");
        return -1;
    }
    int result = h->arr[0];
    
    h->arr[0] = h->arr[h->size];
    h->size--;
    
    int currentIndex = 0;
    int childIndex = currentIndex * 2 + 1;
    int maxIndex = childIndex;
    while (childIndex <= h->size) {
        if (childIndex + 1 <= h->size  
            && h->arr[childIndex] < h->arr[childIndex + 1]) 
        {
            maxIndex = childIndex + 1;
        }
        if (h->arr[currentIndex] < h->arr[maxIndex])
        {
            swap(h->arr, currentIndex, maxIndex);
            currentIndex = maxIndex;
            childIndex = currentIndex * 2 + 1;
            maxIndex = childIndex;
        } else {
            break;
        }
    }
    return result
}

void printHeap(maxheap *h)
{
    int i;
    for (i = 0; i <= h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}

int findKthLargest(int arr[], int size, int k)
{
    int result;
    
    // create a max_heap
    maxheap *h = newHeap(size);

    // insert all elements into a max heap
    int i;
    for (i = 0; i < size; ++i) {
        insert_heap(h, arr[i]);
        //printHeap(h);
    }
    
    /* for testing the heap delete operation
    for (i = 0; i < size; ++i) {
        result = removeMax_heap(h);
        printHeap(h);
    }
    */
    
    // first time removal
    int prev = removeMax_heap(h);
    result = prev;
    
    // remove k-1 times from the max heap
    for (i = 0; i < k - 1; i++) {
        result = removeMax_heap(h);
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
    
    findKthLargest(a, n, 1);
    scanf("%d", &k);
    printf("%dth largest is: %d\n", k, findKthLargest(a, n, k));
    return 0;
}