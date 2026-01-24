#include <iostream>
#include <vector>

std::vector <int> func(std::vector <int> vec1, std::vector <int> vec2){
    std::vector <int> new_vec = {};

    for (int i=0;i<vec1.size();i++){
        for(int j=0;j<vec2.size();j++){
            new_vec.push_back(vec1.at(i) * vec2.at(j));
        }
    }

    return new_vec;
}

int main(){
    std::vector <int> vec1 = {1,2,3};
    std::vector <int> vec2 = {10,20,30,40,50};
    
    std::vector <int> new_vec = func(vec1, vec2);

    for (int num : new_vec){
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}