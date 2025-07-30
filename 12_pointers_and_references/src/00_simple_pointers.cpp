#include <iostream>
#include <vector>
#include <string>

int main() {

    int score = 10;
    int *score_ptr = &score;

    std::cout << "Value of score is " << score << std::endl;
    std::cout << "Address of score  is " << &score << std::endl;
    std::cout << "Value of the score_ptr is " << score_ptr << std::endl;
    std::cout << "Value pointed to score_ptr is " << *score_ptr << std::endl;

    return 0;
}
