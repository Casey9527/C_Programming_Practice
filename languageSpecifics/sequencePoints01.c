/**
 *
 * Sequence points in C: 
 * http://www.geeksforgeeks.org/sequence-points-in-c-set-1/
 * 
 * Operators like +, -, *, /, |, & 
 * has undefined evaluation sequences for its operands
 *
 **/

#include <stdio.h>

int fn1()
{
	printf("aaa");
	return 10;
}

int fn2()
{
	printf("111");
	return 15;
}

int fn3()
{
	printf("xyz");
	return 100;
}

void main()
{
	int x = fn1() + fn2() * fn3();
	printf("%d", x);
}

