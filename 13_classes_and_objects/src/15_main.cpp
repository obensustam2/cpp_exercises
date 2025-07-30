#include "15_player.h"


void display_active_players(){
   std::cout << "Active players: " << Player::get_num_players() << std::endl;
}

int main(){

    display_active_players(); // 0

    {
        Player hero("Hero");
        Player hero2("Hero2");
        display_active_players(); // 2
    } // hero and hero2 go out of scope *here*

    display_active_players(); // now it will print 0 again

    Player *enemy = new Player("Enemy", 100, 100);
    display_active_players();
    delete enemy;
    display_active_players();
    
    Player my_hero("Oben");
    Player copy_hero(my_hero);
    display_active_players();

    return 0;
}