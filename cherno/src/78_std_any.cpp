#include <iostream>
#include <any>
#include <string>

int main() {

    std::any a;

    a = 42;
    std::cout << std::any_cast<int>(a) << std::endl;      // 42

    a = 3.14;
    std::cout << std::any_cast<double>(a) << std::endl;   // 3.14

    a = std::string("Oben");
    std::cout << std::any_cast<std::string>(a) << std::endl; // Oben

    // safe check before casting
    if (a.has_value()) {
        std::cout << "a has a value" << std::endl;
    }

    // check the type
    if (a.type() == typeid(std::string)) {
        std::cout << "a is a string" << std::endl;
    }

    // wrong cast — throws std::bad_any_cast
    try {
        int x = std::any_cast<int>(a);  // a holds string, not int
    } catch (const std::bad_any_cast& e) {
        std::cout << "bad cast: " << e.what() << std::endl;
    }

    // clear it
    a.reset();
    std::cout << "has value after reset: " << a.has_value() << std::endl; // 0

    return 0;
}