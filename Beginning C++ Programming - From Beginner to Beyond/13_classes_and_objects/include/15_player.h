#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    int health;
    int xp;
    static int num_players; // shared by all objects of the class

public:
    std::string get_name();
    int get_health();
    int get_xp();

    Player(std::string name_val = "None", int health_val = 13, int xp_val = 56);
    Player(const Player &source);
    ~Player();

    static int get_num_players(); // I don't need an object to call this method
};


#endif // _PLAYER_H_