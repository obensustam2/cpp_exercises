#include <iostream>
#include <array>

int main()
{    
    int example[5];
    std::cout << "Array address: " << example << std::endl; // pointer
    std::cout << "Length of array in bytes: " << sizeof(example) << std::endl; // bytes


    // Array For Loop
    size_t len = sizeof(example) / sizeof(example[0]);
    for(int i = 0; i < len; i++){
        example[i] = 9;
    }
    std::cout << "Forth element of example: " << example[3] << std::endl;


    // Array Pointer Aritmethic
    int *ptr = example;
    *(ptr+3) = 1;
    std::cout << "Forth element of example: " << example[3] << std::endl;
    std::cout << "Example address: " << ptr << std::endl;
    std::cout << "Address of second element in example: " << (ptr+1) << std::endl;


    // Heap Memory Array
    int *another = new int[5];
    for(int i = 0; i < 5; i++){
        another[i] = 66;
    }
    std::cout << "Forth element of another: " << another[3] << std::endl;
    delete[] another;


    // C++ 11 Array library
    std::array<int, 5> new_array;
    for(int i = 0; i < new_array.size(); i++){
        new_array[i] = 55;
    }
    std::cout << "Forth element of new_array: " << new_array[3] << std::endl;
    return 0;
}