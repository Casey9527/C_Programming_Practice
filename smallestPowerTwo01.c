#include <stdio.h>
#include <math.h>

int main() {
    int x = 17, p, pos;
    pos = ceil(log(x));
    p = pow(2, pos);
    printf("p is %d\n", p);
    return 0;
}