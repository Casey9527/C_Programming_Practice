
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int fact(int n) {
	return (n == 1) ? 1 : n * fact(n - 1);
}

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void perm_by_iteration(char *s, int n)
{
	assert(s != NULL && n > 0);
	if (n == 1) {
		printf("%s\n", s);
		return;
	} else if (n == 2) {
		printf("%s\n", s);
		swap(&s[0], &s[1]);
		printf("%s\n", s);
		return;
	}

	int fc = fact(n);	// total number of perms
	int cnt = 0;		// number of perms we found so far
	int subfc = fc / n;	// total number of perms for n-1 chars
	int subcnt = 0;
	int m = 1;			// index of next char to put at first position

	int i;

	while (cnt != fc) {
		subcnt = 0;
		while (subcnt != subfc) {
			for (i = 1; i < n - 1; ++ i) {
				swap(&s[i], &s[i + 1]);
				printf("%s\n", s);	// we get one perm
				cnt += 1;
				subcnt += 1;
			}
		}
		swap(&s[0], &s[m]);
		m ++;
	}
	printf("total: %d\n", cnt);
}


int main(int ac, char *av[])
{
	if (ac != 2) {
		printf("USAGE: %s string_to_permute\n", av[0]);
		return -1;
	}

	perm_by_iteration(av[1], strlen(av[1]));

	return 0;

}