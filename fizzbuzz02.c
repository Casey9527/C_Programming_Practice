#include <stdio.h>
int main()
{   int i;
    for (i = 1; i <= 105; ++i)
        if (i % 3 && i % 5)
            printf("%d", i);
        else
            printf("%s%s%s", i%3? "":"Fizz", i%5? "":"Buzz", i%15? "":"\n");
    return 0;
}