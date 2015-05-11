struct TrieNode {
    char letter;
    bool isLeaf;
    struct TrieNode* next[26];
};

/** Initialize your data structure here. */
struct TrieNode* trieCreate() {
    struct TrieNode* newNode = (struct TrieNode* )malloc(sizeof(struct TrieNode));
    newNode->letter='\0';
    newNode->isLeaf=false;
    
    for (int i = 0; i<26; i++)
        newNode->next[i]=NULL;
    
    return newNode;
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
    if (word[0]=='\0')
        return;
    
    if (root==NULL)
        return;
    
    struct TrieNode* curr=root;
    
    for (int pos=0; word[pos]!='\0';pos++){
        if (curr->next[word[pos]-'a']==NULL){
            struct TrieNode* newNode = trieCreate();
            newNode->letter = word[pos];
            curr->next[word[pos]-'a'] = newNode;
        }
        curr = curr->next[word[pos]-'a'];
    }
    
    curr->isLeaf = true;
    return;
}

/** Returns if the word is in the trie. */
bool search(struct TrieNode* root, char* word) {
    if (!root)
        return false;
    
    struct TrieNode* curr=root;
    int pos;
    for(pos=0;word[pos]!='\0';pos++)
        if (curr->next[word[pos]-'a']==NULL)
            return false;
        else
            curr = curr->next[word[pos]-'a'];
    if (curr->isLeaf)
        return true;
    return false;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */
bool startsWith(struct TrieNode* root, char* prefix) {
    if (!root)
        return false;
    
    struct TrieNode* curr=root;
    int pos;
    for(pos=0;prefix[pos]!='\0';pos++)
        if (curr->next[prefix[pos]-'a']==NULL)
            return false;
        else
            curr = curr->next[prefix[pos]-'a'];
    return true;
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
    for (int i = 0; i<26; i++)
        if (root->next[i])
            trieFree(root->next[i]);
    free(root);
}
