
#include <stdio.h>
#include <arpa/inet.h>

int main()
{

unsigned int x = htons(0xFFF9);

printf("x: %x\n", x);
}

