/*
** pipe2.c -- a smarter pipe example
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void) {
	int pdfs[2];
	char buf[30];

	pipe(pdfs);

	if (!fork()) {
		printf(" CHILD: writing to the pipe\n");
		write(pdfs[1], "test", 5);
		printf(" CHILD: exiting\n");
		exit(0);
	} else {
		printf("PARENT: reading from pipe\n");
		read(pdfs[0], buf, 5);
		printf("PARENT: read \"%s\"\n", buf);
	}
	return 0;
}