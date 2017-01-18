

// 32-bit unsigned int
unsigned convert_endian_32(unsigned x) {
    unsigned swapped;
    swapped = (x >> 24 | 0xff      ) |
              (x >> 8  | 0xff00    ) |
              (x << 8  | 0xff0000  ) |
              (x << 24 | 0xff000000);
}

