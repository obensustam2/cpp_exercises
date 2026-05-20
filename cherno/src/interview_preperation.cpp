#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> student_list = {
    {"ben", 9}, {"rbay", 8}, {"cun", 0}
}; 

long long factorial(int n){
    long long result = 1;
    for(int i = n; i>0; i--){
        result = result * i;
    }    
    return result;
}


int main(){
    std::cout << student_list.at("cun") << std::endl;
    for(auto& [k, v] : student_list){
        std::cout << k << ":" << v << std::endl;
    }

    long long res = factorial(20);
    std::cout << res << std::endl;

    return 0;
}

