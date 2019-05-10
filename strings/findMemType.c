#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 32
#define NSS_MEMINFO_MEMTYPE_COUNT 2

/*
 * Names of memory type for user.
 */
char *nss_meminfo_memtype_table[NSS_MEMINFO_MEMTYPE_COUNT] = {
	"Large-Object",
	"Fast-Access"
};

char nss_meminfo_user_config[1024];

int nss_meminfo_get_memtype(int index)
{
	char *user_config;
	char needle[8];
	char user_choice[MAXLEN];
	char **mtype_table;
	int mtype_user = -1;

	int i;
	char *p = NULL;

	user_config = nss_meminfo_user_config;
	mtype_table = nss_meminfo_memtype_table;

	sprintf(needle, "<%d, ", index);
	printf("needle: %s\n", needle);

	p = strstr(user_config, needle);

	if (p == NULL) {
		printf("cannot find in user configuration\n");
		return -1;
	}

	p += strlen(needle);
	printf("p starts from: %s\n", p);

	for (i = 0; i < MAXLEN - 1; i++) {
		if (*p == '>' || *p == '\0')
			break;
		user_choice[i] = *p;
		p++;
	}

	user_choice[i] = '\0';

	printf("user choice: %s\n", user_choice);
	for (i = 0; i < NSS_MEMINFO_MEMTYPE_COUNT; i++) {
		if (strcmp(mtype_table[i], user_choice) == 0) {
			return i;
		}
	}

	return -1;
}


int main(int ac, char *av[])
{
	if (ac != 3)
		return -1;

	// findMemType <index> <"<1, Fast-Object>, <>, <>">

	int index = atoi(av[1]);
	int memtype = -1;

	strcpy(nss_meminfo_user_config, av[2]);

	printf("Find <%d> from User config: %s\n", index, nss_meminfo_user_config);

	memtype = nss_meminfo_get_memtype(index);

	printf("memtype: %d\n", memtype);

	return 0;
}

