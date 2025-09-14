#include <iostream>
#include <string>
#include <memory>

class Animal{
protected:
    std::string name_;

public:
    Animal(std::string name) : name_(name){
    }

    void eat(){
        std::cout << name_ << " is eating." << std::endl;
    }

    // virtual enables polymorphism
    virtual void sleep(){
        std::cout << name_ << " is sleeping." << std::endl;
    }
};

class Dog : public Animal{
public:
    Dog(std::string dog_name) : Animal(dog_name){
    }

    void bark(){
        std::cout << name_ << " is barking." << std::endl;
    }

    // override the base version
    void sleep() override{
        std::cout << name_ << " is snoring while sleeping." << std::endl;
    }
};


int main(){

    // stack object
    Dog d1("Boncuk");
    d1.eat();
    d1.bark();
    d1.sleep();

    // stack object
    Animal a1("Kertenkele");
    a1.sleep(); 

    // stack pointer
    Dog d2("Cesur");
    Dog *d2_ptr = &d2;
    d2_ptr->sleep();

    // raw heap pointer
    Animal *a2 = new Animal("Sincap");
    a2->sleep();
    delete a2;

    // smart pointer (heap)
    std::unique_ptr<Animal> a3 = std::make_unique<Animal>("Fare");
    a3->sleep();

    return 0;
}