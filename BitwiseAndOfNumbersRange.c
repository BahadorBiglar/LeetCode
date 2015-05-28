int rangeBitwiseAnd(int m, int n) {
    
    int r = m&n;
    if (r==0)
        return r;
    int diff = 1;
    
    while (m<=n-diff){
        r=r&(n-diff);
        diff = diff<<1;
    }
    return r;
}