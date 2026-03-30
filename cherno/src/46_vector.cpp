#include <iostream>
#include <vector>

int main(){
    std::vector<int> my_vector = {10, 20};

    std::cout << my_vector.at(my_vector.size()-1) << std::endl;

    my_vector.push_back(30);

    std::cout << my_vector.at(my_vector.size()-1) << std::endl;
    
    return 0;
}