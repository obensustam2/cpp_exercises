#include <iostream>

int main(){

    int *heap_ptr = new int(42); // 'new' allocates memory on the heap and returns a pointer
    
    std::cout << "Value stored in heap memory: " << *heap_ptr << std::endl;
    std::cout << "Address of heap memory: " << heap_ptr << std::endl;

    // Modify the value via pointer
    *heap_ptr = 45; 
    std::cout << "New value after modification: " << *heap_ptr << std::endl;

    // Always free heap memory manually to avoid memory leaks
    delete heap_ptr;
    heap_ptr = nullptr; // good practice to avoid dangling pointer

    return 0;
}