#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector <std::string>);


int main(){
    print(10);
    print(10.3);
    print('a');
    print("Oben"); // C-style string is converted to C++ string
    print({"Hello", "my", "name", "is", "Oben"});

    return 0;
}


void print(int num){
    std::cout << "Printing int: " << num << std::endl;
}

void print(double num){
    std::cout << "Printing double: " << num << std::endl;
}

void print(std::string text){
    std::cout << "Printing string: " << text << std::endl;
}

void print(std::string text, std::string text2){
    std::cout << "Printing 2 string: " << text << " " << text2 << std::endl;
}

void print(std::vector <std::string> text_vec){
    std::cout << "Printing vector: ";
    for(std::string text : text_vec){
        std::cout << text << " ";
    }
    std::cout << std::endl;
}