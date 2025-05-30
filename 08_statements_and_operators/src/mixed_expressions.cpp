#include <iostream>

int main(){

    const int count = 3;
    int num1, num2, num3, total;
    num1 = num2 = num3 = total = 0;

    std::cout << "Enter 3 integers seperated with spaces" << std::endl;
    std::cin >> num1 >> num2 >> num3;

    total = num1 + num2 + num3;

    double average = 0.0;
    average = total / count;
    std::cout << "Num1: " << num1 << " Num2: " << num2 << " Num3: " << num3 << std::endl;
    std::cout << "Sum is: " << total << std::endl;
    std::cout << "Average is: " << average << std::endl;

    std::cout << "Precise average is: " << static_cast<double>(total) / count << std::endl;

    return 0;
}