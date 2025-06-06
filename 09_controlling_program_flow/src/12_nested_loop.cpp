#include <iostream>
#include <vector>

int main (){

    // for(int i=1; i<=10; i++){
    //     for(int j=1; j<=10; j++){
    //         std::cout << i << " * " << j << " = " << i*j << std::endl;
    //     }
    //     std::cout << "-------------------" << std::endl;
    // }

    int num_items;
    std::cout << "How many items you have?: ";
    std::cin >> num_items;

    std::vector <int> my_vector;

    for(int i=1;i<=num_items;i++){
        int vector_item;
        std::cout << "Enter vector item " << i << ": ";
        std::cin >> vector_item;
        my_vector.push_back(vector_item);
    }

    std::cout << "\nDisplaying Histogram" << std::endl;
    for (auto val : my_vector){
        for(int i=1; i<=val; i++){
            if(i%5 == 0){
                std::cout << " ";
            }
            else{
                std::cout << "+";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}