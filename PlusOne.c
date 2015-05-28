int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if (digitsSize==0)
        return digits;
    
    int *result=(int *)malloc((digitsSize+1)*sizeof(int));
    int add=1;
    
    for (int pos = digitsSize-1;pos>=0;pos--){
        result[pos+1]=(digits[pos]+add) % 10;
        add = (digits[pos]+add) / 10;
    }
    result[0]=add;
    if (add == 0){
        *returnSize = digitsSize;
        return &result[1];
    }
    else{
        *returnSize = digitsSize + 1;
        return result;
    }
}