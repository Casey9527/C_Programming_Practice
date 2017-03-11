/**
 *
 *	convert a IP address represented by a string to unsigned int in network byte order
 *  
 *  assume host machine is little-endian
 *
 * "192.168.100.188" -> C0 A8 64 BC -> BC 64 A8 C0 (big-endian)
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int cip2uint(const char *cip)
{	
	char *cip_copy = strdup(cip);
	if (cip_copy == NULL) {
		return 0;
	}

	unsigned int uip = 0;
	int tmp = 0;
	char *byte;

	if (cip_copy == NULL || 
		strlen(cip_copy) > 15 || 
		strlen(cip_copy) < 7) {
		return 0;
	}

	byte = strtok(cip_copy, ".");
	int i = 0;

	for ( ; byte && i < 4 ; i ++) {
		if (strlen(byte) > 3) {
			return (0);
		}
		tmp = atoi(byte);
		if (tmp < 0x00 || tmp > 0xFF) {
			return 0;
		}
		uip <<= 8;
		uip += tmp;
		byte = strtok(NULL, ".");
	}

	free(cip_copy);

	return ( (uip & 0xFF      ) << 24 ) |
           ( (uip & 0xFF00    ) << 8  ) |
           ( (uip & 0xFF0000  ) >> 8  ) |
           ( (uip & 0xFF000000) >> 24 );
}

int main(int ac, char *av[])
{
	if (ac != 2) {
		printf("USAGE: ./charIP2uint \"ip_address\"\n");
		return 0;
	}

	printf("0x%.8X\n", cip2uint(av[1]));
	return 0;
}