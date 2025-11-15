#include <iostream>
#include <string>

class Entity{
protected:    
    int X, Y;
     
    void print(){
        std::cout << "Hello" << std::endl;
    }

public:
    Entity(){
        X = 0;   
    }
};

class Player : public Entity{
public:
    Player(){
        X = 2;
        print();
    }
};

int main(){
    Entity e;

    // e.print();
    // e.X = 5;
    
    return 0;
}