#include <iostream>
#include <string>

template<typename T>
void print(T value){
    std::cout << value << std::endl;
}

template<typename T1, typename T2>
void sum(T1 num1, T2 num2){
    std::cout << "Sum: " << num1 + num2 << std::endl;
}


template<typename type, int size>
class Array{
private:
    type arr[size];
public:
    int getSize(){
        return size;
    }
};



int main(){

    // Testing of template function      
    print("Hello");
    print(23);
    print(55.57);

    sum(10, 3);
    sum(10.4, 5.44);


    // Testing of template class
    Array<float, 7> array;
    std::cout << array.getSize() << std::endl;

    return 0;
}