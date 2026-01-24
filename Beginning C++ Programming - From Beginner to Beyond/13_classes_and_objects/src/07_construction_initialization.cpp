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

    //Overloaded Constructors
    Player();
    Player(std::string name_val);
    Player(std::string name_val, int health_val, int xp_val);
};

Player::Player() : 
    name("Oben"), health(99), xp(29) {
}

Player::Player(std::string name_val) : 
    name(name_val), health(80), xp(22){
}

Player::Player(std::string name_val, int health_val, int xp_val) : 
    name(name_val), health(health_val), xp(xp_val) {
}

int main(){

    Player first_player;
    std::cout << first_player.get_name() << std::endl;
    std::cout << first_player.get_health() << std::endl;

    Player second_player("Orbay");
    std::cout << "\n" << second_player.get_name() << std::endl;
    std::cout << second_player.get_health() << std::endl;

    Player third_player("Orcun", 100, 20);
    std::cout << "\n" << third_player.get_name() << std::endl;
    std::cout << third_player.get_health() << std::endl;

    return 0;
}