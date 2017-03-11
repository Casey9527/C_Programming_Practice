void* mymemset(void *s, char c, size_t n)
{
	char *p = s;
	while (n --) {
		*p ++ = c;
	}
	return s;
}