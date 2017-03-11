/**
 * This program test whether strtok will affect the 
 * original string if first call doesn't return NULL.
 * 
 * After each successfull call, the delimiter is
 * replaced with '\0'
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_string_by_char(char *s)
{
	int i;
	for (i = 0; i < 20; i ++) {
		printf("\'%c\'\t", s[i]);
	}
	printf("\n");	
}

int main()
{
	char s[20] = "hello world ni hao";
	print_string_by_char(s);

	char *token = strtok(s, " ");
	while (token) {
		print_string_by_char(s);
		token = strtok(NULL, " ");
	}

	printf("%s\n", s);

	return 0;
}