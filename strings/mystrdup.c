char* mystrdup(char *source)
{
    char *p = (char *) malloc(strlen(source) + 1);
    strcpy(p, source);
    return p;
}