#include <iostream>
#include <cstdint> 


struct Vector2{
    float x, y;

    Vector2 operator +(const Vector2& other){
        return {x+other.x, y+other.y};
    }

    Vector2 operator *(const Vector2& other){
        return {x*other.x, y*other.y};
    }

    bool operator ==(const Vector2& other){
        return (x == other.x && y == other.y);
    }
};


uint32_t s_AllocCount = 0;
void* operator new(size_t size){
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size); // what default new function do
}


int main(){
    Vector2 v1 = {1.0, 2.0};
    Vector2 v2 = {3.0, 4.0};

    Vector2 v3 = v1 + v2; // Vector2 v3 = v1.operator+(v2)
    std::cout << "V3-x: " << v3.x << ", V3-y: " << v3.y << std::endl; 
    std::cout << "v1 == v2: " << (v1 == v2) << "\n" << std::endl;

    int* pi = new int(76);
    double* pd = new double(76.85);

    return 0;
}
