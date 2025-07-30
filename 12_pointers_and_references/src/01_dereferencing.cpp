#include <iostream>

int main() {
    int score = 100;
    int *score_ptr = &score;
    std::cout << "Dereferencing the pointer: " << *score_ptr << std::endl;
    std::cout << "Score value: " << score << std::endl;

    *score_ptr = 200; // updating the original score variable through the pointer
    std::cout << "\nDereferencing the pointer: " << *score_ptr << std::endl;
    std::cout << "Score value: " << score << std::endl;
    
    score = 500;  // change directly
    std::cout << "\nDereferencing the pointer: " << *score_ptr << std::endl;
    std::cout << "Score value: " << score << std::endl;

    return 0;
}