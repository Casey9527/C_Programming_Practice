/*
 * bitwise method to check  
 * whether a number is odd or even
 *
 */
#include <stdio.h>
#define ODD  1
#define EVEN 0

int is_even_or_odd(int x)
{
	if ((x & 1) == 0) {
	    return EVEN;
	} else {
	    return ODD;
	}
}

void main(void)
{
	int x = 0;
	printf("Input a number: ");
	scanf("%d", &x);
	if (EVEN == is_even_or_odd(x)) {
		printf("%d is even\n", x);
	} else {
		printf("%d is odd\n", x);
	}
}