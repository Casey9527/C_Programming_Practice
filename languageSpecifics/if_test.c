


#include <stdio.h>

int main()
{

	int err = -22;

	if (err)
		printf("if(%d) is true\n", err);

	if (!err)
		printf("if(!(%d)) is true\n", err);

	if(-22)
		printf("x\n");

/*
	while (-1) {
		printf("-1 is true in while\n");
	}
*/

	while (0) {
		printf("0 is true in while\n");
	}
	return 0;
}
