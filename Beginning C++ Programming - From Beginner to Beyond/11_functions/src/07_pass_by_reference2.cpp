#include <iostream>

void scale_number (int &numx);
void swap(int &a, int &b);

int main () {

    // int numx = 1000;
    // scale_number(numx);
    // std::cout << numx << std::endl;

    int a = 10;
    int b = 20;
    std::cout << a << " " << b << std::endl;
    swap(a,b);
    std::cout << a << " " << b << std::endl;
    return 0;
}

void scale_number(int &numx){
    if (numx > 100){
        numx = 100;
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}




