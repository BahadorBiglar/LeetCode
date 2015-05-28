int numTrees(int n) {
    if (n==0)
        return 0;
    
    int posCount[n+1];
    posCount[0]=1;
    posCount[1]=1;
    
    for(int i=2; i<=n; i++){
        posCount[i]=0;
        for(int j=1; j<=i; j++){
            posCount[i]+=posCount[i-j]*posCount[j-1];
        }
    }
    
    return posCount[n];
}