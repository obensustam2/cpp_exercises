#include <iostream>
#include <variant>
#include <string>


int main(){

    std::variant<int, double, std::string> var;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(std::string) << std::endl;
    std::cout << "Size of variable: " << sizeof(var) << std::endl;

    var = 50.5;
    int x = std::get<double>(var);
    std::cout << x << std::endl;

    var = "Oben";
    std::string name = std::get<std::string>(var);
    std::cout << name << std::endl;
    std::cout << var.index() << std::endl;

    std::string* isString = std::get_if<std::string>(&var);
    std::cout << *isString << std::endl;

    double* isDouble = std::get_if<double>(&var);
    if(isDouble){
        std::cout << *isDouble << std::endl;
    }
    else{
        std::cout << "Var is not a double" << std::endl;
    }
    
    return 0;
}