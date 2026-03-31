#include <iostream>

struct Vector3{
    float x, y, z;
};

int main(){
    // integers
    int value = 5; // stack
    
    int *heap_value = new int; // heap
    *heap_value = 5;
    delete heap_value;

    // arrays
    int array[5]; // stack
    std::cout << "Size of array: " << sizeof(array) << std::endl;
    for(int i=0; i<(sizeof(array)/4); i++){
        std::cout << "Address of array[" << i << "] = " << &array[i] << std::endl;
    }

    int *heap_array = new int[5]; // heap
    for(int i=0; i<5; i++){
        std::cout << "Address of heap_array[" << i << "] = " << &heap_array[i] << std::endl;
    }
    delete [] heap_array;

    // struct objects
    Vector3 vector; // stack
    
    Vector3 *heap_vector = new Vector3(); // heap
    delete heap_vector;

    return 0;
}