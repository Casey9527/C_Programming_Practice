#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (a > b) ? a : b


int
length_longest_substr(char *s)
{
    int i = 0, j = 0, ans;
    int n = strlen(s);
    // create a hash table
    int *hash = (int *) malloc(sizeof(int) * 256);
    
    int k;
    for (k = 0; k < 256; k ++)
        hash[k] = -1;
    
    while (i < n && j < n) {
        if (hash[s[j]] != -1) {
            i = max(hash[s[j]] + 1, i);
        }
        
        ans = max(ans, j - i + 1);
        
        hash[s[j]] = j;
        
        j++;
    }
    free(hash);
    return ans;
}

int
main(int ac, char *av[])
{
    int i;
    for (i = 1; i < ac; i ++)
        fprintf(stdout, "%s : %d\n", av[i], length_longest_substr(av[i]));
        //printf("%s: %d\n", av[i], length_longest_substr(av[i]));
        
    return 0;
}