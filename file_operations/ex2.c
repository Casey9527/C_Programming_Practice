#include <stdio.h>

int main() {
	FILE *fp;

	fp = fopen("a.txt", "r+");
	fprintf(fp, "test printf by ex2....................................\n" );
	fprintf(fp, "test printf by ex2....................................\n" );

	fclose(fp);
	return 0;
}