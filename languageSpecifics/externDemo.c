#include <stdio.h>

void foo();
void goo();
/*
 * static variable inside a function:
 * - scope
 * - lifetime
 *
 */

int main()
{
	foo();
	foo();
	return 0;
}

void foo()
{
	// with static keyword, a is initialized to 5 only once
	static int a = 5;	
	a ++;
	printf("foo() is called, a = %d\n", a);
}


/*

// the scope of a is limited inside foo()

void goo()
{
	extern int a;
	a += 2;
	printf("goo() is called, a = %d\n", a);
}
*/