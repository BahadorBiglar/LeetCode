int RepeatingPos(char *s, int start, int end){
    for (int i = start; i<end; i++)
        if (s[i] == s[end])
                return i;
    return -1;
}
int lengthOfLongestSubstring(char* s) {
    if (s[0]=='\0')
        return 0;
    int start, end, pos, max = 1;
    end = 1;
    for (start = 0; s[end]!='\0'; ){
        pos = RepeatingPos(s, start, end);
        if (pos > -1){
            max = (max<(end-start) ? (end-start):max);
            start = pos+1;
        }
        end++;
    }
    max = (max<(end-start) ? (end-start):max);
    return max;
}