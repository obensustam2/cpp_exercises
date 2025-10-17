#include <iostream>

class Entity{
public:
    float X, Y;

    void move(float xa, float ya){
        X += xa;
        Y += ya;  
    }
};

class Player : public Entity{
public: 
    const char *name;

    void printName(){
        std::cout << name << std::endl;
    }

};

int main(){

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player p1;
    p1.name = "Oben";
    p1.move(5,5);
    std::cout << p1.X << std::endl;
    p1.printName();
    return 0;
}