#include <iostream>
#include <vector>

int main() {

    // for (int i = 0; i < 10; i++){
    //     std::cout << i << std::endl;
    // }


    // for (int i = 0; i < 10; i += 2){
    //     std::cout << i << std::endl;
    // }


    // for (int i = 10; i > 0; i--){
    //     std::cout << i << std::endl;
    // }


    // for (int i=0; i<=100; i+=10){
    //     if (i%15 == 0){
    //         std::cout << i << std::endl;
    //     } 
    // }


    // for (int i = 1, j = 5; i<=5; i++, j++){
    //     std::cout << i << " + " << j << " = " << i+j << std::endl;
    // }


    // for (int i = 1; i <=100; i++)
    // {
    //     std::cout << i << " ";
    //     if (i%10 == 0){
    //         std::cout << std::endl;
    //     }
    // }


    // for (int i = 1; i <=100; i++)
    // {
    //     std::cout << i << ((i%10 == 0) ? "\n" : " ");
    // }   

    
    std::vector<int> my_vector = {10,20,30,40};
    for (int i = 0; i<my_vector.size() ; i++){
        std::cout << my_vector.at(i) << std::endl;
    }

    return 0;
}