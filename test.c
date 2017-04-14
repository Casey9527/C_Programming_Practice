#include <stdio.h>
#include <string.h>

#define PRINT(string)	\
        do { printf("%s\n", string); } while (0) \

void main(void)
{
	// is this modifiable ? Yes it is
	char str[] = "hello, world!";
	// char *str = "hello, world!";	// not modifiable
	strcpy(str, "world, hello!");
	printf("%s\n", str);

	PRINT("Test if we can define empty char");
	// char empty_char = ''; // empty character constant is not allowed
	char *empty_str = "";	 // empty string constant is allowed
	printf("empty_str len is: %d\n", (int)(strlen(empty_str)));	// length is 0

	printf("strlen(\"\") is: %d\n", (int)strlen(""));

	char c = ' ';

	printf("value of true is: %d\n", (int) (2 > 1));
	printf("value of false is: %d\n", (int) (2 < 1));

	printf("ascii value of \' \' is: %d\n", (int) c);	// 32

	char s[] = "kexin";

	printf("strlen(\'\\0\') is %d\n", (int)strlen(s + 5));
}