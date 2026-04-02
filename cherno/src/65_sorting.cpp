#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility> // std::pair
#include <map>

template<typename T>
void print(std::vector<T> vec){
    for(size_t i=0; i<vec.size(); i++){
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n";
}


template<typename T>
void pair_print(std::vector<T> vec){
    for(size_t i=0; i<vec.size(); i++){
        std::cout << vec.at(i).first << " " << vec.at(i).second << ", ";
    }
    std::cout << "\n";
}


int abs_func(int a, int b){
    return std::abs(a) > std::abs(b);
}


int main(){

    // std::sort - lambda - int
    std::vector<int> nums = {1, 3, 2, 6, 4};
    std::sort(nums.begin(), nums.end());
    print(nums);

    std::sort(nums.begin(), 
                nums.end(), 
                [](int a, int b){ 
                    return a > b;
                }
    );
    print(nums);


    // std::sort - string - lambda  
    std::vector<std::string> words = {"banana", "apple", "cherry", "date"};
    std::sort(words.begin(), words.end());
    print(words);

    std::sort(words.begin(), 
                words.end(),
                [](std::string &a, std::string &b){ 
                    return a.size() < b.size();
                }
    );
    print(words);


    // std::sort - pairs - lambda
    std::vector<std::pair<int, std::string>> scores = {{88, "Oben"}, {70, "Orbay"}, {99, "Orcun"}};
    std::sort(scores.begin(), scores.end());
    pair_print(scores);

    std::sort(scores.begin(), 
                scores.end(),
                [](std::pair<int, std::string> x, std::pair<int, std::string> y){ 
                    return x.first > y.first;
                }
    );
    pair_print(scores);


    // std::sort - map - lambda 
    std::map<std::string, int> grades = {{"Oben", 5}, {"Orbay", 9}, {"Orcun", 1}};
    std::vector<std::pair<std::string, int>> v_grades(grades.begin(), grades.end());
    std::sort(v_grades.begin(), 
                v_grades.end(),
                [](std::pair<std::string, int> x, std::pair<std::string, int> y){ 
                    return x.second > y.second;
                }
    );
    pair_print(v_grades);


    // std::sort - plain funtion
    std::vector<int> v = {-5, 3, -1, 4, -2};
    std::sort(v.begin(), v.end(), abs_func);
    print(v);


    // std::partial_sort
    std::vector<int> pv = {5, 2, 8, 1, 9, 3, 7};
    std::partial_sort(pv.begin(), pv.begin()+4, pv.end());
    print(pv); // onlf first 4 element are sorted


    // std::is_sorted
    std::vector<int> v_sorted = {1, 2, 3, 4, 5, -1};
    std::cout << "Is vector sorted: " << std::is_sorted(v_sorted.begin(), v_sorted.end()) << std::endl;




    return 0;
}