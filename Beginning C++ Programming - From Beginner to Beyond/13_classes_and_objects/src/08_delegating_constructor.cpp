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

Player::Player() : Player("Oben", 99, 29) {
    std::cout << "No args constructor" << std::endl;
}

Player::Player(std::string name_val) : Player(name_val, 100, 22) {
    std::cout << "One arg constructor" << std::endl;
}

Player::Player(std::string name_val, int health_val, int xp_val) : 
    name(name_val), health(health_val), xp(xp_val) {
    std::cout << "\nThree args constructor" << std::endl;
}

int main(){

    Player first_player;
    std::cout << first_player.get_name() << std::endl;
    std::cout << first_player.get_health() << std::endl;

    Player second_player("Orbay");
    std::cout << second_player.get_name() << std::endl;
    std::cout << second_player.get_health() << std::endl;

    Player third_player("Orcun", 100, 20);
    std::cout << third_player.get_name() << std::endl;
    std::cout << third_player.get_health() << std::endl;

    return 0;
}