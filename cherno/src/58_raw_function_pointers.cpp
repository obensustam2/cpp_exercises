#include <iostream>

int add(int a, int b){
    return a+b;
}


void apply(int a, int b, int(*fn)(int, int)){
    std::cout << fn(a, b) << std::endl;
}


int main(){
    // Usage 1
    int (*fn_ptr)(int, int) = &add;
    std::cout << fn_ptr(3,5) << std::endl;

    // Usage 2: main use case is passing functions as arguments to other functions
    apply(3, 5, add);

    return 0;
}