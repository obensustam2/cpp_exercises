#include <iostream>

int main(){
    int num = 0;
    const int target = 10;

    std::cout << "Enter a number and I will compare it to " << target << ": ";
    std::cin >> num; 

    if (num >= target){
        std::cout << num << " is greater than or equal to " << target << std::endl;
        int diff = num - target;

        std::cout << num << " is " << diff << " greater than " << target << std::endl;
    }

    else{
        std::cout << num << " is less than " << target << std::endl;
        int diff = target - num;
        std::cout << num << " is " << diff << " less than " << target << std::endl;
    }
    
    return 0;
}