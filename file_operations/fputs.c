/*
	fgets()
	fputs()

*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	p_file = fopen("c.txt", "w+");	// read, write and treat as binary
	
	char ch = 0;
	char read[100] = {0};

	if(p_file) {

		fputs("xyz\n abc", p_file);	// return EOF if fail

		rewind(p_file);
		fgets(read, 7, p_file);
		
		puts(read);

		fclose(p_file);
		p_file = NULL;
	}

}