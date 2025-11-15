#include <iostream>
#include <string>

// NO VIRTUAL FUNCTION
class Entity1{
public: 
    std::string getName(){
        return "Entity1";
    }
};

class Player1 : public Entity1{
private:
    std::string m_name;

public:
    Player1(const std::string &name) 
        : m_name(name){
    }

    std::string getName(){
        return m_name;
    } 
};

void printName1(Entity1 *entity1){
    std::cout << entity1->getName() << std::endl;
} 



// WITH VIRTUAL FUNCTION
class Entity2{
public:
    virtual std::string getName(){
        return "Entity2";
    }
};

class Player2 : public Entity2{
private:
    std::string m_name;

public:
    Player2(const std::string &name)
        : m_name(name){
    }

    std::string getName() override{
        return m_name;
    }
};

void printName2(Entity2 *entity2){
    std::cout << entity2->getName() << std::endl;
}


// MAIN
int main(){
    std::cout << "Without Virtual Function" << std::endl;
    Entity1 *my_entity1 = new Entity1();
    printName1(my_entity1); 

    Player1 *my_player1 = new Player1("Oben");
    printName1(my_player1);
    

    std::cout << "\nWith Virtual Function" << std::endl;
    Entity2 *my_entity2 = new Entity2();
    printName2(my_entity2);

    Player2 *my_player2 = new Player2("Oben2");
    printName2(my_player2);

    return 0;
}