/**
 * gcc -o sample dynamicLink_demo01.c
 *
 * ldd sample
 *
 *	 kc@ubt:c_workspace$ ldd sample 
 *		linux-vdso.so.1 =>  (0x00007ffe53ce1000)
 *		libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fcd77357000)
 *		/lib64/ld-linux-x86-64.so.2 (0x0000557f2ad01000)
 *
 **/
#include <stdio.h>

int main() {
	printf("hello world\n");
	return 0;
}