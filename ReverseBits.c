uint32_t reverseBits(uint32_t n) {
    uint32_t r, sum =0;
    uint32_t base = 1024 * 1024 * 1024 * 2; // 2^32
    while (n > 0)
    {
        r = n & 1;
        sum = sum + r * base;
        base =  base >> 1;
        n = n >> 1;
    }
    return sum;
}