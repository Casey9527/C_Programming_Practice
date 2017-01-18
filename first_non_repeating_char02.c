#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct char_info {
    int index;  // index of first occurance
    int count;  // number of occurances
} char_info;

char_info* get_char_infos(char *s)
{
    char_info* char_infos = (char_info *) calloc(sizeof(char_info), 256);
    
    int i;
    for (i = 0; i < 256; i ++) {
        char_infos[i].index = -1;
    }
    
    i = 0;
    while (*(s + i)) {
        if (char_infos[*(s + i)].index == -1) {
            char_infos[*(s + i)].index = i;
        }
        char_infos[*(s + i)].count ++;
        i ++;
    }
    
    return char_infos;
}

char first_non_repeating_char(char *s)
{
    char_info *char_infos = get_char_infos(s);
    
    int i;
    int ret = INT_MAX;
    
    for (i = 0; i < 256; i ++)
        if (char_infos[i].count == 1)
            if (ret > char_infos[i].index)
                ret = char_infos[i].index;
    
    free(char_infos);
    
    if (ret == INT_MAX)
        return '\0';
    else
        return s[ret];
}

int
main(int ac, char *av[])
{
    printf("%c\n", first_non_repeating_char(av[1]));
    
    return 0;
}