/**
 * memcpy() by 32-bits chunks
 * 
 * Assume both src and dst address are 32-bit aligned
 *
 *
 **/

void* memcpy_aligned_in_32bits_addr(void *dst, const void *src, size_t len)
{
	long *plDst = dst;
	const long *plSrc = src;

	if (!(dst & ~0xFFFFFFFC) && !(src & ~0xFFFFFFFC)) {
		// check both dst and src are aligned in 32-bits
		while (len >= 4) {
			*plDst ++ = *plSrc ++;
			len -= 4;
		}
	}
	char *pcDst = (char *)plDst;
	const char *pcSrc = (const char *)plSrc;

	// copy the remainings
	while (len --) {
		*pcDst ++ = *pcSrc ++;
	}
	
	return dst;
}