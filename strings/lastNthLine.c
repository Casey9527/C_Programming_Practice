/*
Usage: ./a.out line_no

e.g. 10 lines in total, 

line_no <= 0:

1 =< line_no <= 10: 

line_no > 10: return the first line


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH (256)

char *getOneLine(FILE *fd)
{
    char *result = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH + 1);
    char c;
    int i = 0;
    
    while ((c = fgetc(fd)) != EOF) {
        if (c == '\n' || (i + 1) > MAX_LINE_LENGTH) {
            break;
        }
        *(result + i) = c;
        i++;
    }
    
    if (i == 0 && c == EOF) {
        free(result);
        return NULL;
    } else {
        *(result + i) = '\0';
        return result;
    }
}

char *getLastNthLine(char *filename, int nlines)
{
    if (nlines <= 0) return NULL;
    
    FILE *fd = fopen(filename, "r");

    char* *lines = (char **) malloc(sizeof(char *) * nlines);
    int index, turnover, output, i;
    output = index = turnover = 0;
    
    char *current, *result;
    
    while ((current = getOneLine(fd)) != NULL) {
        //printf("%s\n", current);
        if (turnover == 1) {
            free(lines[index]);
        }
        lines[index] = (char *) malloc(strlen(current) + 1);
        strcpy(lines[index], current);
        //printf("index: %d\n%s\n", index, lines[index]);
        index++;
        if (index == nlines) {
            turnover = 1;
            index = 0;
        }
    }
    if (!turnover)
        output = 0;
    else
        output = index % nlines;
    
    for (i = 0; i < nlines; ++i)
        if (i != output)
            free(lines[i]);
        
    result = lines[output];
    free(lines);
    fclose(fd);
    return result;
}

// 1 2 3 4 5 6 7 8 9 10
// 1 2 3 4 5 
// 6 7 8 9 10

// 1 2 3 4 5 6 7
// 6 7 3 4 5

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: ./a.out filename line_no\n");
        return 0;
    }
    char *str;
    str = getLastNthLine(argv[1], atoi(argv[2]));
    if (str != NULL)
        printf("%s\n", str);
    return 0;
}


/*
char *getOneLine(FILE *fd)
{
    char *result = (char *) malloc(sizeof(char) * MAX_LINE_LENGTH + 1);
    char c;
    int i = 0;
    
    while ((c = fgetc(fd)) != EOF) {
        if (c == '\n' || (i + 1) > MAX_LINE_LENGTH) {
            *(result + i) = '\0';
            break;
        }
        *(result + i) = c;
        i++;
    }
    
    if (c == EOF) {           
        if (i == 0) return NULL;
        else *(result + i) = '\0';
    }
    return result;
}

*/