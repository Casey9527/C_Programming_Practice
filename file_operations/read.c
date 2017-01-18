/*
	simple example - read file
*/
#include <stdio.h>

int main() {
	FILE *p_file = NULL;	// p_file is a file pointer
	p_file = fopen("a.txt", "r"); // current folder

	int i = 0;
	char ch = 0;

	if(p_file) {	// if p_file is NULL
		// 
		while((ch = fgetc(p_file)) != EOF) {
				printf("%c", ch);
		}
		printf("\n");
		fclose(p_file);
		p_file = NULL;	// after close the file, clear the file pointer
	}
	return 0;
}

