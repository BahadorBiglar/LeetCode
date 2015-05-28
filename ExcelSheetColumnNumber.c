int titleToNumber(char* s) {
    int sum = 0;
    for (int i=0; s[i]!='\0';i++)
        sum=((int)s[i]) - 'A' + 1 + (sum * 26);
    return sum;
}