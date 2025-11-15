#include <iostream>
#include <string>


class Printable{
public:
    virtual std::string getClassName() = 0;
};


class Entity3 : public Printable{
public:
    std::string getClassName() override{
        return "Entity3";
    }
};


class Entity4 : public Printable{
public:
    std::string getClassName() override{
        return "Entity4";
    }
};


class Entity5 : public Printable{
};


void printName(Printable *obj){
    std::cout << "Object address: " << obj << std::endl;
    std::cout << obj->getClassName() << std::endl;
}


// MAIN
int main(){
    Entity3 *entity3 = new Entity3();
    printName(entity3);

    Entity4 *entity4 = new Entity4();
    printName(entity4);

    // Entity5 *entity5 = new Entity5();
    // printName(entity5);

    return 0;
}