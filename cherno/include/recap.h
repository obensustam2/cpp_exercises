#ifndef RECAP
#define RECAP

#include <iostream>
#include <string>
#include <vector>

class Animal{
private:
    std::string breed;
    std::vector<std::string> skills;

protected:
    int age;

public:
    Animal(int _age, std::string _breed, std::vector<std::string> _skills);
    virtual void set_age(int new_age);
    int get_age();
    void add_skills(std::string new_skill);
    std::vector<std::string> get_skills();
    void print_skills();
};

class Zebra : public Animal{
public:
    Zebra(int _age, std::string _breed, std::vector<std::string> _skills) : 
        Animal(_age,_breed, _skills){
    }

    void set_age(int age_) override;    
};

#endif // RECAP