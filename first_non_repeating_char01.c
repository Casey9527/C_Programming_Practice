

#include <stdio.h>
#include <stdlib.h>


int* get_count_array(char *s)
{
    int *count = (int *) calloc(sizeof(int), 256);
    
    int i = 0;
    while (*(s + i)) {
        count[*(s + i)] += 1;
        i ++;
    }
    return count;
}

char first_non_repeating_char(char *s)
{
    int *count = get_count_array(s);
    
    char c = '\0';
    
    int i = 0;
    
    while (*(s + i)) {
        if (count[*(s + i)] == 1) {
            c = *(s + i);
            break;
        }
        i ++;
    }
    
    free(count);
    return c;
}

int
main(int ac, char *av[])
{
    printf("%c\n", first_non_repeating_char(av[1]));
    
    return 0;
}