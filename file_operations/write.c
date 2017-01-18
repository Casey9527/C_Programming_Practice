/*
	simple example - write file
*/
#include <stdio.h>

int main() {
	FILE *p_file = NULL;	// p_file is a file pointer
	char str[] = "Hello World! NVIDIA AND ME!";
	p_file = fopen("a.txt", "w"); // current folder

	int i = 0;
	if(p_file) {	// if p_file is NULL
		// fputc write a char to file, if fail, return constant EOF
		while(str[i] && (EOF != fputc(str[i], p_file))) {
			i++;
		}

		fclose(p_file);
		p_file = NULL;	// after close the file, clear the file pointer
	}
	return 0;
}

