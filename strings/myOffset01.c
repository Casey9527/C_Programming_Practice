
#include <stdio.h>
#include <inttypes.h>

#define myOffset(type, member) (uintptr_t)(&(((type *) 0)->member))

typedef struct trieNode {
    char key;
    int data;
    struct trieNode *parent, *children;
    struct trieNode *prev, *next;
} trieNode;

int main()
{
    printf("sizeof(void *): %d\n", (int )sizeof(void *));
    printf("offset(trieNode, key): %d\n", (int )myOffset(trieNode, key));
    printf("offset(trieNode, data): %d\n", (int )myOffset(trieNode, data));
    printf("offset(trieNode, parent): %d\n", (int )myOffset(trieNode, parent));
    printf("offset(trieNode, children): %d\n", (int )myOffset(trieNode, children));
    printf("offset(trieNode, prev): %d\n", (int )myOffset(trieNode, prev));
    printf("offset(trieNode, next): %d\n", (int )myOffset(trieNode, next));
    
    return 0;
}