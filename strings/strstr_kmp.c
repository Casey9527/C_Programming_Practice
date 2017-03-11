// optimize the brute-force solution for strStr() using rabin karp

#include <string.h>
#include <stdio.h>

#define d 256

void rabinkarp_match(char txt[], char pat[], int prime)
{
    int N = strlen(txt);
    int M = strlen(pat);
    
    int p = 0;  // pattern hash
    int t = 0;  // text hash
    int h = 1;
    
    int i, j;
 
    for (i = 0; i < M - 1; i++)
        h = (h*d) % prime;    // h is pow(d, M-1)%prime
    
    // calculate the first window of both strings
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % prime;
        t = (d * t + txt[i]) % prime;
    }
    
    // 
    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            
            if (j == M)
                printf("pattern find at index %d \n", i);
        }
        // calculate hash of next window
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % prime;
            // we might get negative value of t, converting to positive
            if (t < 0)
                t = t + prime;
        }
    }
}

 
/* Driver program to test above function */
int main()
{
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    int q = 101; // A prime number
    rabinkarp_match(txt, pat, q);
    return 0;
}