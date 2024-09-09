#ifndef MEMORY_POOL_ALLOCATOR_H
#define MEMORY_POOL_ALLOCATOR_H

#include <cstddef>  // For size_t
#include <iostream> // For debugging purposes

class MemoryPoolAllocator {
private:
    struct FreeBlock {
        FreeBlock* next; // Pointer to the next free block
    };

    void* pool;           // Pointer to the start of the memory pool
    FreeBlock* freeList;  // Pointer to the start of the free list
    size_t poolSize;      // Total size of the memory pool
    size_t blockSize;     // Size of each block in the pool

public:
    MemoryPoolAllocator(size_t totalSize, size_t blockSize);
    ~MemoryPoolAllocator();

    void* allocate(size_t size);
    void deallocate(void* ptr);

    void printStatus() const; // Optional: Print status for debugging
};

#endif // MEMORY_POOL_ALLOCATOR_H
