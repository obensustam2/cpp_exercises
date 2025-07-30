#include <iostream>

class Shallow{
private:
    int *data;

public:
    void set_data(int val){
        *data = val;
    }

    void show_data(){
        std::cout << "Value: " << *data << ", Address: " << data << std::endl;
    }

    Shallow(int val){
        data = new int(val);
    }

    ~Shallow(){
        delete data;
        std::cout << "Destructor freed memory at " << data << std::endl;
    }

};

int main(){
    Shallow obj1(42);
    
    Shallow obj2 = obj1;
    obj2.set_data(99);

    obj1.show_data();
    obj2.show_data();

    return 0;
}