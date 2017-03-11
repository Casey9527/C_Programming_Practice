#include <stdio.h>
#include <string.h>

void main(void)
{
	// is this modifiable ? Yes it is
	char str[] = "hello, world!";
	// char *str = "hello, world!";	// not modifiable
	strcpy(str, "world, hello!");
	printf("%s\n", str);
}