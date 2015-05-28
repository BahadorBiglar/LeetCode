char* convertToTitle(int n) {
    char *s;
    
     s = (char*) malloc (20*sizeof(char));
    //return 'A' + 3;
    while (n>0){
        strcat(s, itoa (i,buffer,10));
        n=(n-1)/26;
    }
    strcat(s,"\0");
    return s;
}