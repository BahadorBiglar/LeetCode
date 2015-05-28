int countPrimes(int n) {
    if (n<=2)
        return 0;
    if (n==3)
        return 1;
    int prime[n/10+1000];
    bool is_prime;
    int lastone=2;
    
    prime[0]=2;
    prime[1]=3;

    for (int i=4; i<n; i++){
        is_prime = true;
        for (int j=0; (j<lastone) && (prime[j]<=1+sqrt(i)); j++)
            if ((i%prime[j]) == 0){
                is_prime = false;
                break;
            }
        if (is_prime){
            prime[lastone]=i;
            lastone++;
        }
    }
    return lastone;
}