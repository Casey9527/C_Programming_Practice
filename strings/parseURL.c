#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 64

struct descriptor_url {
	char protocol[MAX_STR_LEN];
	char hostname[MAX_STR_LEN];
	int port;
};

int parseURL(char *url, struct descriptor_url *d_url)
{
	char *p, *p1;
	int len;

	if (url == NULL || d_url == NULL) {
		return -1;
	}

	if ( (p = strstr(url, "://")) != NULL) {
		if ( (len = p - url) >= MAX_STR_LEN )
			return -1;
		strncpy(d_url->protocol, url, len);
		d_url->protocol[len] = '\0';
	} else {
		return -1;
	}
	p += 3;		// skip "://"

	p1 = p;

	while ((*p != ':') && (*p != '\0')) {
		p ++;
	}

	len = p - p1;
	if ( len >= MAX_STR_LEN || len == 0 ) {
		return -1;
	}

	strncpy(d_url->hostname, p1, len);
	d_url->hostname[len] = '\0';
	d_url->port = atoi(++ p);

	return 0;
}

int main(int ac, char *av[])
{
	char *srcURL;
	struct descriptor_url dest;

	if (ac < 2) {
		printf("USAGE: %s url\n", av[0]);
		return -1;
	}
	srcURL = av[1];
	if ((parseURL(srcURL, &dest)) == 0) {
		printf("Protocol: %s, Hostname: %s, Port: %d\n", 
			    dest.protocol, dest.hostname, dest.port);
	} else {
		printf("Invalid URL: %s\n", av[1]);
	}
	return 0;
}