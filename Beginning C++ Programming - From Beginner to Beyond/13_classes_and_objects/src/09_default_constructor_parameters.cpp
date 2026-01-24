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

    Player(std::string name_val = "None", int health_val = 13, int xp_val = 56) : 
        name(name_val), health(health_val), xp(xp_val){
    }
};




int main(){

    Player first_player;
    std::cout << first_player.get_name() << std::endl;
    std::cout << first_player.get_health() << std::endl;
    std::cout << first_player.get_xp() << std::endl;

    Player second_player("Orbay");
    std::cout << "\n" << second_player.get_name() << std::endl;
    std::cout << second_player.get_health() << std::endl;
    std::cout << second_player.get_xp() << std::endl;

    Player extra_player("Orhan", 20);
    std::cout << "\n" << extra_player.get_name() << std::endl;
    std::cout << extra_player.get_health() << std::endl;
    std::cout << extra_player.get_xp() << std::endl;

    Player third_player("Orcun", 100, 20);
    std::cout << "\n" << third_player.get_name() << std::endl;
    std::cout << third_player.get_health() << std::endl;
    std::cout << third_player.get_xp() << std::endl;



    return 0;
}