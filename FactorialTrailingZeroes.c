int trailingZeroes(int n) {
    int sum = 0, param = 1220703125; //5^13
    while (param > 1){
        sum+=(n/param);
        param/=5;
    }
    return sum;
}