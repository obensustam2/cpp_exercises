#include <iostream>
#include <memory>

class Car{
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
    std::cout << "--- Unique Pointer Example ---\n";

    // Create a Car object on the heap, owned by unique_ptr
    std::unique_ptr<Car> car1_ptr = std::make_unique<Car>("Tesla");
    std::cout << "Debug 1 \n";

    // Use the object via unique_ptr
    car1_ptr->drive();

    // Transfer ownership to another unique_ptr
    std::unique_ptr<Car> car2_ptr = std::move(car1_ptr);

    if(!car1_ptr){
        std::cout << "car1_ptr no longer owns the object.\n";
        std::cout << "Car1 Pointer: " << car1_ptr.get() << std::endl;
        std::cout << "Car2 Pointer: " << car2_ptr.get() << std::endl;
    }

    car2_ptr->drive();

    // No need to delete manually → car2_ptr automatically destroys the object

    return 0;
} 