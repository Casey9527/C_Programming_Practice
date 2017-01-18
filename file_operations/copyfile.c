/*
	copy content of one file to another file
*/
#include <stdio.h>

int main() {
	FILE *p_src = NULL, *p_des = NULL;
	p_src = fopen("a.txt", "r"); // current folder

	int i = 0;
	char ch = 0;

	if(p_src) {
		p_des = fopen("b.txt", "w");
		
		if(p_des) {
			while (EOF != ch) {
				ch = fgetc(p_src);
				if(EOF != ch) {
					fputc(ch, p_des);
				}
			}
			fclose(p_des);
			p_des = NULL;
		}
		fclose(p_src);
		p_src = NULL;	// after close the file, clear the file pointer
	}
	return 0;
}

