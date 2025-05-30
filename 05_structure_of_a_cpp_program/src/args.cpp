#include <iostream>

int main(int num_args, char *args[]){
    
    if(num_args < 2){
        std::cout << "Please provide your number as argument" << std::endl;
        return 0;
    }

    std::cout << "Oh my favorite number is also " << args[1] << "\n"; // alternative to std::endl
    return 1;
}