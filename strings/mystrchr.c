
/**
 * find the first occurance of char @c in string @s
 * return NULL if there is no @c
 *
 **/

char* mystrchr(const char *s, char c)
{
	while (*s != '\0') {
		if (*s == c) {
			return (char *)s;
		}
		s ++;
	}
	return NULL;
}