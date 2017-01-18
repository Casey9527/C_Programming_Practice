/*
 * The following description is from Linux Programmer's Manual (strtok(3)):
 *
 * #include <string.h>
 * char *strtok(char *str, const char *delim);
 *
 * The  strtok() function breaks a string into a sequence of zero or more
 * nonempty tokens.  On the first call to strtok() the string to be parsed
 * should be specified in str. In each subsequent call that should parse
 * the same string, str must be NULL.
 *
 * The delim argument specifies a set of bytes that delimit the tokens in
 * the parsed string.  The caller may specify different strings in  delim
 * in  successive  calls  that parse the same string.
 *
 * Each  call  to strtok() returns a pointer to a null-terminated string
 * containing the next token.  This string does not include the delimiting
 * byte.  If no more tokens are found, strtok() returns NULL.
 */
 
#include <stdio.h>
#include <string.h>
 
int main() {
    char msg[] = "Lorem ipsum dolor sit/amet, consectetur adipiscing elit.";
    char *word;
    
    word = strtok(msg, ";");
    printf("1 %s\n", word);
    
    word = strtok(NULL, "/");
    printf("2 %s\n", word);
    
    while ((word = strtok(NULL, " ")) != NULL)
        printf("%s\n", word);

    return 0;
}
 
 
 
 