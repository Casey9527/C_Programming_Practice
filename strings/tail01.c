
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE (256)


#if 0

char* getOneLine(FILE *fd)
{
    int count = 0;
    char c;
    char *s = (char *) malloc(MAX_LINE_SIZE + 1);
    
    while ((c = fgetc(fd)) != EOF) {
        if (c == '\n') {
            *(s + count) = '\0';
            return s;
        } else if (count + 1 > MAX_LINE_SIZE) {
            continue;
        } else {
            *(s + count) = c;
            count++;
        }
    }
    
    if (count == 0) {
        return NULL;
    } else {
        *(s + count) = '\0';
        return s;
    }
}

#endif


#if 1
char* getOneLine(FILE *fd)
{
    int count = 0;
    char c;
    char *s = (char *) malloc(sizeof(char) * MAX_LINE_SIZE + 1);
    
    while ((c = fgetc(fd)) != EOF) {
        if (c == '\n' || count + 1 > MAX_LINE_SIZE) {
            break;
        } else {
            *(s + count) = c;
            count++;
        }
    }
    
    if (count == 0 && c == EOF) {
        return NULL;
    } else {
        *(s + count) = '\0';
        return s;
    }
}
#endif

void printLastNLines(char *file, int n)
{
    if (n <= 0) return;
    
    FILE *fd;
    if ((fd = fopen(file, "r")) == NULL) {
        return;
    }

    char *lines[n];
    
    int i;
    for (i = 0; i < n; ++i)
        lines[i] = NULL;
    
    char *curLine;
    int turnover = 0;
    int nlines = n;
    int index = 0;
    
    while ((curLine = getOneLine(fd)) != NULL) {
        int curSize = strlen(curLine);
        if (turnover == 1) {
            free(lines[index]);
        }
        lines[index] = (char *) malloc(curSize + 1);
        strcpy(lines[index], curLine);
        index++;
        if (index == n) {
            turnover = 1;
            index = 0;
        }
    }
    
    // print out
    for (i = index; i < n; i++) {
        if (lines[i]) {
            printf("%s\n", lines[i]);
            free(lines[i]);
        }
    }
    
    for (i = 0; i < index; i++) {
        if (lines[i]) {
            printf("%s\n", lines[i]);
            free(lines[i]);
        }        
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("USAGE: ./a.out filename nlines\n");
        return;
    }
    
    printLastNLines(argv[1], atoi(argv[2]));
    
    return 0;
}



