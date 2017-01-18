/*
 implementations of sizeof operator
 
 mysizeof: support measuring variables and datatype literals
 MYSIZEOF: only support measuring datatype literals

*/


#include <stdio.h>

//#define mysizeof(type) ({typeof(type) _a ; (char *)(&_a+1) -(char*)(&_a);}) 

#define mysizeof(X) \
({ \
	typeof(X) x; \
	(char *) (&x+1) - (char*) (&x); \
})


#define MYSIZEOF(X) (int)((X*)0 +1)

int main() {

	typedef struct {
		int a;
		float b; 
		char c;
	}sample;

	printf("size of struct sample:[%d]\n", mysizeof(sample));// sizeof struct sample
	printf("size of int:[%d]\n", mysizeof(int));
	printf("size of float:[%d]\n", mysizeof(float));
	printf("size of char:[%d]\n", mysizeof(char));
	printf("size of long:[%d]\n", mysizeof(long));
	printf("size of short int:[%d]\n", mysizeof(short int));

	printf("size of struct sample:[%d]\n", MYSIZEOF(sample));// sizeof struct sample
	printf("size of int:[%d]\n", MYSIZEOF(int));
	printf("size of float:[%d]\n", MYSIZEOF(float));
	printf("size of char:[%d]\n", MYSIZEOF(char));
	printf("size of long:[%d]\n", MYSIZEOF(long));
	printf("size of short int:[%d]\n", MYSIZEOF(short int));

	int a;

	printf("%d \n", mysizeof(a));


	return 0;

}