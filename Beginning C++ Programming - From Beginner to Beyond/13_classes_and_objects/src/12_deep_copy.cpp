#include <iostream>

class Deep{
private:
    int *data;

public:
    void set_data(int val){
        *data = val;
    }

    void show_data(){
        std::cout << "Value: " << *data << ", Address: " << data << std::endl;
    }

    Deep(int val) {
        data = new int(val);
        std::cout << "Constructor is called" << std::endl;
    }

    // Deep copy constructor
    Deep(const Deep &source){
        data = new int(*source.data);
        std::cout << "Deep copy constructor is called" << std::endl;
    }

    ~Deep(){
        delete data;
        std::cout << "Destructor freed memory at " << data << std::endl;
    }
};

int main(){
    Deep obj1(42);
    Deep obj2(obj1);
    obj1.show_data();  
    obj2.show_data(); 
    obj2.set_data(99);  

    obj1.show_data();  
    obj2.show_data(); 

    return 0;
}