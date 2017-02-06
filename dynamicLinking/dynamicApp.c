/**
 * gcc dynamicApp.c -L /home/kc/c_workspace/ -llibrary -o dynamicApp
 * export LD_LIBRARY_PATH=/home/kc/c_workspace/:$LD_LIBRARY_PATH
 *
 * 
 */
#include <stdio.h>

ssize_t signum(ssize_t input);

int main() {
	ssize_t input = -10;
	printf("signum of (%ld) = %ld\n", input, signum(input));
	return 0;
}
