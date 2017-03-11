/**
 * 
 * this program demos that you cannot
 * use constant pointer to modify the
 * memory it points to.
 *
 **/

#include <stdio.h>

int main()
{
	int i = 10;
	const int *p = &i;
//	*p -= 1;
	 i -= 1;
	printf("%d\n", i);
	return 0;
}