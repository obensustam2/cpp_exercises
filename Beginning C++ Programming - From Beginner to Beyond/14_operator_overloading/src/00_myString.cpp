#include "myString.h"

// No-args constructor
MyString::MyString() : str(nullptr) {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
MyString::MyString(const char *s) : str(nullptr) {
    if(s==nullptr){
        str = new char[1];
        *str = '\0';
    } else{
        str = new char[std::strlen(s)+1];
        std::strcpy(str, s);
    }
} 

// Copy constructor
MyString::MyString(const MyString &source) : str(source.str){
    str = new char[std::strlen(source.str)+1];
    std::strcpy(str, source.str);
}

// Destructor 
MyString::~MyString(){
    delete [] str;
}

// Length getter
int MyString::get_length() const {
    return std::strlen(str);
}

// String getter
const char *MyString::get_str() const {
    return str;
}

// Display method
void MyString::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}


