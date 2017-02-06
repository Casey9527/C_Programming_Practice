/*
	rewind()
	reset the position of file pointer to the start

	fseek()
	move the file pointer to any position of the file
	SEEK_SET: the start of file, value 0
	SEEK_CUR: current position, value 1
	SEEK_END: last of file, value 
*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	p_file = fopen("a.txt", "r");	// read, write and treat as binary
	
	char ch = 0;

	if(p_file) {
		fseek(p_file, 6, SEEK_SET);	
		ch = fgetc(p_file);
		printf("%c ", ch);
		
		fseek(p_file, -2, SEEK_END);
		ch = fgetc(p_file);
		printf("%c ", ch);

		fseek(p_file, -3, SEEK_CUR);
		ch = fgetc(p_file);
		printf("%c\n", ch);
		printf("current position of file pointer is: %ld\n", ftell(p_file));
		fclose(p_file);
		p_file = NULL;
	}

}