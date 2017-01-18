
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    
    char *curLine = NULL;
    int turnover = 0;
    int index = 0;
    size_t len = 0;
    ssize_t read;
    
    while ((read = getline(&curLine, &len, fd)) != -1) {
        if (turnover == 1) {
            free(lines[index]);
        }
        lines[index] = (char *) malloc(strlen(curLine) + 1);
        strcpy(lines[index], curLine);
        index++;
        if (index == n) {
            turnover = 1;
            index = 0;
        }
    }
    free(curLine);
    fclose(fd);
    // print out
    for (i = index; i < n; i++) {
        if (lines[i]) {
            printf("%s", lines[i]);
            free(lines[i]);
        }
    }
    
    for (i = 0; i < index; i++) {
        if (lines[i]) {
            printf("%s", lines[i]);
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



