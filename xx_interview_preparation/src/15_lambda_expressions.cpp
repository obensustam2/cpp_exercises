#include <iostream>
#include <string>


int main(){

    // Simple Lambda
    auto greet = [](){
        std::cout << "Hello Lambda!" << std::endl;
    };
    greet();
    greet();


    // Lambda with parameters
    auto add = [](int a, int b){
        return a+b;
    };
    std::cout << "Add: " << add(3,4) << std::endl; 


    // Lambda with capturing variables
    int x = 10;
    int y = 5;
    auto sum = [x,y](){
        return x+y;
    };
    std::cout << "Sum: " << sum() << std::endl; 


    // Lambda with auto parameter
    auto print = [](auto val){
        std::cout << val << std::endl;
    };
    print("Oben");
    print(29);


    return 0;
}