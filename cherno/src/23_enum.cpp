#include <iostream>

enum Direction{
    North,
    East,
    South,
    West
};

int main(){
    Direction dir = South;

    if(dir == South){
        std::cout << "Going South" << std::endl;
    }

    std::cout << "Direction Value: " << dir << std::endl;

    return 0;
}