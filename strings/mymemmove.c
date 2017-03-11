

void* mymemmove(void *dst, const void *src, size_t n)
{
	const char *s = src;
	char *d = dst;

	if (s <= d && d < s + n) {	// dst begins at some middle point in src
		s += n, d += n;	// copy from tail
		while (n -- ) {
			*-- d = *-- s;
		}
	} else {	// src begins at some middle point in dst
		while (n -- ) {
			*d ++ = *s ++;
		}
	}
	return dst;
}