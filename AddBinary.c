char* addBinary(char* a, char* b) {
    int l1=strlen(a);
    int l2=strlen(b);
    
    char *num1 = (char*) malloc(l1+l2+1);
    char *num2 = (char*) malloc(l1+l2+1);
    
    strcpy(num1, "\0");
    strcpy(num2, num1);
    
    //return num1;
    for (int i = 1; i <= l2-l1; i++)
        strcat(num1, "0\0");
    for (int i = 1; i <= l1-l2; i++)
        strcat(num2, "0\0");
    
    strcat(num1, a);
    strcat(num2, b);

    //strcat(num2, num1);
    //return num2;
    int temp1, cr = 0;
    
    for (int i=strlen(num1)-1; i>=0; i--){
        temp1 = (int) num1[i] + (int) num2[i] + cr - '0' - '0';
        switch(temp1){
            case 0: temp1 = 0; cr = 0; break;
            case 1: temp1 = 1; cr = 0; break;
            case 2: temp1 = 0; cr = 1; break;
            case 3: temp1 = 1; cr = 1; break;
        }
        //printf("%d", temp1);
        //char *s = "  \0";
        //s[0] = (char) temp1;
        //return (char) temp1 - '0';
        switch(temp1){
            case 0: num2[i] = '0'; break;
            case 1: num2[i] = '1'; break;
        }
        //num2[i] = (char) temp1 + '0';
        //printf("num1 = %s, num2 = %s", num1, num2);
        //return num2;
    }
    if (cr==1){
        strcpy(num1, "1\0");
        strcat(num1, num2);
        strcpy(num2, num1);
    }
    
    return num2;
}