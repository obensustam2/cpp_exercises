#include <iostream>
#include <memory>
#include <string>


struct AllocationMetrics{
    uint32_t totalAllocatedMemory = 0;
    uint32_t totalFreed = 0;

    uint32_t currentUsage(){
        return totalAllocatedMemory - totalFreed;
    }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size) {
    s_AllocationMetrics.totalAllocatedMemory += size;

    void* p = malloc(size);
    return p;
}

void operator delete(void* memory, size_t size){
    s_AllocationMetrics.totalFreed += size;

    free(memory);
}

struct Object{
    int x, y, z;
};

void printMemoryUsage(){
    std::cout << "Memory Usage: " << s_AllocationMetrics.currentUsage() << std::endl;
}

int main() {
    printMemoryUsage();
    int* i_ptr = new int(77);
    printMemoryUsage();

    {
        std::unique_ptr<Object> obj_p = std::make_unique<Object>();
        printMemoryUsage();
    }
    
    printMemoryUsage();
    delete i_ptr;
    printMemoryUsage();

    return 0;
}