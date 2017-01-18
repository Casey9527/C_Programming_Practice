#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
 
int main(int c, char **v)
{
        while (--c > 1 && !fork());
        sleep(c = atoi(v[c]));
        printf("%d\n", c);
        wait(0);        // equal to "wait(NULL)"
        return 0;
}

// use wait(0) if you don't care what the return value of the child is
// wait(&status) equals to waitpid(-1, &status, 0);
