#include <iostream>

int main(){

    int lower = 10;
    int upper = 20;
    int num1 = 0;
    std::cout << "Enter an integer - the bounds are "<< lower << " and " << upper << ": ";
    std::cin >> num1;

    bool within_bounds = num1 >= lower && num1 <= upper;
    std::cout << num1 << " is between "<< lower << " and " << upper << ": " << within_bounds << std::endl;


    bool outside_bounds = num1 < lower || num1 > upper;
    std::cout << num1 << " is outside of "<< lower << " and " << upper << ": " << outside_bounds << std::endl;

    return 0;
}