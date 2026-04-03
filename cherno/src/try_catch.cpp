#include <iostream>
#include <stdexcept>

int divide(int a, int b){
    if (b == 0){
        throw std::runtime_error("Division by zero");
    }
    return a / b;
}

int parse_and_divide(const std::string& a, const std::string& b){
    if (!std::isdigit(a[0]) || !std::isdigit(b[0])){
        throw std::invalid_argument("Arguments must be numeric");
    }
    return divide(std::stoi(a), std::stoi(b));
}

int main(){
    try{
        int result = divide(10, 0);
        // int result = parse_and_divide("10", "abc"); 
        std::cout << result << std::endl;
    } catch (const std::runtime_error &e){
        std::cout << "Caught: " << e.what() << std::endl;
    } catch (const std::invalid_argument &e){
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}