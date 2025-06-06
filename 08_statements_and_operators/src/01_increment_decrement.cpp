#include <iostream>

int main(){

    int counter = 10;
    int result = 0;

    std::cout << "Counter: " << counter << std::endl;

    counter = counter + 1;
    std::cout << "Counter: " << counter << std::endl;

    //post increment
    counter++;
    std::cout << "Counter: " << counter << std::endl;

    // pre increment
    ++counter;
    std::cout << "Counter: " << counter << std::endl;

    

    counter = 10;
    result = 0;
    std::cout << "\nCounter: " << counter << std::endl;

    result = ++counter;
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Result: " << result << std::endl;


    counter = 10;
    result = 0;
    std::cout << "\nCounter: " << counter << std::endl;

    result = counter++;
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Result: " << result << std::endl;


    counter = 10;
    result = 0;
    std::cout << "\nCounter: " << counter << std::endl;

    result = ++counter + 10;
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Result: " << result << std::endl;


    counter = 10;
    result = 0;
    std::cout << "\nCounter: " << counter << std::endl;

    result = counter++ + 10;
    std::cout << "Counter: " << counter << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}