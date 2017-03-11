/**
 * mystrcpy() - copy string @src to @dst
 *
 * Assumptions:
 * 1. dst, and src are non-NULL 
 * 2. dst has enough spaces
 * 3. src is null-terminated i.e. ending with '\0'
 * 
 **/

#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

int mystrcpy(char *dst, const char *src)
{
	if (src == NULL || dst == NULL) {
		return FAILURE;
	}

	char *p = dst;

	while ( (*p ++ = *src ++) != '\0' )
		;

	return SUCCESS;
}

void results_evaluation(int flag, const char *dst)
{
	if (flag) {
		printf("Error\n");
	} else {
		printf("dst: %s\n", dst);
	}
}

void main(void)
{
	char src0[20] = "Kexin";
	char dst0[5];

	int flag = mystrcpy(dst0, src0);
	results_evaluation(flag, dst0);
}