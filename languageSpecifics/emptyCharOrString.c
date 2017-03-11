#include <stdio.h>
#include <string.h>

void main(void)
{
	PRINT("Test if we can define empty char");
	// char empty_char = ''; // empty character constant is not allowed
	char *empty_str = "";	 // empty string constant is allowed
	printf("empty_str len is: %d\n", (int)(strlen(empty_str)));	// length is 0
}