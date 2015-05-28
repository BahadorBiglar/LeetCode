int strStr(char* haystack, char* needle) {
    
    int start, add = 0;
    int hlen = strlen(haystack), nlen = strlen(needle);
    
    if (hlen<nlen)
        return -1;
    
    for (start = 0; start <= (hlen-nlen); start++){
        add = 0;
        while ((add<nlen) && (haystack[start+add] == needle[add]))
            add++;
        if (add==nlen)
            return start;
    }
    return -1;
}