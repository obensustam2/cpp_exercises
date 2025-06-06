#include <iostream>
#include <vector>

int main(){

    std::vector <int> vector1;
    vector1.push_back(10);
    vector1.push_back(20);
    std::cout << "|Vector 1| Element 1: " << vector1.at(0) << " Element 2: " << vector1.at(1) << 
        " Size: " << vector1.size() << std::endl;
    
    std::vector <int> vector2;
    vector2.push_back(100);
    vector2.push_back(200);
    std::cout << "|Vector 2| Element 1: " << vector2.at(0) << " Element 2: " << vector2.at(1) << 
        " Size: " << vector2.size() << std::endl;

    std::vector <std::vector <int>> vector_2d ;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2); 

    std::cout << "\n";
    std::cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << std::endl;
    std::cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << std::endl; 
    std::cout << "\n";

    vector1.at(0) = 1000;

    std::cout << vector_2d.at(0).at(0) << " " << vector_2d.at(0).at(1) << std::endl;
    std::cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << std::endl; 
    std::cout << "\n";

    std::cout << vector1.at(0) << " " << vector1.at(1) << std::endl;
    
    return 0;
}
