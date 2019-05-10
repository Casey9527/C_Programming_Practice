#include <stdio.h>
#include <stdlib.h>
#define MSG_CMSG_COMPAT	0x80000000

void main(int ac, char **av)
{
	if (ac != 2) {
		printf("usage: %s <flag_value>\n", av[0]);
		return;
	}

	int flag = atoi(av[1]);
	printf("flag: %d, MSG_CMSG_COMPAT: %d, &: %d\n", 
			flag, MSG_CMSG_COMPAT, MSG_CMSG_COMPAT & flag);
	if (flag & MSG_CMSG_COMPAT)
		printf("if is True\n");
	return;
}
