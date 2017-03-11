/**
 * memcpy() by 32-bits chunks
 * 
 * Assume destination buffer is aligned on a 32-bit address
 *        source buffer is 8 bits off the alignment
 *
 **/
// todo: unfinished
// http://www.danielvik.com/2010/02/fast-memcpy-in-c.html
void* memcpy_aligned_in_32bits_addr(void *dst, const void *src, size_t len)
{
	long srcWord, dstWord;
	srcWord = *src32 ++;

	while (len --) {
		dstWord = srcWord << 8;

	}


}
