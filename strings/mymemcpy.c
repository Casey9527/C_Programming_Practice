

void* mymemcpy(void *dst, const void *src, size_t n)
{
	const char *s = src;
	char *d = dst;

	while (n --) {
		*d ++ = *s ++;
	}
	return dst;
}