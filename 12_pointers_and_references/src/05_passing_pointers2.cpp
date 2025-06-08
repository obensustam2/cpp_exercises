#include <iostream>
#include <string>
#include <vector>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void example1(){
    int x = 100;
    int y = 200;
    std::cout << "X: " << x << " Y: " << y << std::endl;
    swap(&x, &y);
    std::cout << "X: " << x << " Y: " << y << std::endl;
}


void display(const std::vector <std::string> *const v){
    // (*v).at(0) = "Oben"; // Compile error (const std::vector <std::string>)
    for (std::string s : *v){
        std::cout << s << " ";
    }
    std::cout << std::endl;
    // v = null_ptr // Compile error (*const v)
}

void example2(){
    std::vector <std::string> stooges = {"Larry", "Moe", "Curly"};
    display(&stooges);
}


int main(){
    // example1();
    example2();

    return 0;
}