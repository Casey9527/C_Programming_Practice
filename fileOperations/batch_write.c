/*
batch operations on file

*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	int values[3] = {1, 2, 3}, num = 0;
	p_file = fopen("a.bin", "w+b");	// read, write and treat as binary

	if(p_file) {
		num = fwrite(values, sizeof(int), 3, p_file);
		printf("wrote %d int\n", num);

		fclose(p_file);
		p_file = NULL;
	}

}