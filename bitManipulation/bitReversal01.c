
// 32-bit
void bitReversal(int n)
{
    // reverse odd and even bits
    n = ((n & 0xaaaaaaaa) >> 1 ) | ((n & 0x55555555) << 1);
    // reverse pairs
    n = ((n & 0xcccccccc) >> 2 ) | ((n & 0x33333333) << 2);
    // reverse nibbles
    n = ((n & 0xf0f0f0f0) >> 4 ) | ((n & 0x0f0f0f0f) << 4);
    // reverse bytes
    n = ((n & 0xff00ff00) >> 8 ) | ((n & 0x00ff00ff) << 8);
    // reverse half-words
    // n = ((n & 0xffff0000) >> 16) | ((n & 0x0000ffff) << 16);
    n = (n >> 16) | (n << 16);
    return n;
}