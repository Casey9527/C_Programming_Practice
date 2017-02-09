/*
** pipe1.c -- a dumb pipe example
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
	int pfds[2];
	char buf[30];
	/*
		pipe() takes an array of two ints as an argument
		it connects two file descriptors and return them
		in the array.
		The first element of the array is the reading-end
		The second is the writing end.
	*/
	if (pipe(pfds) == -1) {
		perror("pipe");
		exit(1);
	}

	printf("writing to file descriptor #%d\n", pfds[1]);
	write(pfds[1], "test", 5);
	printf("reading from file descriptor #%d\n", pfds[0]);
	read(pfds[0], buf, 5);
	printf("read \"%s\"\n", buf);
	return 0;
}