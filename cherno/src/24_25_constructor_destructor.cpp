#include <iostream>


class Entity{
private:
    float X, Y;

public:
    Entity(){
        X = 0.0f;
        Y = 0.0f;
        std::cout << "Created Entity!" << std::endl;
    }

    Entity(float x, float y){
        X = x;
        Y = y;
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity(){
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void print(){
        std:: cout << "X: " << X << " Y: " << Y << std::endl;
    }
};

int main(){
    Entity e1;
    e1.print();

    Entity e2(4,5);
    e2.print();

    return 0;
}