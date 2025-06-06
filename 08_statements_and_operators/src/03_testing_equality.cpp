#include <iostream>

int main(){

    bool equal_result = false;
    bool not_equal_result = false;

    int num1 = 0;
    int num2 = 0;

    std::cout << "Enter 2 integers with space" << std::endl;
    std::cin >> num1 >> num2;

    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);

    std::cout << "Comparision Result (Equal): " << equal_result << std::endl;
    std::cout << "Comparision Result (Not Equal): " << not_equal_result << std::endl;



    char letter1 = 'a';
    char letter2 = 'a';

    std::cout << "Enter 2 character with space" << std::endl;
    std::cin >> letter1 >> letter2;

    equal_result = (letter1 == letter2);
    not_equal_result = (letter1 != letter2);

    std::cout << "Comparision Result (Equal): " << equal_result << std::endl;
    std::cout << "Comparision Result (Not Equal): " << not_equal_result << std::endl;



    double num3 = 0.0;
    double num4 = 0.0;

    std::cout << "Enter 2 double with space" << std::endl;
    std::cin >> num3 >> num4;

    equal_result = (num3 == num4);
    not_equal_result = (num3 != num4);

    std::cout << "Comparision Result (Equal): " << equal_result << std::endl;
    std::cout << "Comparision Result (Not Equal): " << not_equal_result << std::endl;

    return 0;
}