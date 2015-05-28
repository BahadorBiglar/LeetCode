int climbStairs(int n) {
    if (n<=2)
        return n;
    
    int Solutions[n+1];
    Solutions[0]=0;
    Solutions[1]=1;
    Solutions[2]=2;
    
    for (int i = 3; i<=n; i++)
        Solutions[i]=Solutions[i-1]+Solutions[i-2];
    return Solutions[n];

}