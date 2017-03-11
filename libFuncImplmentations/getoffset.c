


#include <stdio.h>
#include <inttypes.h>

//#define myOffset(type, member) (uintptr_t)(&(((type *) 0)->member))
#define get_offset(type, mem) ( (size_t)(&(((type *)(0))->mem)) )

typedef struct trieNode {
    char key;
    int data;
    struct trieNode *parent, *children;
    struct trieNode *prev, *next;
} trieNode;

int main()
{
    printf("sizeof(void *): %d\n", (int )sizeof(void *));
    printf("offset(trieNode, key): %d\n", get_offset(trieNode, key));
    printf("offset(trieNode, data): %d\n", get_offset(trieNode, data));
    printf("offset(trieNode, parent): %d\n", get_offset(trieNode, parent));
    printf("offset(trieNode, children): %d\n", get_offset(trieNode, children));
    printf("offset(trieNode, prev): %d\n", get_offset(trieNode, prev));
    printf("offset(trieNode, next): %d\n", get_offset(trieNode, next));
    
    return 0;
}