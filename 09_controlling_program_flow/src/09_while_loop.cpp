#include <iostream>

int main() {

    // int num ;
    // std::cout << "Enter a positive integer - start countdown: ";
    // std::cin >> num;
    // while (num > 0){
    //     std::cout << num << std::endl;
    //     num--;
    // }
    // std::cout << "Blastoff!" << std::endl;


    // int num ;
    // std::cout << "Enter a positive integer - count up to: ";
    // std::cin >> num;
    // int starting_point = 1;
    // while (starting_point < num){
    //     std::cout << starting_point << std::endl;
    //     starting_point++;
    // }
    // std::cout << "Blastoff!" << std::endl;


    // int user_input;
    // std::cout << "Enter an integer less than or equal to 100: ";
    // std::cin >> user_input;
    // while (user_input > 100){
    //     std::cout << "It was not a valid input. Enter an integer less than or equal to 100: ";
    //     std::cin >> user_input;
    // }
    // std::cout << "Thanks!\n";


    bool done = false;
    int number = 0;
    while (!done)
    {
        std::cout << "Enter an integer between 1 and 5: ";
        std::cin >> number;
        if (number<1 || number>5){
            std::cout << "Out of range try again." << std::endl;
        }
        else{
            std::cout << "Thanks!" << std::endl;
            done = true;
        }
    }
    


    return 0;
}