#include <iostream>

int main(){

    // stack memory with stack overlow program exit
    // int bigStackArray[4000000]; // int stores 4 bytes. 4.000.000 x 4 = 16.000.000 Byte = 16 MB. Which is higher than stack memory size (8 MB)
    // bigStackArray[0] = 0;
    // std::cout << "First Element: " << bigStackArray[0] << std::endl; 

    // heap memory with success
    int *bigHeapArray = new int[4000000];
    bigHeapArray[0] = 0;
    std::cout << "First Element: " << bigHeapArray[0] << std::endl; 
    delete[] bigHeapArray;

    // heap memory with memory leak system crash
    // while(true){
    //     int *bigHeapArray = new int[4000000];
    //     std::cout << "Leaking..." << std::endl;
    // }

    return 0;
}