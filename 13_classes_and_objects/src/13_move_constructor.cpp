#include <iostream>

class Number {
private:
    int* data;

public:
    // Constructor
    Number(int value) {
        data = new int(value);
        std::cout << "Constructor: allocated " << *data << ", at address: " << data << std::endl;
    }

    // Copy Constructor
    Number(const Number& source) {
        data = new int(*source.data);  // deep copy
        std::cout << "Copy Constructor: copied " << *data << ", at address: " << data << std::endl;
    }

    // ✅ Move Constructor
    Number(Number &&source) : data(source.data) {
        source.data = nullptr;  // steal ownership
        std::cout << "Move Constructor: ownership moved" << std::endl;
    }

    // Destructor
    ~Number() {
        if (data)
            std::cout << "Destructor: deleting " << *data << std::endl;
        else
            std::cout << "Destructor: nullptr — nothing to delete" << std::endl;

        delete data;
    }

    void print() const {
        if (data)
            std::cout << "Value: " << *data << std::endl;
        else
            std::cout << "No value (nullptr)" << std::endl;
    }
};

Number create_number() {
    Number temp(99);
    return std::move(temp);  // Forces move constructor
}


int main() {
    Number n1(10);          // Constructor
    Number n2 = n1;         // Copy constructor
    Number n3 = create_number();  // Move constructor

    std::cout << "n1: ";
    n1.print();

    std::cout << "n2: ";
    n2.print();

    std::cout << "n3: ";
    n3.print();

    return 0;
}
