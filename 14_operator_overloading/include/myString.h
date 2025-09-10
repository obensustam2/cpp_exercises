#ifndef MY_STRING_H
#define MY_STRING_H

#include <iostream>
#include <cstring>

class MyString{
private: 
    char *str; // pointer to char[] that holds a C-style string
public:
    MyString(); // No-args constructor
    MyString(const char *s); // Overloaded constructor
    MyString(const MyString &source); // Copy constructor
    ~MyString();
    void display() const;
    int get_length() const; // getters 
    const char *get_str() const;

};


#endif // MY_STRING_H
