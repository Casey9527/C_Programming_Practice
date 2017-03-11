/*
 * mystrncpy - copy @n bytes from @src to @dst
 * 
 * If there is no '\0' among first n bytes of
 * src, the dst will not be null-terminated.
 *
 * n <= strlen(src): the dst will not be null-terminated
 * n >  strlen(src): first n bytes are followed by '\0'(s)
 *
 */

char* mystrncpy(char *dst, const char *src, size_t n)
{
	assert(dst != NULL && src != NULL);
	char *p = dst;
	while (n > 0) {
		if ( (*p = *src) != '\0' ) {
			src ++;
		}
		p ++, n --;
	}
	return dst;
}

int main(int ac, char *av[])
{
	if (ac != 3) {
		prinf("USAGE: %s source_string length", av[0]);
		return -1;
	}

	int n = atoi(av[2]);

	char *dst = (char *) malloc(n);
	assert(dst != NULL);
	mystrncpy(dst, av[1], n);

	printf("dst:\n%s\n", dst);

	free(dst);
	return 0;
}