#include <stdio.h>
 
// m-th on the reversed kill list; m = 0 is final survivor
int jos(int n, int k, int m) {
	int a;
	for (a = m + 1; a <= n; a++)
		m = (m + k) % a;
	return m;
}
 
typedef unsigned long long xint;
 
// same as jos(), useful if n is large and k is not
xint jos_large(xint n, xint k, xint m) {
	if (k <= 1) return n - m - 1;
 
	xint a = m;
	while (a < n) {
		xint q = (a - m + k - 2) / (k - 1);
 
		if (a + q > n)	q = n - a;
		else if (!q)	q = 1;
 
		m = (m + q * k) % (a += q);
	}
 
	return m;
}
 
int main(void) {
	xint n, k, i;
 
	n = 7;
	k = 3;
	
	for (i = 0; i < 7; i++)
	    printf("n = %llu, k = %llu, <%llu>th survivoris : %d\n", n, k, 7 - i, jos(n, k, i) + 1);
 	

	n = 9876543210987654321ULL;
	k = 12031;
	printf("n = %llu, k = %llu, three survivors:", n, k);
 
	for (i = 3; i--; )
		printf(" %llu", jos_large(n, k, i));
	putchar('\n');
 
	return 0;
}