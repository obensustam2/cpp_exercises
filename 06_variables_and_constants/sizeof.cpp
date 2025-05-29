#include <iostream>
#include <climits>

int main(){
    // Size
    std::cout << "char: " << sizeof(char) << " bytes" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "double: " << sizeof(double) << " bytes" << std::endl;
    std::cout << "string: " << sizeof(std::string) << " bytes" << std::endl;

    std::cout << "\nMax Values " << std::endl;
    std::cout << "char: " << CHAR_MAX << std::endl;
    std::cout << "int: " << INT_MAX << std::endl;
        
    return 0;
}
