#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1:21 pm - 1:36 pm

/**
 ** leetcode 14 - longest common prefix
 **
 **/

int compare(const void *a, const void *b)
{
    const char *sa = *(char **)a;   // why ?
    const char *sb = *(char **)b;   // when you are qsorting an array of pointers of type char *
                                    // you pass into compare() the address of two char pointers,
    size_t la = strlen(sa);         // which are type char **. They are cast by compare() into void *
    size_t lb = strlen(sb);         // So in your comparator, you should convert it back to char **
                                    // and then you can dereference them.
    return (la > lb) - (la < lb);
}

char* longestCommonPrefix(char** strs, int strsSize) 
{

    if (!strs || strsSize <= 0) {
        return "";
    }

    int i, j;

    for (i = 0; i < strsSize; i ++) {
        if (!strs[i]) {
            return "";
        }
    }
    
    qsort(&strs[0], strsSize, sizeof(char *), compare);

    for (i = 0; i < strlen(strs[0]); i ++) {
        for (j = 1; j < strsSize; j ++) {
            if (strs[0][i] != strs[j][i]) {
                goto end_part;
            }
        }
    }
    end_part: ;
    char *ret = (char *) malloc(i - 0 + 1); //
    ret[i --] = '\0';
    while (i >= 0) {
        ret[i] = strs[0][i];
        i --;
    }
    return ret;
}

void main(void)
{
    char *strs[] = {"", "ac", "ad", "abc"};
    int size = sizeof(strs) / sizeof(strs[0]);

    char *ret = NULL;
    ret = longestCommonPrefix(strs, size);

    printf("ret: %s\n", ret);
}