#include <iostream>
#include <string>

void employee_profile() {

    std::string name = "";
    std::cout << "Employee Name: ";
    std::cin >> name;

    int age = 0;
    std::cout << "Employee Age: ";
    std::cin >> age;
    
    double hourly_wage = 23.50;

    std::cout << name << " is " << age << " years old and makes " << hourly_wage << " per hour."<< std::endl;
}

int main(){
    employee_profile();
    return 0;
}
