#include <iostream>
#include <memory>
#include <string>

class Car{
private:
    std::string model_;

public:
    // Constructor
    Car(const std::string &model) : model_(model){
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // Copy constructor
    Car(const Car& other) : model_(other.model_){
        std::cout << "Car " << model_ << " copied 🧬\n";
    }

    // Destructor
    ~Car(){
       std::cout << "Car " << model_ << " destroyed 💥\n"; 
    }

    void drive() const{
        std::cout << "Car " << model_ << " is driving...\n";
    }
};

int main(){
    std::cout << "--- Copy Constructor Example ---\n";

    // Normal stack object
    Car car1("BMW");

    // Copy construction
    Car car2 = car1;   // <-- calls copy constructor

    car2.drive();

    std::cout << "End of main()\n";
    
    return 0;
}
