#include "mymalloc.h"
#include <stdint.h>

#define MEMORY_SIZE 25000
static unsigned char memory[MEMORY_SIZE];

typedef struct Block {
    size_t size;
    struct Block* next;
    int free;
} Block;

static Block* freeList = NULL;

void initMemory() {
    freeList = (Block*)memory;
    freeList->size = MEMORY_SIZE - sizeof(Block);
    freeList->next = NULL;
    freeList->free = 1;
}

Block* findFreeBlock(size_t size) {
    Block* current = freeList;
    while (current) {
        if (current->free && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void splitBlock(Block* block, size_t size) {
    Block* newBlock = (Block*)((unsigned char*)block + sizeof(Block) + size);
    newBlock->size = block->size - size - sizeof(Block);
    newBlock->next = block->next;
    newBlock->free = 1;
    block->size = size;
    block->next = newBlock;
    block->free = 0;
}

void* MyMalloc(size_t size) {
    if (!freeList) {
        initMemory();
    }

    Block* block = findFreeBlock(size);
    if (block) {
        if (block->size > size + sizeof(Block)) {
            splitBlock(block, size);
        }
        block->free = 0;
        return (void*)((unsigned char*)block + sizeof(Block));
    }
    return NULL;
}

void MyFree(void* ptr) {
    if (!ptr) return;

    Block* block = (Block*)((unsigned char*)ptr - sizeof(Block));
    block->free = 1;
}