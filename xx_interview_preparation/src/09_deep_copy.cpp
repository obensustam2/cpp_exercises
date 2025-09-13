#include <iostream>
#include <cstring>

class Car{
private:
    char *model_;
    int year_;

public:
    Car(const char *model, int year) : year_(year){
        model_ = new char[strlen(model) + 1];
        strcpy(model_, model);
        std::cout << "Car created: " << model_ << std::endl;
    }

    // Deep Copy
    Car(const Car &other) : year_(other.year_){
        model_ = new char[strlen(other.model_) + 1];
        strcpy(model_, other.model_);  
        std::cout << "Deep copy car created: " << model_ << std::endl;
    }

    ~Car(){
        std::cout << "Deleting car: " << model_ << std::endl;
        delete[] model_;
    }

    void set_year(int new_year){
        year_ = new_year;
    }

    void print() { 
        std::cout << "Model: " << model_ << ", Year: " << year_ << std::endl; 
    } 
};


int main(){
    Car c1("Audi", 1996);

    Car c2 = c1;
    c2.set_year(2000);

    c1.print();
    c2.print();

    return 0;
}