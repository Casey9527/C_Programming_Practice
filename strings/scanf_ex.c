#include<stdio.h>

int main()
{
	char token[20] = { 0 };
	char c, name[20];
	int i = 0, offset;
	while (scanf("%[a-z]%*[^a-z]", token) == 1) {
		i++;
		if(i%2==0)
			printf("[%s]\n",token );
	}
	return 0;
}

/*

./a.out 
product=c,author=dennis,category=programming,
	[c]
	[dennis]
	[programming]
	Ctrl+D
*/
