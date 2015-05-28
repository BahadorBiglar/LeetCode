double myPow(double x, int n) {
    if (n==0)
        return 1.0;
    if (x==1.0)
        return 1.0;
    int r = n & 1;
    if (x==-1.0 && r == 1)
        return (-1.0);
    if (x==-1.0 && r == 0)
        return (1.0);
    if (n0)
        return (1myPow(x, -1n));
    
    double f = (r == 1)  x  1.0;
    double x1 = myPow(x, n2);
    
    return (x1x1f);

}