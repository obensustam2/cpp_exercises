#include <iostream>

namespace MySensors{
    int id = 1;
    void read(){
        std::cout << "id: " << id << std::endl;
    }
}

namespace MyActuator{
    int id = 2;
    void read(){
        std::cout << "id: " << id << std::endl;
    }
}

using namespace MySensors;

int main(){
    read();
    MyActuator::read();

    return 0;
}