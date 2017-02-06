/*
	rewind()
	reset the position of file pointer to the start

*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	p_file = fopen("a.txt", "r");	// read, write and treat as binary
	
	char ch = 0;

	if(p_file) {
		ch = fgetc(p_file);
		printf("%c ", ch);
		rewind(p_file);
		
		ch = fgetc(p_file);
		printf("%c ", ch);
		rewind(p_file);

		ch = fgetc(p_file);
		printf("%c\n", ch);

		fclose(p_file);
		p_file = NULL;
	}

}