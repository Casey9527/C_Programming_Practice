/*trie.h*/
typedef int trieVal_t;
 
typedef struct trieNode 
{
    char key;
    trieVal_t value;

    struct trieNode *next; 	// Next node at same level
    struct trieNode *prev;	// Previous node at same level
    struct trieNode *children;	// Child node
    struct trieNode *parent;	// Parent node
} trieNode_t;
 
trieNode_t* TrieSearch(trieNode_t *root, const char *key);

trieNode_t *TrieCreateNode(char key, int data);
void TrieAdd(trieNode_t **root, char *key, int data);
void TrieRemove(trieNode_t **root, char *key);
void TrieDestroy(trieNode_t *root);
