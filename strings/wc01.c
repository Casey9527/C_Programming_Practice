
#include <stdio.h>
#include <ctype.h>

void wc(FILE *f)
{
    int lc, wc, cc;     // line count, word count, char count
    lc = wc = cc = 0;
    
    char c;             // c:  current char
    char c0 = ' ';      // c0: previous char
    while ((c = fgetc(f)) != EOF && c != '\0') {
        cc++;
        
        if (c == '\n') {
            lc++;
        }
        
        if (isspace(c0) && isalpha(c)) {
            wc++;
        }
        c0 = c;
    }
    printf("wc: %d, lc: %d, cc: %d\n", wc, lc, cc);
}

int main(int argc, char* *argv)
{
    // ./a.out filename
    if (argc != 2) {
        printf("Usage: ./a.out filename\n");
        return -1;
    }
    
    char *filename = argv[1];
    FILE *f = fopen(filename, "r");
    
    if (f == NULL) {
        printf("file open error\n");
        return -1;
    }
    
    wc(f);
    return 0;
}


