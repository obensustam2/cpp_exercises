#include <iostream>
#include <string>

class Entity;
void printEntity(Entity &e);

class Entity{
public:
    int x, y;

    Entity(int x, int y) {  
        this->x = x;
        this->y = y;
    
        printEntity(*this);
    }

    int get_x() const{
        return this->x;
    }
};

void printEntity(Entity &e){
    std::cout << e.x << ", " << e.y << std::endl;
}

int main(){
    Entity e1(3,5);

    return 0;
}