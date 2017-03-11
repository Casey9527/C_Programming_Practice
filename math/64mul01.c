
#include <stdio.h>
#include <stdint.h>

int main()
{
    uint32_t result[4] = {0};
    uint32_t ah = 0xfffeffff;
    uint32_t al = 0xffffffff;
    uint32_t bh = 0xffff0001;
    uint32_t bl = 0xffffffff;

    uint64_t temp0, temp1;
    
    temp0 = (uint64_t) bl * (uint64_t) al;
    temp1 = (uint64_t) bl * (uint64_t) ah;
    temp2 = (uint64_t) bh * (uint64_t) al;
    temp3 = (uint64_t) bh * (uint64_t) ah;
    
    result[0] = (uint32_t) (temp0 & 0xffffffff);

    temp4 = temp1 & 0xffffffff + temp0 >> 32;
    

    int i;
    for (i = 0; i < 4; ++i) {
        printf("result[%d]: 0x%x\n", i, result[i]);
    }
    
    return 0;
}