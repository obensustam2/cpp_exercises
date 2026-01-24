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
        std::cout << "Health: " << health << std::endl;
        return health;
    }

    void set_health(int new_health){
        health = new_health;
    }

    int get_xp(){
        return xp;
    }

    // Constructor
    Player(std::string name_val = "None", int health_val = 13, int xp_val = 56) : 
        name(name_val), health(health_val), xp(xp_val){
        std::cout << "\nCreated Player object with " << name << " name" << std::endl;
    }

    // Copy Constructor
    Player(const Player &source) : name(source.name), health(source.health), xp(source.xp){
        std::cout << "\nMade copy of Player object with " << source.name << " name" << std::endl;
    }

    // Destructor
    ~Player(){
        std::cout << "\nDestructor called for the object with " << name << " name" << std::endl;
    }
};



void display_player(Player p){
    std::cout << "\nName: " << p.get_name() << std::endl;
    std::cout << "Health: " << p.get_health() << std::endl;
    std::cout << "XP: " << p.get_xp() << std::endl;
}

int main(){

    Player first_player("Oben");
    first_player.set_health(100);
    first_player.get_health();
    // display_player(first_player);

    Player new_player(first_player);
    new_player.get_health();

    return 0;
}