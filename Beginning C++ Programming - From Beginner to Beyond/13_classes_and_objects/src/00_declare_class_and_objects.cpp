#include <iostream>
#include <string>
#include <vector>


class Player{
    // attributes
    std::string name = "Player";
    int health = 100;
    int experience = 0;

    // methods
    void talk(std::string);
    bool is_dead();
};


class Account{
    // attributes
    std::string name = "Account";
    double balance = 0.0;

    // methods
    bool deposit(double);
    bool withdraw(double);
};


int main (){
    Player frank;
    Player hero;

    // array of objects
    Player players[] = {frank, hero};

    // vector of objects
    std::vector<Player> player_vec = {frank};
    player_vec.push_back(hero);
    
    // heap
    Player *enemy = nullptr;
    enemy = new Player;
    delete enemy;


    Account frank_account;
    Account hero_account;

    return 0;
}