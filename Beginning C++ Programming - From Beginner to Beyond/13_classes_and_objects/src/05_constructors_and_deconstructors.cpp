#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    int health;
    int xp;

public:
    void set_name(std::string new_name){
        name = new_name;
    }

    std::string get_name(){
        return name;
    }

    Player(){
        std::cout << "No args constructor is called" << name << std::endl;
    }

    Player(std::string init_name){
        name = init_name;
        std::cout << "String arg constructor is called for " << name << std::endl;
    }

    Player(std::string init_name, int init_health, int init_xp){
        name = init_name;
        health = init_health;
        xp = init_xp;
        std::cout << "Three args constructor is called for " << name << std::endl;
    }

    ~Player(){
        std::cout << "Deconstructor called for " << name << std::endl;
    }
};


int main(){
    Player oben("Oben");
    Player orbay("Orbay", 100, 10);
    Player orcun;
    orcun.set_name("Orcun");

    Player *tenzile = new Player("Tenzile");
    Player *orhan = new Player;
    orhan->set_name("Orhan");
    
    delete tenzile;
    delete orhan;


    return 0;
}