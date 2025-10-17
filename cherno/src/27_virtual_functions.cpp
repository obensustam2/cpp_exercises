#include <iostream>
#include <string>

// NO VIRTUAL FUNCTION
class Entity1{
public: 
    std::string getName(){
        return "Entity";
    }
};

class Player1 : public Entity1{
private:
    std::string m_name;
public:
    Player1(const std::string &name) 
        : m_name(name){
    }
    std::string getName() {
        return m_name;
    }
};

void printName1(Entity1 *e){
    std::cout << e->getName() << std::endl;
}


// WITH VIRTUAL FUNCTION
class Entity2{
public: 
    virtual std::string getName(){
        return "Entity";
    }
};

class Player2 : public Entity2{
private:
    std::string m_name;
public:
    Player2(const std::string &name) 
        : m_name(name){
    }
    std::string getName() override {
        return m_name;
    }
};

void printName2(Entity2 *e){
    std::cout << e->getName() << std::endl;
}


// MAIN
int main(){
    Entity1 *e1 = new Entity1();
    Player1 *p1 = new Player1("New Player");

    printName1(e1); 
    printName1(p1); 

    Entity2 *e2 = new Entity2();
    Player2 *p2 = new Player2("New Player");

    printName2(e2); 
    printName2(p2); 

    return 0;
}