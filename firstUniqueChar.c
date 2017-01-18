#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct indexCount{
    int index;
    int count;
} indexCount;


int indexOfFirstUniqueChar(char* str)
{
    indexCount *idxcount = (indexCount *) calloc(256, sizeof(indexCount));
    int i;
    
    int result = INT_MAX;
    
    for (i = 0; str[i] != '\0'; ++i) {
        if (idxcount[str[i]].count == 0) {
            idxcount[str[i]].index = i;
        }
        idxcount[str[i]].count++;
    }
    for (i = 0; i < 256; ++i) {
        if (idxcount[i].count == 1 && result > idxcount[i].index)
            result = idxcount[i].index;
    }
    free(idxcount);
    return result;
}

int main()
{
    char str[] = "geeksforgeeks";
    int index = 0;
    index = indexOfFirstUniqueChar(str);
    
    printf("%d %c \n", index, str[index]);
    return 0;
}