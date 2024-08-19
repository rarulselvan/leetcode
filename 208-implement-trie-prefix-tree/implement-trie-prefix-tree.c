int CHAR_TO_INDEX(char c)
{
    return  ((int)c - (int)'a');
}

struct trieDataStructure
{
	struct trieDataStructure *children[26]; //26 pointers
	bool isLeaf;// isLeaf is true if the node represents end of a word
};
typedef struct trieDataStructure Trie;

Trie* trieCreate()
{
 	int i; 
	Trie *tNode = (Trie *)malloc(sizeof(Trie));
	if(tNode)
	{
		tNode->isLeaf = false;
		for (i = 0; i < 26; i++)
			tNode->children[i] = NULL;
	}
	return tNode;
}

void trieInsert(Trie* root, char* key) 
{
	int length = strlen(key);
	int index;
 
	Trie *pCrawl = root;
 
	for (int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		//Non NULL means the node is present...NULL means need to allocate
		if(pCrawl->children[index]==NULL)
			pCrawl->children[index]=(Trie *)trieCreate();
		
		pCrawl = pCrawl->children[index];
    }
 
	// Mark the last node TRUE ...which means that is a leaf node
	pCrawl->isLeaf = true;
}

bool trieSearch(Trie* root, char* key)
{
    int length = strlen(key);
	int index;
 
	Trie *pCrawl = root;
 
	for (int level = 0; level < length; level++)
	{
		index = CHAR_TO_INDEX(key[level]);
		//Non NULL means the node is present...NULL means need to allocate
		if(pCrawl->children[index])		
		    pCrawl = pCrawl->children[index];
        else
            return false;
    }
    //last char has a valid pointer and  isLeaf==true .....means return true
	return (pCrawl != NULL && pCrawl->isLeaf);
}

bool trieStartsWith(Trie* root, char* prefix) 
{
    Trie *pCrawl = root; 
    // Check if prefix is present and find  the node (of last level) with last character of given string.
    for (int level = 0; level < strlen(prefix); level++)
    {
        int index = CHAR_TO_INDEX(prefix[level]);
        // no string in the Trie has this prefix
        if (!pCrawl->children[index])
            return false;
 		//move to the next char
        pCrawl = pCrawl->children[index];
    }
 
	if (!pCrawl)
        return false;//nothing found
    else
        return true;
}

void trieFree(Trie* root) 
{
    if(root)
    {
        Trie *pCrawl = root;
        for(int i=0; i<26;i++)
        if(pCrawl->children[i])	
            trieFree(pCrawl->children[i]);
        free(root);
    }
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);
 
 * bool param_2 = trieSearch(obj, word);
 
 * bool param_3 = trieStartsWith(obj, prefix);
 
 * trieFree(obj);
*/