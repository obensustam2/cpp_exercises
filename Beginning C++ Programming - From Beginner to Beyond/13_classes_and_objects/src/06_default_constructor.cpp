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
        name = "None";
        health = 100;
        xp = 3;
    }

    Player(std::string name_val, int health_val, int xp_val){
        name = name_val;
        health = health_val;
        xp_val = xp_val;
    }

    Player(std::string);
};

Player::Player(std::string name_){
    name = name_;
}


int main(){
    Player frank;
    frank.set_name("Frank");
    std::cout << frank.get_name() << std::endl;

    Player oben("Oben", 50, 5);
    std::cout << oben.get_name() << std::endl;

    Player orhan("Orhan");
    std::cout << orhan.get_name() << std::endl;



    return 0;
}