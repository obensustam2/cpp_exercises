#include <iostream>

int main(){

    /* Example 1
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::cout << num << " is " << ((num % 2 == 0) ? "even\n" : "odd\n");
    */

    int num1, num2, bigger, smaller;
    std::cout << "Enter two integers seperated by space: ";
    std::cin >> num1 >> num2;

    if (num1 != num2) {
        bigger = (num1 > num2) ? num1 : num2;
        smaller = (num1 < num2) ? num1 : num2;
        std::cout << "Bigger is " << bigger << std::endl;
        std::cout << "Smaller is " << smaller << std::endl;
    }

    else{
        std::cout << "They are equal" << std::endl;
    }

    return 0;
}