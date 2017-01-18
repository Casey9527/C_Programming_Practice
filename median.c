
#include <stdio.h>
#define MAX_SIZE (100)

typedef struct heap {
	int count;
	int a[MAX_SIZE];
} heap;

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
	return;
}

void insert_max(heap *h, int val) {
	if(h->count == MAX_SIZE) {
		printf("Failed to insert on MAX heap full\n");
		return;
	}

	h->count++;
	h->a[h->count] = val;

	int now = h->count;
	int parent = now/2;

	while(parent >= 1 && h->a[parent] < h->a[now]) {
		swap(h->a, parent, now);
		now = parent;
		parent = now/2;
	}
	return;
}

void delete_max(heap *h) {
	if(h->count == 0) {
		printf("Failed to delete on MAX heap empty\n");
		return;
	}

	h->a[1] = h->a[h->count--];
	int now = 1;
	int now_val = h->a[now];
	int left = h->a[2*now];
	int right = h->a[2*now+1];

	while( (left > now_val && 2*now <= h->count) ||
		   (right > now_val) && 2*now+1 <= h->count) {
		
		int bigger = (left < right) ? right : left;

		if( bigger == left) {
			swap(h->a, now, 2*now);
			now = 2*now;
		} else {
			swap(h->a, now, 2*now+1);
			now = 2*now + 1;
		}

		now_val = h->a[now];
		left = h->a[2*now];
		right = h->a[2*now+1];
	}  
	return;
}

void insert_min(heap *h, int val) {
	if(h->count == MAX_SIZE) {
		printf("Failed to insert on MIN heap full\n");
		return;
	}

	h->count++;
	h->a[h->count] = val;

	int now = h->count;
	int parent = now/2;

	while(parent >= 1 && h->a[parent] > h->a[now]) {
		swap(h->a, parent, now);
		now = parent;
		parent = now/2;
	}
	return;
}

void delete_min(heap *h) {
	if(h->count == 0) {
		printf("Failed to delete on MAX heap empty\n");
		return;
	}

	h->a[1] = h->a[h->count--];
	int now = 1;
	int now_val = h->a[now];
	int left = h->a[2*now];
	int right = h->a[2*now+1];

	while( (left < now_val && 2*now <= h->count) ||
		   (right < now_val) && 2*now+1 <= h->count) {
		
		int smaller = (left < right) ? left : right;

		if( smaller == left) {
			swap(h->a, now, 2*now);
			now = 2*now;
		} else {
			swap(h->a, now, 2*now+1);
			now = 2*now + 1;
		}

		now_val = h->a[now];
		left = h->a[2*now];
		right = h->a[2*now+1];
	}  
	return;
}


void add_integer(heap *min, heap *max, int val) {
	/* insert to max heap */
	insert_max(max, val);

	/*  */
	if((max->count - min->count > 1) ||
	   (min->count > 0 && max->a[1] > min->a[1])) {
		int top = max->a[1];
		delete_max(max);
		insert_min(min, top);
	}

	if((min->count - max->count > 1) &&
	   (min->count > 0)) {
		int top = min->a[1];
		delete_min(min);
		insert_max(max, top);
	}
}

void print_median(heap *min, heap *max) {
	if(max->count == min->count) {
		printf("Median is: %d\n", (max->a[1] + min->a[1])/2);
	} else if(max->count > min->count) {
		printf("Median is: %d\n", max->a[1]);
	} else {
		printf("Median is: %d\n", min->a[1]);
	}
}


int main() {
	int n = 0;
	heap min, max;	
	min.count = 0;
	max.count = 0;

	while(1) {
		printf("Enter a number: ");
		scanf("%d", &n);
		if(n == -1) {	// terminate
			break;
		}
		add_integer(&min, &max, n);
		print_median(&min, &max);
	}
	return 0;
}
