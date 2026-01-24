#include <iostream>

int main(){
    int x = 42; // x is a stack variable
    int *p = &x; // ptr is a pointer pointing to x
 
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Value stored in this pointer (address of x): " << p << std::endl;
    std::cout << "Value pointed to by pointer: " << *p << std::endl;
    
    // dereference the pointer to access or modify the value 
    *p = 45;
    std::cout << "Value of x: " << x << std::endl;
    return 0;
}