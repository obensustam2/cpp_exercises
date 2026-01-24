#include <iostream>
#include <string>

const int age = 30;
// age = 31; // ❌ Error! Cannot modify

class Person {
    std::string name;
public:
    Person(std::string n) : name(n) {}

    void printName() const {   // ✅ const member function
        // name += "!"; // ❌ Error
        std::cout << name << std::endl;
    }

    void changeName(std::string n) {  // Non-const
        name = n;
    }
};

int main(){
    Person p("Oben");
    p.changeName("Sustam");
    p.printName();

    return 0;
}