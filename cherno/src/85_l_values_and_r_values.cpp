#include <iostream>
#include <string>

void printName(std::string& name){
    std::cout << "lvalue: " << name << std::endl;
}

void printName(std::string&& name){
    std::cout << "rvalue: " << name << std::endl;
}

int main(){
    std::string first_name = "Oben";
    std::string last_name = "Sustam";
    // std::string full_name = first_name + last_name;
    
    printName(first_name);
    printName(last_name);
    printName(first_name + " " + last_name);
    printName(std::move(first_name));
    printName(first_name);

    return 0;
}