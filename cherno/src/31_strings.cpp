#include <iostream>
#include <string>

int main(){
    char *name = "Oben";
    std::cout << name << std::endl;

    char surname[7] = "Sustam";
    surname[1] = 'a';
    std::cout << surname << std::endl;

    std::string new_name = "Orbay";
    std::string full_name = new_name + " Sustam" ;
    std::cout << new_name << std::endl;
    std::cout << new_name.size() << std::endl;
    std::cout << full_name << std::endl;

    return 0;
}