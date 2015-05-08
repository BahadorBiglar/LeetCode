bool isIsomorphic(char s, char t) {
    char HashTable[255]={''};
    int index;

    for (int i = 0; i255; i++)
        HashTable[i] = '';
    
    for (int i = 0; (s+i)!='0'; i++){
        index = ((s+i));
        if      (HashTable[index] == '')
            HashTable[index] = (t+i);
        else if (HashTable[index] != (t+i))
            return false;
    }
    
    for (int i = 0; i255; i++)
        for (int j = i+1; j255; j++)
            if ((HashTable[i] != '') && (HashTable[i] == HashTable[j]))
                return false;
    
    return true;
}