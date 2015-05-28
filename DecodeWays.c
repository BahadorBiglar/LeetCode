int numDecodings(char* s) {
    if (s[0]=='\0')
        return 0;
    if ((s[0]=='0') && (s[1]=='\0'))
        return 0;
    if (s[1]=='\0')
        return 1;
    if ((s[0]=='0'))
        return 0;
    
    int len = strlen(s);
    int sum[len+1];
    
    sum[len]   = 1;
    if (s[len-1] == '0')
        sum[len-1] = 0;
    else
        sum[len-1] = 1;
    
    for (int pos = len-2; pos>=0; pos--){
        if ((s[pos]=='0'))
            sum[pos] = 0;
        else
            sum[pos] = sum[pos+1];
        if ((s[pos]=='0') || (s[pos]>'2'))
            continue;
        char sub[3];
        sub[0]=s[pos];
        sub[1]=s[pos+1];
        sub[2]='\0';
        if ((atoi(sub)<=26) && (s[pos]!='0'))
            sum [pos] += sum[pos+2];
    }
    
    return sum[0];
    
}