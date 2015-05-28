struct WordDictionary {
    char letter;
    bool isLeaf;
    struct WordDictionary* next[26];
};

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    struct WordDictionary* newNode = (struct WordDictionary* )malloc(sizeof(struct WordDictionary));
    
    newNode->letter='\0';
    newNode->isLeaf=false;
    
    for (int i = 0; i<26; i++)
        newNode->next[i]=NULL;
    
    return newNode;
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    if (word[0]=='\0')
        return;
    
    if (wordDictionary==NULL)
        return;
    
    struct WordDictionary* curr=wordDictionary;
    
    for (int pos=0; word[pos]!='\0';pos++){
        if (curr->next[word[pos]-'a']==NULL){
            struct WordDictionary* newNode = wordDictionaryCreate();
            newNode->letter = word[pos];
            curr->next[word[pos]-'a'] = newNode;
        }
        curr = curr->next[word[pos]-'a'];
    }
    
    curr->isLeaf = true;
    return;
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */
bool search(struct WordDictionary* wordDictionary, char* word) {
    if (!wordDictionary)
        return false;
    
    if ((word[0]=='\0') && (wordDictionary->isLeaf))
        return true;
    else if ((word[0]=='\0') && (!wordDictionary->isLeaf))
        return false;
    
    if (word[0]=='.'){
        for(int nextLetter=0; nextLetter<26; nextLetter++){
            if (search(wordDictionary->next[nextLetter], (word+1)))
                return true;
        }
        return false;
    }
    else
        return (search(wordDictionary->next[word[0]-'a'], (word+1)));
}

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    for (int i = 0; i<26; i++)
        if (wordDictionary->next[i])
            wordDictionaryFree(wordDictionary->next[i]);
    free(wordDictionary);
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);
