#include <stdio.h>

#define STR1(x) #x
#define STR2(x) STR1(x)

#define target 5
int main(int ac, char **av)
{
	if (ac != 2)
		return -1;

	int memtype = 0;
//	char target[3] = "n2h";

	sscanf(av[1],  "STR2(target), %d", &memtype);

	printf("memtype: %d\n", memtype);

	return 0;
}
