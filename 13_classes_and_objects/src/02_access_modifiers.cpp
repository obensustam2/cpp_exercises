#include <iostream>
#include <string>

class Player{
private:
    std::string name = "Oben";
    int health;
    int xp;
public:
    void talk(std::string text_to_say){ std::cout << name << " says " << text_to_say << std::endl;}
    bool is_dead();
};

int main(){
    Player oben;
    oben.talk("hello");
    return 0;
}