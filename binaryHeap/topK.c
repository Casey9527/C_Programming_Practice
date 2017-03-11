// 11:51

/**
 *
 * get the kth largest element from an array
 *
 * - implement by using binary heap (max heap)
 *
 **/


typedef struct heap {
	int *A;		// 
	int len;	// actually number of elements, 
	            // i.e. index of next available spot. len = 1 at initial
	int size;	// can actually hold (size - 1) elements
} max_heap;


void insert(max_heap *h, int val)
{
	// todo: is full ?

	int i = h->len;
	int j = i / 2;

	while (i > 1 && h->A[j] < val) {
		h->A[i] = h->A[j];
		i = j;
		j = i / 2;
	}
	h->A[i] = val;
	h->len ++;
}

int remove(max_heap *h)
{
	// todo: is empty ?
	int ret = h->A[1];

	h->A[1] = h->A[-- len];

	int p = 1, c1 = p * 2, c2= p * 2 + 1;
	int max_index = p;

	while (c1 <= h->len && c2 <= h->len) {
		if (h->A[c1] > h->A[p]) {
			max_index = c1;
		}
		if (h->A[max_index] > h->A[c2]) {
			max_index = c2;
		}
		if (max_index == p) {
			break;
		}
		swap(&h->A[p], &h->A[max_index]);
		p = max_index;
		c1 = p*2;
		c2 = p*2 + 1;
	}
	return ret;
}

