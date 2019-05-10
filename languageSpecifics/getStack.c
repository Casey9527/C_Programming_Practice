#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#define MAX_LEVEL 4
void sigfunc(int signo)
{
	printf("%s(0): %p\n", __func__, __builtin_return_address(0));
	exit(1);
}

int b()
{
	printf("%s(0): %p\n", __func__, __builtin_return_address(0));
	printf("%s(1): %p\n", __func__, __builtin_return_address(1));
	while(1) {
		sleep(1);
	}
}

int a(int temp)
{
	temp += 1;
	printf("%s(0): %p\n", __func__, __builtin_return_address(0));

	b();

	return temp;
}

int main()
{
	signal(SIGINT, sigfunc);
	a(123);

	return 0;
}
/*

kexinc@c_test$ gcc -g getStack.c -o getStack
kexinc@c_test$ ./getStack
a(0): 0x4006c6
b(0): 0x4006a4
b(1): 0x4006c6
^Csigfunc(0): 0x7fe0e3a0e4b0

kexinc@c_test$ gdb e
(gdb) file getStack
Reading symbols from getStack...done.
(gdb) l *0x4006c6
0x4006c6 is in main (getStack.c:37).
32	int main()
33	{
34		signal(SIGINT, sigfunc);
35		a(123);
36	
37		return 0;
38	}
(gdb) l *0x4006a4
0x4006a4 is in a (getStack.c:29).
24		temp += 1;
25		printf("%s(0): %p\n", __func__, __builtin_return_address(0));
26	
27		b();
28	
29		return temp;
30	}
31	
32	int main()
33{
(gdb)

*/
