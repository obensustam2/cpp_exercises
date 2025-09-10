#include <iostream>


int func1(){
    int x = 10;
    int *x_ptr = &x;

    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Pointer stores: " << x_ptr << std::endl;
    std::cout << "Value via pointer: " << *x_ptr << std::endl;

    *x_ptr = 30;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Address of x: " << &x << std::endl;
    std::cout << "Pointer stores: " << x_ptr << std::endl;
    std::cout << "Value via pointer: " << *x_ptr << std::endl; 

    return 0;
}



int main(){
    std::cout << "--------Pointer introduction-------" << std::endl;
    func1();

    return 0;
}