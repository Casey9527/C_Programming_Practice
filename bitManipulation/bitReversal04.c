

unsigned int reverseBits(unsigned int n)
{
    int reverse_num = 0;
    int i;
    for (i = 0; i < 32; i++) {
        if (num & (1 << i))
            reverse_num |= 1 << ((32 - 1) - i);
    }
    return reverse_num;
}