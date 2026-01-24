#include <iostream>

int main(){
    int *int_ptr = nullptr;
    int_ptr = new int;
    std::cout << int_ptr << std::endl; // Heap address
    delete int_ptr;


    size_t size;
    std::cout << "\nHow many temperatures data do you want to keep? ";
    std::cin >> size;
    double *temp_ptr = nullptr;
    temp_ptr = new double[size];
    std::cout << temp_ptr << std::endl;
    delete [] temp_ptr;

    return 0;
}