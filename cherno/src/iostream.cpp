#include <iostream>
#include <iomanip>

// color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"


enum class PrintType{
    OUT,
    LOG,
    ERR
};

template<typename T>
void print(T text, PrintType prt = PrintType::OUT){
    if (prt == PrintType::OUT){
        std::cout << GREEN  << text << RESET << std::endl;
    }
    else if(prt == PrintType::LOG){
        std::clog << YELLOW << text << RESET << std::endl;
    }
    else{
        std::cerr << RED << text  << RESET << std::endl;
    } 
}

int main() {

    // Print colorful
    const char* text = "Hello";
    print(text);
    print(text, PrintType::ERR);
    std::cout << "-----------\n";

    // Input — single value
    int age;
    std::cout << "Enter a number: ";
    std::cin >> age;
    std::cout << "Are you really " << age << " years old?" << std::endl;
    std::cout << "-----------\n";
    
    // Input — whole line (skips leading whitespace with std::ws)
    std::string fullName;
    std::cout << "Enter your fullname please: ";
    std::getline(std::cin >> std::ws, fullName);
    std::cout << "Thank you " << fullName << std::endl;
    std::cout << "-----------\n";

    // Set precision
    constexpr double PI = 3.14159265;
    std::cout << std::setprecision(3) << PI << std::endl;
    std::cout << "-----------\n";

    // Spacing
    std::cout << "Item" << std::setw(12) << "Qty" << std::setw(10) << "Price\n";
    std::cout << "-----------\n";

    // Hex conversion
    int num = 26;
    std::cout << "Hex of num " << num << " is " << std::hex << num << std::endl; 
    std::cout << std::dec << "Resetting to decimal, num: " << num << std::endl;   // 255 (reset to decimal)
    std::cout << "-----------\n";

    // Bool as text
    bool status = false;
    std::cout << status << std::endl;
    std::cout << std::boolalpha << status << std::endl;
    std::cout << std::noboolalpha << status << std::endl;
    std::cout << "-----------\n";

    return 0;
}