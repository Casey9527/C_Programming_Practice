/*
batch operations on file

*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	int values[3] = {0}, num = 0;
	p_file = fopen("a.bin", "rb");	// read, write and treat as binary

	if(p_file) {
		num = fread(values, sizeof(int), 3, p_file);
		printf("read %d int: \n", num);

		printf("%d %d %d\n",values[0], values[1], values[2]);
		fclose(p_file);
		p_file = NULL;
	}

}