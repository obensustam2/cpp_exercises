#include <iostream>
#include <string>
#include <tuple>

////////// TUPLE ////////////////
// Function returning tuple
std::tuple<std::string, int, float> tupleStudentData(){
    return {"Oben", 29, 1.4};
}

int tuple_solution(){
    // Modern C++17 way to unpack (Structured Bindings)
    auto [name, age, gpa] = tupleStudentData();
    
    // Older way (if you can't use C++17)
    // std::string n = std::get<0>(getStudentData());

    std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;

    return 0;
}


////////// STRUCT ////////////////
struct StudentData
{
    std::string name;
    int age;
    float gpa;
};


StudentData structStudentData(){
    return {"Verena", 28, 1};
}

int struct_solution(){
    StudentData s = structStudentData();

    std::cout << "Name: " << s.name << ", Age: " << s.age << ", GPA: " << s.gpa << std::endl;

    return 0;
}



int main(){

    tuple_solution();

    struct_solution();

    return 0;
}