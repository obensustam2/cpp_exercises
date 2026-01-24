#include <iostream>

void increase_by_ten(int *num_ptr){
    *num_ptr +=10;
    std::cout << "Inside function: *num_ptr = " << *num_ptr << std::endl;
}

int main(){
    int number = 42;
    std::cout << "Before: number = " << number << std::endl;

    increase_by_ten(&number);

    std::cout << "After: number = " << number << std::endl;
    
    return 0;
}