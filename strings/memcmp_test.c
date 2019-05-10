#include <string.h>
#include <stdio.h>

struct conn_v4_l3l4 {
	char protocol;			/* Protocol */
	char reserved[3];
	unsigned int ip[2];		/* IP */
	unsigned int ident[2];		/* Port */
};

int main(void)
{
	struct conn_v4_l3l4 c1, c2;
	char *p1, *p2;
	int len, i;

	c1.protocol = 8;
	c1.ip[0] = 0xC0A801D2;
	c1.ip[1] = 0xC0A80164;
	c1.ident[0] = 64296;
	c1.ident[1] = 5001;

	c2.protocol = 8;
	c2.ip[0] = 0xC0A801D2;
	c2.ip[1] = 0xC0A80164;
	c2.ident[0] = 64296;
	c2.ident[1] = 5001;

	len = (int)sizeof(struct conn_v4_l3l4);
	printf("sizeof(struct conn_v4_l3l4): %d\n", len);

	if (memcmp(&c1, &c2, sizeof(struct conn_v4_l3l4)))
		printf("struct is not equal\n");
	else
		printf("struct is  equal\n");


	/* Inspect every byte of struct */
	p1 = (char *)&c1;
	p2 = (char *)&c2;

	for (i = 0; i < len; i++)
		printf("Byte #%2d: 0x%16x  -  0x%16x\n", i, *p1++, *p2++);

	return 0;
}
