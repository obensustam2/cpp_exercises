#include <iostream>
#include <vector>
#include <string>

int main() {
    int num = 10;
    std::cout << "Value of num is " << num << std::endl;  
    std::cout << "Size of num is " << sizeof(num) << " bytes" << std::endl;    
    std::cout << "Address of num is " << &num << std::endl;

    int* p;
    std::cout << "\nValue of p is " << p << std::endl;  // Garbage
    std::cout << "Size of p is " << sizeof(p) << " bytes" << std::endl;    
    std::cout << "Address of p is " << &p << std::endl; 

    p = nullptr ;
    std::cout << "New value of p is " << p << std::endl; 


    int* p1 = nullptr;
    double* p2 = nullptr;
    unsigned long long* p3 = nullptr;
    std::vector <std::string>* p4 = nullptr;
    std::string* p5 = nullptr;
    
    std::cout << "\nSize of p1 is " << sizeof(p1) << std::endl;
    std::cout << "Size of p2 is " << sizeof(p2) << std::endl;
    std::cout << "Size of p3 is " << sizeof(p3) << std::endl;
    std::cout << "Size of p4 is " << sizeof(p4) << std::endl;
    std::cout << "Size of p5 is " << sizeof(p5) << std::endl;


    int score = 10;
    int* score_ptr = nullptr;
    score_ptr = &score;
    std::cout << "\nValue of score is   " << score << std::endl;
    std::cout << "Address of score is   " << score_ptr << std::endl;
    std::cout << "Value of score_ptr is " << score_ptr << std::endl;

    return 0;
}
