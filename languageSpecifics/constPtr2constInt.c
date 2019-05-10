#include <stdio.h>

void modify_pointer(char *const *i)
{
	printf("%p: %s\n", *i, *i);

	/*
	 * Below two lines doesn't work
	 * Because the pointer to char is const
	 * However, the pointer to pointer to char is not.
	 */
//	*i = (char *)0x1234;
//	printf("Modify char * is OK\n");

	printf("Before: &av[0] is: %p\n", i);

	i = (char **)0x1234;
	printf("Modify char ** is OK\n");

	printf("After: &av[0] is: %p\n", i);
}

void main(int ac, char **av)
{
	if (ac != 4)
	{
		printf("usage: %s string1 string2 string3\n", av[0]);
		return;
	}

	int i = 0;
	for (; i < 4; i++) {
		printf("%p: av[%d]: %s\n", av[i], i, av[i]);
	}

	modify_pointer(av);
}
