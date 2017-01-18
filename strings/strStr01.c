
char* mystrStr(char* haystack, char* needle)
{
    char *src = haystack;
    char *dst = needle;
    
    while (*haystack != '\0') {
        if (*dst == '\0') {         /* whole string match */
            return haystack;    
        } else if (*src == '\0') {  /* the source is not long enough  */
            return NULL;
        } else if (*dst == *src) {  /* current character match */
            dst++;
            src++;
        } else {                    /* character not match, backtracking */
            src = ++haystack;
            dst = needle;
        }
    }
    if (*dst == '\0') return haystack;
    else return NULL;
}