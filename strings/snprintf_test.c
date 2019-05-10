#include <stdio.h>

int main(void)
{
	char a[10];
	int ret;

	ret = snprintf(a, sizeof(a), "%s", "hellohellooo");

	printf("ret: %d, a: %s\n", ret, a);

	return 0;
}
