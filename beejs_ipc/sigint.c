/*
** sigint.c -- grab SIGINT
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void sigint_handler(int sig) {
	/*
		why not use 'printf()'
		because 'write' is async-safe
		we should make sure the function
		inside the handler is async-safe
	*/
	write(0, "Ahhh! SIGINT!\n", 14);
}

int main(void) {
	void sigint_handler(int sig);
	char s[200];
	struct sigaction sa;
	sa.sa_handler = sigint_handler;
	sa.sa_flags = SA_RESTART;	
	/*
	restart:
		if (some_system_call() == -1) {
			if (errno == EINTR) goto restart;
			perror("some_system_call");
			exit(1);
		}
	*/
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGINT, &sa, NULL) == -1) {
		perror("sigaction");
		exit(1);
	}
	printf("Enter a string: \n");
	if (fgets(s, sizeof s, stdin) == NULL)
		perror("fgets");
	else
		printf("You entered %s\n", s);
	return 0;
}