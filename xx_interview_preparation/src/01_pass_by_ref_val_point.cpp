#include <iostream>

void pass_by_pointer(int *num){
    *num -= 5;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pass_by_reference(int &x){
    x -= 5;
}

void pass_by_value(int x){
    x -= 5;
}

int pass_by_value_return(int x){
    x -= 5;
    return x;
}


int main(){
    std::cout << "-------Pass by Pointer----" << std::endl;
    int my_num = 100;
    std::cout << "Before Increment: " << my_num << std::endl;
    pass_by_pointer(&my_num);
    std::cout << "After Increment: " << my_num << "\n" << std::endl;


    std::cout << "---------Swap with Pointer----" << std::endl;
    int a = 10;
    int b = 20;
    std::cout << "Before Swap A: " << a << " B: " << b << std::endl;
    swap(&a, &b);
    std::cout << "After Swap A: " << a << " B: " << b << "\n" << std::endl;


    std::cout << "--------Pass by Reference-----" << std::endl;
    int c = 100;
    std::cout << "Before Decrement: " << c << std::endl;
    pass_by_reference(c);
    std::cout << "After Decrement: " << c << "\n" << std::endl;


    std::cout << "------Pass by Value------" << std::endl;
    int d = 100;
    std::cout << "Before Decrement: " << d << std::endl;
    pass_by_value(d);
    std::cout << "After Decrement: " << d << "\n" << std::endl;


    std::cout << "-----Pass by Value with Return------" << std::endl;
    int e = 100;
    std::cout << "Before Decrement: " << e << std::endl;
    std::cout << "After Decrement: " << pass_by_value_return(e) << std::endl;
    
    
    return 0;
}