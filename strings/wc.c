
// 11:32 pm - 

#include <stdio.h>
#include <ctype.h>

void wordcount(FILE *file, int *wc, int *lc, int *cc)
{
    if (!file) {
        return;
    }
    char pre, cur;
    pre = '.';

    while ( (cur = fgetc(file)) != EOF ) {
        if (cur == '\n') {
            *lc += 1;
        }

        (*cc) += 1;

        if (!isalpha(pre) && isalpha(cur)) {
            *wc += 1;
        }
        pre = cur;
    }
}

int main(int ac, char *av[])
{
    if (ac != 2) {
        printf("USAGE: %s filename\n", av[0]);
        return -1;
    }

    FILE *file;

    if ( (file = fopen(av[1], "r")) == NULL) {
        printf("file open failed\n");
        return -1;
    }

    int wc, lc, cc;
    wc = lc = cc = 0;

    wordcount(file, &wc, &lc, &cc);

    printf("wc: %d, lc: %d, cc: %d\n", wc, lc, cc);

    fclose(file);
    return 0;
}