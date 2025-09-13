#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Car{
private:
    std::string model_;
    std::vector<std::string> properties_;
    int year_;

public:
    Car(std::string model, std::vector<std::string> properties, int year) 
        : model_(model), properties_(properties), year_(year){
        std::cout << "Car " << model_ << " created" << std::endl;
    }

    Car(Car &copy) : model_(copy.model_), properties_(copy.properties_), year_(copy.year_){
        std::cout << "Copied car " << model_ << " created" << std::endl;
    }

    ~Car(){
        std::cout << "Car " << model_ << " removed" << std::endl;
    }

    std::string get_model(){
        return model_;
    }

    void set_model(std::string new_model){
        model_ = new_model;
    }
};


int main(){
    Car new_car("Renault Clio", {"rear camera", "automatic gear", "front distance sensor"}, 2022);
    std::cout << "New Car model: " << new_car.get_model() << std::endl;

    Car copy_car = new_car;
    std::cout << "Copy Car model: " << copy_car.get_model() << std::endl;
    copy_car.set_model("Volkswagen Golf");
    std::cout << "Copy Car model: " << copy_car.get_model() << std::endl;

    std::cout << "New Car model: " << new_car.get_model() << std::endl;
    
    return 0;
}