#include <iostream>
#include <array>

int main(){

    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;
    std::cout << data.size() << std::endl;
    std::cout << "Fifth element: " << data.at(4) << std::endl;

    int data_old[5];
    data_old[0] = 2;
    data_old[4] = 1;


    return 0;
}