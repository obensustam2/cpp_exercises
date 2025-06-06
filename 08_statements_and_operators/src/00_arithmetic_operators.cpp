#include <iostream>

int main(){

    int result;
    int num1 = 10;
    int num2 = 3;

    result = num1 + num2;
    std::cout << "Result +: " << result << std::endl;

    result = num1 - num2;
    std::cout << "Result -: " << result << std::endl;
    
    result = num1 * num2;
    std::cout << "Result *: " << result << std::endl;
    
    result = num1 / num2;
    std::cout << "Result /: " << result << std::endl;

    result = num1 % num2;
    std::cout << "Result %: " << result << std::endl;

    return 0;
}