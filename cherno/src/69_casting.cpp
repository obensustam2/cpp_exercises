#include <iostream>
#include <string>


class Animal {
public:
    virtual ~Animal() {}   // <-- this is enough to enable RTTI
    virtual void speak(){
        std::cout << "basic animal" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "dog havs" << std::endl;
    }
    void fetch() {
        std::cout << "dog fetched the ball" << std::endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "cat maews" << std::endl;
    }
    void purr() {}
};



void legacyProcess(std::string& str) {
    std::cout << "Processing: " << str << std::endl;
}


struct Entity{
    int x, y;
};


int main(){

    // static_cast
    float pi = 3.14;
    int x = static_cast<int>(pi);
    std::cout << x << std::endl;


    // dynamic_cast
    Animal* a1 = new Dog();
    a1->speak();

    Animal* a2 = new Cat();
    a2->speak();

    Dog* d1 = dynamic_cast<Dog*>(a1);
    if (d1){
        std::cout << "d1: ";
        d1->fetch();
    }
    else{
        std::cout << "nullptr" << std::endl;
    }

    Dog* d2 = dynamic_cast<Dog*>(a2); // no direct connection from Cat to Dog
    if (d2){
        std::cout << "d2: ";
        d2->fetch();
    }
    else{
        std::cout << "nullptr" << std::endl;
    }


    // const_cast
    const std::string message = "Hello, World!";
    // legacyProcess(message);  // ERROR: cannot bind non-const ref to const object
    legacyProcess(const_cast<std::string&>(message));


    // reinterpret_cast
    Entity e;
    e.x = 3;
    e.y = 5;

    int* position = reinterpret_cast<int*>(&e);

    std::cout << position[0] << "\n"; // 3  → reads e.x
    std::cout << position[1] << "\n"; // 5  → reads e.y

    return 0;
}
