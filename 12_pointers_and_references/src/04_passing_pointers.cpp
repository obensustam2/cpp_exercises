#include <iostream>

void double_data(int *ptr){
    *ptr *= 2;
}

void trial1(){
    int value = 10;
    int *int_ptr = nullptr;
    std::cout << "Value: " << value << std::endl;
    double_data(&value);
    std::cout << "Value: " << value << std::endl;

    int_ptr = &value;
    double_data(int_ptr);
    std::cout << "Value: " << value << std::endl;
}


void double_data2(int &val){
    val *= 2;
}

void trial2(){
    int value2 = 10;
    std::cout << "Value: " << value2 << std::endl;
    double_data2(value2);
    std::cout << "Value: " << value2 << std::endl;
    double_data2(value2);
    std::cout << "Value: " << value2 << std::endl;
}


int main(){
    trial1();
    // trial2();
    return 0;
}