
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int count_word(char *str, char *word, int offset)
{
    char *p;
    int count = 0;
    
    p = strstr(str, word);
    assert(p != NULL);

    if (p - str < offset) {
        return -1;      // means this word has searched before
    }

    while (p != NULL) {
        count++;
        p = strstr(p + 1, word);
    }
    return count;
}

void show_all_words(char *str)
{
    char *str_rw = strdup(str);
    assert(str_rw != NULL);
    char delimiters[] = " .,;:!-?";
    // delimiters: space and punctuations
    char *next_word = strtok(str_rw, delimiters); 
    int offset, count;
    while (next_word != NULL) {
        offset = next_word - str_rw;
        count = count_word(str, next_word, offset);
        if (count != -1)    // avoid duplicate counting
            printf("%s: %d\n", next_word, count);
        next_word = strtok(NULL, delimiters);
    }
    free(str_rw);
}

int main()
{
    char str[] = " . ! , ; kexin ; chen ; kexin chen xiao yuan yuan yu zi yuan";
    show_all_words(str);
    return 0;
}