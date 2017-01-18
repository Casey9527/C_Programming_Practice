
#include <stdio.h>
#include <stdlib.h>

int isBegin(char c1, char c2) {
    if (c1 == '/' && c2 == '/') {
        return 1;
    } else if (c1 == '/' && c2 == '*') {
        return 2;
    }
    return 0;
}

int isSpace(char c) {
    if (c == ' ' || c == '\r' || c == '\t' || c == '\n')
        return 1;
    return 0;
}

int isEnd(char c1, char c2, int commentType) {
    if (c1 == '*' && c2 == '/' && commentType == 2) {
        return 1;
    } else if (c1 != '\n' && c2 == '\n' && commentType == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int inComment = 0;      // 0, the cur pos is not in comment
    int commentType = 0;    // 0, not a comment; 1, // comment; 2, /* comment
    char c1, c2;
    
    FILE *fdr;
    fdr = fopen("extract_test.c", "r");
    
    while ((c1 = fgetc(fdr)) != EOF) {
        if ((c2 = fgetc(fdr)) == EOF) {
            break;
        }
        if (!inComment) {
            commentType = isBegin(c1, c2);
            if (commentType) {
                inComment = 1;
                fputc(c1, stdout);
            }
        } else {
            while (c1 == '\n' && isSpace(c2)) {
                c2 = fgetc(fdr);
            }
            fputc(c1, stdout);
            if (isEnd(c1, c2, commentType)) {
                inComment = 0;
                fputc(c2, stdout);
                if (commentType == 2) {
                    fputc('\n', stdout);
                }
            }
        }
        fseek(fdr, -1, SEEK_CUR);
    }
    fclose(fdr);
    return 0;
}