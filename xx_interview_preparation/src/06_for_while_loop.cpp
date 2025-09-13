#include <iostream>
#include <vector>

int main(){

    std::vector<int> my_vec = {9,90,69};

    for(int i=0; i<my_vec.size(); i++){
        std::cout << my_vec.at(i) << std::endl;
    }

    for(int j : my_vec){
        std::cout << j << std::endl;
    }

    bool is_finished = false;
    int k = 0;
    while(!is_finished){

        if(k == my_vec.size()){
            break;
        }
        
        std::cout << my_vec.at(k) << std::endl;
        
        k += 1;
    }


    return 0;
}