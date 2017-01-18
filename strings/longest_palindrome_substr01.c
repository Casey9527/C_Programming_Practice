#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longest_pal_substr( char *str )
{
    int len = strlen(str);
    
    // dp[i][j] returns 0 if str[i..j] is not palindrome, otherwise, 1
    char dp[len][len];
    memset(dp, 0, sizeof(dp));
    
    int max_len = 1;

    int l, i, j;
    
    int start = 0;
    
    for (l = 0; l < len; l ++) {
        for (i = 0; i < len - l; i ++) {
            j = i + l;
            // j - i <= 2 is for (0, 0), (0, 1), (0, 2) etc.
            if (str[i] == str[j] && (j - i <= 2 || dp[i + 1][j - 1] == 1)) {
                
                dp[i][j] = 1;
                
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                    start = i;
                }
            }
        }
    }
    
    for (i = start; i <= start + max_len - 1; i ++)
        printf("%c", str[i]);
    printf("\n");
    
    return max_len;
    
}

int main()
{
    char str[] = "forgeeksskeegfor";
    printf("\nLength is: %d\n", longest_pal_substr( str ) );
    return 0;
}