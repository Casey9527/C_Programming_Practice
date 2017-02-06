#include <stdio.h>

/*
  gcc -shared -fPIC -o dynamicLib.so dynamicLib.c

  -shared: instruts the compiler that we are building a shared library
  -fPIC:   independent code

  signum function definition (mostly come across in signals and systems or DSP)
  = -1 if input is negative
  =  0 if input is zero
  = +1 if input is positive
*/

ssize_t signum(ssize_t input) {
	printf("From shared library, I got input of %li\n", input);
	if ( 0 == input ) {
		return 0;
	}
	return input < 0 ? -1 : 1;
}