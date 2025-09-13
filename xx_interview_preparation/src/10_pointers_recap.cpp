#include <iostream>
#include <memory>
#include <string>

class Car{
private:
    std::string name_;

public:
    Car(std::string name) : name_(name){
        std::cout << "Car object created: " << name_ << std::endl;
    } 

    Car(Car &copy_car) : name_(copy_car.name_){
        std::cout << "Copy car object created: " << name_ << std::endl;
    } 

    ~Car(){
        std::cout << "Car object deleted: " << name_ << std::endl;
    }

    void set_name(std::string new_name){
       name_ = new_name; 
    }

    std::string get_name(){
        return name_;
    }
};


int main(){
    // Unique Pointer
    std::unique_ptr<Car> my_car_ptr = std::make_unique<Car>("Audi");
    my_car_ptr->set_name("Audi RS");
    std::cout << "My car is called: " << my_car_ptr->get_name() << std::endl;

    std::unique_ptr<Car> copy_c1_ptr = std::move(my_car_ptr);
    copy_c1_ptr->set_name("Audi R3");
    std::cout << "Copy car is called: " << copy_c1_ptr->get_name() << std::endl;
    
    // Shared Pointer
    std::shared_ptr<Car> shared_car_ptr1 = std::make_shared<Car>("Volkswagen");
    shared_car_ptr1->set_name("Golf 5");
    std::cout << "My car is called: " << shared_car_ptr1->get_name() << std::endl;

    std::shared_ptr<Car> shared_car_ptr2 = shared_car_ptr1;
    std::cout << "My car is called: " << shared_car_ptr2->get_name() << std::endl;

    std::shared_ptr<Car> shared_car_ptr3 = std::make_shared<Car>("Porsche");

    std::shared_ptr<Car> shared_car_ptr4 = shared_car_ptr1;

    std::cout << "Shared pointer counter: " << shared_car_ptr2.use_count() << std::endl; // 3

    std::unique_ptr<int> int_ptr = std::make_unique<int>(30);
    std::cout << *int_ptr << std::endl;
    std::cout << int_ptr.get() << std::endl;

    
    return 0;
}