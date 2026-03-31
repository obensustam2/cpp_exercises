#include <iostream>
#include <vector>
#include <tuple>
#include <string>


template<typename T>
void print(T value){
    std::cout << "Value: " << value << std::endl;
}

int main(){ 

    std::vector<float> v = {20.4, 89.7, 66.0};
    for(float vi: v){
        print(vi);
    }

    std::tuple<bool, std::string> t = {false, "true"};
    print(std::get<0>(t));
    print(std::get<1>(t));

    print("Oben");
    print(29);

    std::vector<std::string> strings = {"hello", "my", "name"};
    for(std::string &string: strings){
        std::cout << string << std::endl;
    }

    return 0;
}