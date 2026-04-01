#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    int x = 10;


    // capture nothing
    auto add = [](int a, int b){
        return a+b;
    };
    std::cout << add(3,5) << std::endl;


    // capture x value
    auto add_x = [x](int a){
        return a+x;
    };
    std::cout << add_x(3) << std::endl;


    // std::sort without lambda funtion
    std::vector<int> v = {9, 57, 89, 0, -5};
    std::sort(v.begin(), v.end());
    std::cout << "Ascending order: ";
    for(int vi: v){
        std::cout << vi << " " ;
    }
    std::cout << std::endl;


    // std::sort with lambda funtion
    std::sort(v.begin(), v.end(), [](int a, int b){
        return a > b;
    });
    std::cout << "Descending order: ";
    for(int vi: v){
        std::cout << vi << " " ;
    }
    

    return 0;
}