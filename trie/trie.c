// http://simplestcodings.blogspot.com/2012/11/trie-implementation-in-c.html

/*trie.c*/
#include <stdio.h>
#include "trie.h"
#include <stdlib.h>
#define DEBUGx
 
trieNode_t *TrieCreateNode(char key, int data)
{
    trieNode_t *node = NULL;
    node = (trieNode_t *)malloc(sizeof(trieNode_t));
 
    if(NULL == node)
    {
        printf("Malloc failed\n");
        return node;
    }
 
    node->key = key;
    node->next = NULL;
    node->children = NULL;
    node->value = data;
    node->parent= NULL;
    node->prev= NULL;
    return node;
}
 
void TrieAdd(trieNode_t **root, char *key, int data)
{
    trieNode_t *pTrav = NULL;
 
    if(NULL == *root)
    {
        printf("NULL tree\n");
        return;
    }
#ifdef DEBUG
    printf("\nInserting key %s: \n",key);
#endif
    pTrav = (*root)->children;
 
    if(TrieSearch(pTrav, key))
    {
        printf("Duplicate!\n");
        return;
    }
 
    if(pTrav == NULL)
    {
        /*First Node*/
        for(pTrav = *root; *key; pTrav = pTrav->children)
        {
            pTrav->children = TrieCreateNode(*key, 0xffffffff);
            pTrav->children->parent = pTrav;
#ifdef DEBUG
            printf("Inserting: %c\n",pTrav->children->key);
#endif
            key++;
        }
 
        pTrav->children = TrieCreateNode('\0', data);
        pTrav->children->parent = pTrav;
#ifdef DEBUG
        printf("Inserting: %c\n",pTrav->children->key);
#endif
        return;
    }
 
    while(*key != '\0')
    {
        if(*key == pTrav->key)
        {
            key++;
#ifdef DEBUG
            printf("Traversing child: %c\n",pTrav->children->key);
#endif
            pTrav = pTrav->children;
        }
        else
            break;
    }
 
    while(pTrav->next)
    {
        if(*key == pTrav->next->key)
        {
            key++;
            TrieAdd(&(pTrav->next), key, data);
            return;
        }
        pTrav = pTrav->next;
    }
    
    if (*key)
    {
        pTrav->next = TrieCreateNode(*key, 0xffffffff);
    }
    else
    {
        pTrav->next = TrieCreateNode(*key, data);
    }
    pTrav->next->parent = pTrav->parent;
    pTrav->next->prev = pTrav;
 
#ifdef DEBUG
    printf("Inserting %c as neighbour of %c \n",pTrav->next->key, pTrav->key);
#endif
    
    if (!(*key))
        return;
 
    key++;
 
    for(pTrav = pTrav->next; *key; pTrav = pTrav->children)
    {
        pTrav->children = TrieCreateNode(*key, 0xffffffff);
        pTrav->children->parent = pTrav;
#ifdef DEBUG
        printf("Inserting: %c\n",pTrav->children->key);
#endif
        key++;
    }
 
    pTrav->children = TrieCreateNode('\0', data);
    pTrav->children->parent = pTrav;
#ifdef DEBUG
    printf("Inserting: %c\n",pTrav->children->key);
#endif
    return;
}
 

/* ================================================
   TrieSearch(root, key):

        Find string "key" in trie root
   ================================================ */
trieNode_t* TrieSearch(trieNode_t *root, const char *key)
{
    trieNode_t *level = root;
    trieNode_t *pPtr = NULL;
 
    int lvl=0;
    while(1)
    {
        trieNode_t *found = NULL;
        trieNode_t *curr;
 
        for (curr = level; curr != NULL; curr = curr->next)
        {
            if (curr->key == *key)
            {
                found = curr;
                lvl++;
                break;
            }
        }
 
        if (found == NULL)
            return NULL;
 
        if (*key == '\0')
        {
            pPtr = curr;
            return pPtr;
        }
 
        level = found->children;
        key++;
    }
}
 
void TrieRemove(trieNode_t **root, char *key)
{
    trieNode_t *tPtr = NULL;
    trieNode_t *tmp = NULL;
 
    if(NULL == *root || NULL == key)
        return;
 
    tPtr = TrieSearch((*root)->children, key);
 
    if(NULL == tPtr)
    {
        printf("Key not found in trie\n");
        return;
    }
 
    while(1)
    {
        if( tPtr->prev && tPtr->next)
        {
            tmp = tPtr;
            tPtr->next->prev = tPtr->prev;
            tPtr->prev->next = tPtr->next;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif            
            free(tmp);
            break;
        }
        else if(tPtr->prev && !(tPtr->next))
        {
            tmp = tPtr;
            tPtr->prev->next = NULL;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif            
            free(tmp);
            break;
        }
        else if(!(tPtr->prev) && tPtr->next)
        {
            tmp = tPtr;
            tPtr->parent->children = tPtr->next;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif            
            free(tmp);
            break;
        }
        else
        {
            tmp = tPtr;
            tPtr = tPtr->parent;
            tPtr->children = NULL;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif            
            free(tmp);
        }
    }
#ifdef DEBUG
   printf("Deleted [%s] from trie\n", key);
#endif 
}


void TrieDestroy( trieNode_t* root)
{
    trieNode_t *tPtr = root;
    trieNode_t *tmp = root;
 
    while(tPtr)
    {
        while(tPtr->children)
        tPtr = tPtr->children;
 
        if( tPtr->prev && tPtr->next)
        {
           tmp = tPtr;
           tPtr->next->prev = tPtr->prev;
           tPtr->prev->next = tPtr->next;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif
            free(tmp);
        }
        else if(tPtr->prev && !(tPtr->next))
        {
           tmp = tPtr;
           tPtr->prev->next = NULL;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif
            free(tmp);
        }
        else if(!(tPtr->prev) && tPtr->next)
        {
           tmp = tPtr;
           tPtr->parent->children = tPtr->next;
           tPtr->next->prev = NULL;
           tPtr = tPtr->next;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif
            free(tmp);
        }
        else
        {
            tmp = tPtr;
            if(tPtr->parent == NULL)
            {
                /*Root*/
                free(tmp);
                return;
            }
            tPtr = tPtr->parent;
            tPtr->children = NULL;
#ifdef DEBUG
   printf("Deleted [%c] \n", tmp->key);
#endif
            free(tmp);
        }
    }
}

/* ============================================= */

int maxLevel;

void padding( char *s, int n )
{
   int i;

   for ( i = 0; i < n; i++ )
      printf( "%s", s );
}

void printNode(trieNode_t *p)
{
   if ( p->key != '\0' )
      printf("(`%c',%d)\n", p->key, p->value);
   else
      printf("(`*',%d)\n", p->value);
}

void printSubTrie(trieNode_t *p, int level )  // Print on level level
{
// printf("printSubTrie (p->key = '%c')\n", p->key);
   if ( p == NULL )
      return;

   while ( p != NULL )
   {  
      padding("         ", level );
      printNode( p );

      printSubTrie( p->children, level+1);

      p = p->next;
   }
}

void TriePrint(trieNode_t *root)
{
// printf("TriePrint\n");
   printSubTrie( root, 0 );  // Print on level 0
   printf("\n========================================================\n");
}