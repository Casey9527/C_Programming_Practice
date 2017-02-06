/*
	simple example of file operations
*/
#include <stdio.h>

int main() {
	FILE *p_file = NULL;	// p_file is a file pointer

	p_file = fopen("a.txt", "w"); // current folder

	if(p_file) {	// if p_file is NULL
		fclose(p_file);
		p_file = NULL;	// after close the file, clear the file pointer
	}
	return 0;
}

