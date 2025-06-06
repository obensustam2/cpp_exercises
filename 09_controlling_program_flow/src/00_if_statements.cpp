#include <iostream>

int main(){
    int min = 10;
    int max = 100;
    int num;
    std::cout << "Enter a number between " << min << " and " << max << ": ";
    std::cin >> num;

    if (num >= min)
    {
        std::cout << "============ If Statement 1 ===========\n";
        std::cout << num << " is greater than or equal to " << min << std::endl; 
        
        int difference = num - min;
        std::cout << num << " is " << difference << " greater than " << min << std::endl;
    }

    if (num <= max)
    {
        std::cout << "============ If Statement 2 ===========\n";
        std::cout << num << " is less than or equal to " << max << std::endl; 
        
        int difference = max - num;
        std::cout << num << " is " << difference << " less than " << max << std::endl;       
    }

    if (num >= min && num <= max)
    {
        std::cout << "============ If Statement 3 ===========\n";
        std::cout << num << " is in range " << std::endl; 
        std::cout << "Stamement 1 and 2 will also display!" << std::endl;
    }

    if (num == min || num == max)
    {
        std::cout << "============ If Statement 4 ===========\n";
        std::cout << num << " is right on a boundary " << std::endl; 
        std::cout << "This means all 4 statement will display." << std::endl;
    }

    return 0;
}