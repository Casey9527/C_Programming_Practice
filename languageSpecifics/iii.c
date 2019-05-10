#include <stdio.h>

int main() {

	int x = 0;

	while(x < 10) {
		x = x++;
		printf("x: %d\n", x);
	}

	return 0;
}
