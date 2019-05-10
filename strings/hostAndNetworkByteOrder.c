#include <stdio.h>
#include <netinet/in.h>

int main(void)
{
	unsigned int a = 0x123456;
	unsigned int b;
	char *s;

	s = (char *)&a;
	int i = 0;

	printf("host byte order:\n");
	for ( ; i < sizeof(a); ++i) {
		printf("%p: a[%d]: %x\n", s, i, (unsigned int)*s);
		s++;
	}

	s = (char *)&b;
	b = htonl(a);

	printf("network byte order:\n");
	for (i = 0; i < sizeof(b); ++i) {
		printf("%p: b[%d]: %x\n", s, i, (unsigned int)*s);
		s++;
	}

	return 0;
}
