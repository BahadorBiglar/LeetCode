int hammingWeight(uint32_t n) {
    int r, sum =0;
    while (n > 0)
    {
        r = n & 1;
        sum += r;
        n = n >> 1;
    }
    return sum;
}