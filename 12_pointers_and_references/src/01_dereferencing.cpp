#include <iostream>
#include <vector>
#include <string>

int main() {
    int score = 100;
    int *score_ptr = &score;
    std::cout << *score_ptr << std::endl;
    *score_ptr = 200;
    std::cout << *score_ptr << std::endl;
    std::cout << score << std::endl;


    double high_temp = 100.7;
    double low_temp = 37.4;
    double *temp_ptr = &high_temp;
    std::cout << "\n" << *temp_ptr << std::endl;
    temp_ptr = &low_temp;
    std::cout << *temp_ptr << std::endl;


    std::string name = "Frank";
    std::string *string_ptr = &name;
    std::cout << "\n" << *string_ptr << std::endl;
    name = "Oben";
    std::cout << *string_ptr << std::endl;


    std::vector <std::string> stooges = {"Larry", "Moe", "Curly"};
    std::vector <std::string> *vector_ptr = &stooges;
    std::cout << "\nFirst stooge: " << (*vector_ptr).at(0) << std::endl;
    std::cout << "Stooges: ";
    for (auto stooge : *vector_ptr){
        std::cout << stooge << " ";
    }
    std::cout << std::endl;


    return 0;
}