int reverse(int x) {
    int firstDigit, Reverse = 0, sign;
    
    sign = x<0?-1:1;
    x=abs(x);
    
    while (x>0){
        firstDigit = x%10;
        x=x/10;
        
        if ( Reverse>214748364)
            return 0;
        Reverse=Reverse*10+firstDigit;
    }
    return Reverse*sign;
}
