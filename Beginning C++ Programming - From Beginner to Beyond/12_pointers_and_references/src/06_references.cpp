#include <iostream>
#include <string>
#include <vector>

void stooges(){
    std::vector <std::string> stooges = {"Larry", "Moe", "Curly"};

    for (std::string name : stooges){
        name = "Oben";
    }

    for (std::string name : stooges){
        std::cout << name << " ";
    }
    std::cout << std::endl;
}


int main(){
    stooges();

    int num = 100;
    int &ref = num;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
    num = 500;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
    ref = -300;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
    return 0;
}