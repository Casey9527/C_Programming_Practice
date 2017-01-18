/*
	fscanf
	
*/

#include <stdio.h>
int main() {
	FILE *p_file = NULL;
	p_file = fopen("d.txt", "r");	// read, write and treat as binary

	int value = 0;
	char a_char = 0;
	float a_float = 0.0f;

	if(p_file) {

		//fprintf(p_file, "%d %c %g\n", 15, 't', 1.8);
		fscanf(p_file, "%d %c %g", &value, &a_char, &a_float);
		printf("%d %c %g\n", value, a_char, a_float);
		fclose(p_file);
		p_file = NULL;
	}

}