
#include <stdio.h>

int main()
{
	printf("0x%x\n", ! (0x80000003 & 0xFFFFFFFC) );
	
	if (-5) {
		printf("if(-5) is true \n");
	}

	if ( !(0x80000003 & 0xFFFFFFFC) ) {
		printf("YES\n");
	}
	return 0;
}