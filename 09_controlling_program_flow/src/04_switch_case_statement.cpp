#include <iostream>


int main(){

    char letter_grade;
    std::cout << "Enter the letter grade you expect on the exam: ";
    std::cin >> letter_grade;

    switch (letter_grade){
        case 'a':
        case 'A':
            std::cout << "You need 90-100 for an A" << std::endl;
            break ;

        case 'b':
        case 'B':
                std::cout << "You need 80-89 for a B" << std::endl;
            break ;

        case 'c':
        case 'C':
                std::cout << "You need 70-79 for a C" << std::endl;
            break ;

        case 'd':
        case 'D':
                std::cout << "You need 60-69 for a D" << std::endl;
            break ;    
        
        case 'f':
        case 'F':
            char confirm;
            std::cout << "Are you sure (Y/N)? ";
            std::cin >> confirm;

            if (confirm == 'y' || confirm == 'Y'){
                std::cout << "OK, you didn't study I guess." << std::endl;
            }

            else if (confirm == 'n' || confirm == 'N'){
                std::cout << "Good, go study." << std::endl;
            }
            
            else{
                std::cout << "Illegal choice" << std::endl;
            }

            break ;    
        
        default:
            std::cout << "Sorry it is not a valid grade." << std::endl;
        }

    return 0;
}