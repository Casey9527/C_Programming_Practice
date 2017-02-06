/*
	fprintf
	
*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	p_file = fopen("d.txt", "w");	// read, write and treat as binary

	if(p_file) {

		fprintf(p_file, "%d:%c:%g \n", 15, 't', 1.8);
		fclose(p_file);
		p_file = NULL;
	}
	return 0;
}