
#include <stdio.h>
#include "trie.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
   trieNode_t *root = TrieCreateNode('\0', 0);

   TrieAdd( &root, "andrew", 1);
   TriePrint(root);

   TrieAdd( &root, "tina", 2);
   TriePrint(root);

   TrieAdd( &root, "argo", 3);
   TriePrint(root);

   TrieAdd( &root, "timor", 5);
   TriePrint(root);

   TrieRemove(&root, "tim");
   TrieAdd(&root, "tim", 6);
   TrieRemove(&root, "tim");
   
   
   TrieAdd( &root, "ti", 6);
   TriePrint(root);

   TrieAdd(&root, "amy", 7);

   TrieAdd( &root, "aramis", 8);
   TriePrint(root);
   TrieDestroy(root);
}

