
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE (256)

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

int main(int argc, char **argv) {
    if (argc != 2) {
       printf("USAGE:./a.out filename\n");
       return;
    }
    
    FILE *fd;
    fd = fopen(argv[1], "r");
    
    char *s;
    
    s = getOneLine(fd);    
    printf("%s\n", s);
    s = getOneLine(fd);    
    printf("%s\n", s);
    
    fclose(fd);
    return 0;
}

/*
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
    
*/    