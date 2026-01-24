#include <iostream>
#include <string>
#include <vector>

void pass_by_value1(int num);
void pass_by_value2(std::string s);
void pass_by_value3(std::vector <std::string> v);
void print_vector(std::vector <std::string> v);

int main () {
    int num = 10;
    std::cout << "Num before calling pass_by_value1: " << num << std::endl;
    pass_by_value1(num);
    std::cout << "Num after calling pass_by_value1: " << num << std::endl;

    std::string name = "Oben";
    std::cout << "Name before calling pass_by_value2: " << name << std::endl;
    pass_by_value2(name);
    std::cout << "Name after calling pass_by_value2: " << name << std::endl;

    std::vector <std::string> my_vector = {"Oben", "Sustam", "29"};
    std::cout << "my_vector before calling pass_by_value2: " << std::endl;
    print_vector(my_vector);
    pass_by_value3(my_vector);
    std::cout << "my_vector after calling pass_by_value2: " << std::endl;
    print_vector(my_vector);

    return 0;
}


void pass_by_value1(int num){
    num = 1000;
}

void pass_by_value2(std::string s){
    s = "Changed";
}

void pass_by_value3(std::vector <std::string> v){
    v.clear();
}

void print_vector(std::vector <std::string> v){
    for(std::string el : v){
        std::cout << el << " ";
    }
    std::cout << std::endl;
}


