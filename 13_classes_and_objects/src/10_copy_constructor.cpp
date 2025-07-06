#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    int health;
    int xp;

public:
    std::string get_name(){
        return name;
    }

    int get_health(){
        return health;
    }

    int get_xp(){
        return xp;
    }

    // Constructor
    Player(std::string name_val = "None", int health_val = 13, int xp_val = 56) : 
        name(name_val), health(health_val), xp(xp_val){
    }

    // Copy Constructor
    Player(const Player &source) : name(source.name), health(source.health), xp(source.xp){
        std::cout << "\nMade copy of " << source.name << std::endl;
    }

    // Destructor
    ~Player(){
        std::cout << "Destructor called " << name << std::endl;
    }
};



void display_player(Player p){
    std::cout << "Name: " << p.get_name() << std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "XP: " << p.get_xp() << std::endl;
}

int main(){

    Player first_player;
    display_player(first_player);

    Player new_object(first_player);

    return 0;
}