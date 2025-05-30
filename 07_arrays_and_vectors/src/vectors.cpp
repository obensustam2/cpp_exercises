#include <iostream>
#include <vector>

int main(){

    std::vector <int> my_vector;
    my_vector.emplace_back(5);
    std::cout << my_vector[0] << std::endl; 

    std::vector <double> number_vector = {0.5, 0.6, 0.7, 0.8, 0.9};
    std::cout << number_vector.at(0) << std::endl; 

    number_vector.push_back(1.0);
    std::cout << number_vector.at(5) << std::endl; 

    number_vector.emplace_back(1.1);
    std::cout << number_vector.at(6) << std::endl; 

    std::cout << "Length of the vector is: " << number_vector.size() << std::endl;
    
    number_vector.pop_back();

    std::cout << "Length of the vector is: " << number_vector.size() << std::endl;

    number_vector.insert(number_vector.begin(), -0.6);
    std::cout << number_vector.at(0) << std::endl; 

    // 2D Vectors
    std::vector <std::vector<int>> my_2d_vector = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::cout << my_2d_vector.at(1).at(2) << std::endl; 

    return 0;
}
