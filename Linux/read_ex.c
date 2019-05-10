#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int i;
	char data[8];
	int nbytes;

	if((nbytes = read(0, data, 8)) < 0)
		write(2, "An error occurred in the read.\n", 31);

	printf("read %d bytes, data: %s\n", nbytes, data);
	for (i = 0; i < 8; i++)
		printf("data[%d]: %c\n", i, data[i]);

	exit(0);
}
