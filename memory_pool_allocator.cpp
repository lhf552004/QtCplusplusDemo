#include "memory_pool_allocator.h"
#include <cstdlib>  // For std::malloc and std::free
#include <cassert>  // For assert

MemoryPoolAllocator::MemoryPoolAllocator(size_t totalSize, size_t blockSize)
    : poolSize(totalSize), blockSize(blockSize) {
    // Allocate a block of memory for the pool
    pool = std::malloc(poolSize);
    assert(pool != nullptr); // Ensure memory allocation succeeded

    // Initialize the free list
    freeList = static_cast<FreeBlock*>(pool);
    FreeBlock* current = freeList;

    // Divide the pool into blocks and create a linked list of free blocks
    for (size_t i = blockSize; i < poolSize; i += blockSize) {
        current->next = reinterpret_cast<FreeBlock*>(static_cast<char*>(pool) + i);
        current = current->next;
    }
    current->next = nullptr; // End of the free list
}

MemoryPoolAllocator::~MemoryPoolAllocator() {
    std::free(pool); // Free the entire memory pool
}

void* MemoryPoolAllocator::allocate(size_t size) {
    // Ensure the requested size fits within a block
    if (size > blockSize || freeList == nullptr) {
        return nullptr; // Not enough memory or invalid request
    }

    // Allocate a block from the free list
    FreeBlock* allocatedBlock = freeList;
    freeList = freeList->next; // Update the free list to the next free block
    return static_cast<void*>(allocatedBlock);
}

void MemoryPoolAllocator::deallocate(void* ptr) {
    if (ptr == nullptr) return; // Ignore null pointer deallocation

    // Add the block back to the free list
    FreeBlock* deallocatedBlock = static_cast<FreeBlock*>(ptr);
    deallocatedBlock->next = freeList;
    freeList = deallocatedBlock;
}

void MemoryPoolAllocator::printStatus() const {
    size_t freeCount = 0;
    FreeBlock* current = freeList;
    while (current != nullptr) {
        freeCount++;
        current = current->next;
    }
    std::cout << "Memory Pool Status: " << freeCount << " free blocks remaining." << std::endl;
}
