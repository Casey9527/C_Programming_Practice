
#include <stdio.h>
#include <bsd/string.h>

int main(int ac, char *av[])
{
	char a[10];
	int n;
	char *b;
	
	b = a;

	printf("sizeof(b): %lu\n", sizeof(b));

	printf("av[1]: strlen: %lu, sizeof: %lu\n",
		strlen("hellohello"), sizeof("hellohello"));

	printf("sizeof(a): %lu\n", sizeof(a));

	n = strlcpy(a, "hellohell", sizeof(a));

	printf("n: %d, a: %s\n", n, a);
	return 0;
}
