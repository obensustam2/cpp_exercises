#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float _x, float _y) : 
        x(_x), y(_y){
    }

    Vector2 add(const Vector2 &new_vector) const {
        return Vector2(x + new_vector.x, y + new_vector.y);
    }

    Vector2 operator+(const Vector2 &new_vector) {
        return add(new_vector);
    }

    Vector2 multiply(const Vector2 &new_vector) const {
        return Vector2(x * new_vector.x, y * new_vector.y);
    }

    Vector2 operator*(const Vector2 &new_vector) {
        return multiply(new_vector);
    }

};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other){
    stream << other.x << ", " << other.y;
    return stream;
} 

int main(){
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position.add(speed.multiply(powerup));
    Vector2 result2 = position + speed * powerup ;

    std::cout << result2 << std::endl;

    return 0;
}
