#include <iostream>
#include <memory>

class Car {
private:
    std::string model_;

public:
    // Constructor
    Car(const std::string &model) : model_(model){
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // Deconstructor
    ~Car(){
       std::cout << "Car " << model_ << " destroyed 💥\n"; 
    }

    // A method
    void drive() const{
        std::cout << "Car " << model_ << " is driving...\n";
    }    
};

int main(){
    std::cout << "--- Shared Pointer Example ---";

    // Create a Car object managed by shared_ptr
    std::shared_ptr<Car> car1_ptr = std::make_shared<Car>("Togg");
    
    {
        // Another shared_ptr points to the same object
        std::shared_ptr<Car> car2_ptr = car1_ptr;

        std::cout << "car1_ptr use count: " << car1_ptr.use_count() << std::endl;
        std::cout << "car2_ptr use count: " << car2_ptr.use_count() << std::endl;

        car2_ptr->drive();
    } // car2_ptr goes out of scope, ref count decreases

    std::cout << "After car2_ptr is destroyed" << std::endl;
    std::cout << "car1_ptr use_count = " << car1_ptr.use_count() << std::endl;

    car1_ptr->drive();

    return 0;


    return 0;
}