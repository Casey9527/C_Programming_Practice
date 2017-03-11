/*

 implementations of sizeof operator
 
 MYSIZEOF_1: accept type
 MYSIZEOF_2: accept type and var
 MYSIZEOF_3: accept type and var

*/


#include <stdio.h>

#define MYSIZEOF_1(type) ( (size_t)((type *)0 + 1) ) 

#define MYSIZEOF_2(var) ( (size_t)((typeof(var) *)0 + 1) )

#define MYSIZEOF_3(X) \
	    ({ \
			typeof(X) x; \
			(char *) (&x+1) - (char*) (&x); \
		})

int main() {

	typedef struct {
		int a;
		float b; 
		char c;
	}sample;

	printf("size of struct sample:[%d]\n", MYSIZEOF_1(sample));// sizeof struct sample
	printf("size of int:[%d]\n", MYSIZEOF_1(int));
	printf("size of float:[%d]\n", MYSIZEOF_1(float));
	printf("size of char:[%d]\n", MYSIZEOF_1(char));
	printf("size of long:[%d]\n", MYSIZEOF_1(long));
	printf("size of short int:[%d]\n", MYSIZEOF_1(short int));

	printf("size of struct sample:[%d]\n", MYSIZEOF_2(sample));// sizeof struct sample
	printf("size of int:[%d]\n", MYSIZEOF_2(int));
	printf("size of float:[%d]\n", MYSIZEOF_2(float));
	printf("size of char:[%d]\n", MYSIZEOF_3(char));
	printf("size of long:[%d]\n", MYSIZEOF_3(long));
	printf("size of short int:[%d]\n", MYSIZEOF_3(short int));

	int a;

	printf("%d \n", MYSIZEOF_2(a));


	return 0;

}