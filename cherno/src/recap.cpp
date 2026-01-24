#include "recap.h"

Animal::Animal(int _age, std::string _breed, std::vector<std::string> _skills) : 
    age(_age), breed(_breed), skills(_skills) {
}

void Animal::set_age(int new_age){
    age = new_age;
}

int Animal::get_age(){
    return age;
}

void Animal::add_skills(std::string new_skill){
    skills.emplace_back(new_skill);
}

std::vector<std::string> Animal::get_skills(){
    return skills;
}

void Animal::print_skills(){
    for(int i=0; i< get_skills().size(); i++){
        std::cout << "Skill "  << i+1 << ": " << get_skills()[i] << std::endl;
    }
}

void Zebra::set_age(int age_){
    age = age_ + 5;
}

int main(){
    Animal monkey(29, "orangutan", {"coding", "peeing"});
    
    std::cout << "Inital Age: " << monkey.get_age() << std::endl;

    monkey.set_age(30);
    std::cout << "New Age: " << monkey.get_age() << std::endl;
    
    monkey.print_skills();

    monkey.add_skills("passing interview");

    monkey.print_skills();

    Zebra z1(10, "african zebra", {"jumping", "running"});
    z1.set_age(15);
    std::cout << "New Age Zebra: " << z1.get_age() << std::endl;

    return 0;
}