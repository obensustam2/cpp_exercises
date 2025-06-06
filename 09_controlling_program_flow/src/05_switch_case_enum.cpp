#include <iostream>


int main(){

    enum Direction {
        left, right, up, down
    };

    Direction heading = up;

    switch (heading)
    {
        case left:
            std::cout << "Going left" << std::endl;
            break;
    
        case right:
            std::cout << "Going right" << std::endl;
            break;

        default:
            std::cout << "Not going right or left" << std::endl;
    }


    return 0;
}