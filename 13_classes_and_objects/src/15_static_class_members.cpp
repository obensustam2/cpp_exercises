#include "15_player.h"


int Player::num_players = 0;

std::string Player::get_name(){
    return name;
}

int Player::get_health(){
    return health;
}

int Player::get_xp(){
    return xp;
}

Player::Player(std::string name_val, int health_val, int xp_val) :
    name(name_val), health(health_val), xp(xp_val){
    num_players += 1;
    std::cout << "Constructor" << std::endl;
}

Player::Player(const Player &source) : 
    Player(source.name, source.health, source.xp){ // delegating to constructor
    std::cout << "Deep Copy Constructor" << std::endl;
}

Player::~Player(){
    num_players -= 1;
    std::cout << "Destructor for: " << name << std::endl;
}

int Player::get_num_players(){
    return num_players;
}


