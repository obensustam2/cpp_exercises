#include <iostream>

int main(){

    double num1 = 0.0;
    double num2 = 0.0;

    std::cout << "Enter 2 double with space" << std::endl;
    std::cin >> num1 >> num2;

    std::cout << num1 << " >= " << num2 << " is " << (num1 >= num2) << std::endl;
    std::cout << num1 << " > " << num2 << " is " << (num1 > num2) << std::endl;
    std::cout << num1 << " <= " << num2 << " is " << (num1 <= num2) << std::endl;
    std::cout << num1 << " < " << num2 << " is " << (num1 < num2) << std::endl;

    return 0;
}