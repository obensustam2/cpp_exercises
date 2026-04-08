#include <iostream>
#include <string>



uint32_t s_AllocCount = 0;
void* operator new(size_t size){
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size); // what default new function do
}


void printName(std::string_view name){
    std::cout << name << std::endl;
}

int main(){
    

#if 0
    std::string full_name = "Msc. Eng. Oben Sustam - Robotics Engineer - Munich";
    std::string first_part = full_name.substr(0, 21);
    std::string second_part = full_name.substr(22, 35);
    printName(full_name);   
    printName(first_part);    
    printName(second_part);    
#elif 1
    std::string full_name = "Msc. Eng. Oben Sustam - Robotics Engineer - Munich";
    const char* name_ptr = full_name.c_str(); // c_str(): c string pointer, converts std::string to c style string
    std::string_view first_part(name_ptr, 21); 
    std::string_view second_part(name_ptr + 22, 35);
    printName(full_name); 
    printName(first_part);
    printName(second_part);
#else
    const char* name_ptr = "Msc. Eng. Oben Sustam - Robotics Engineer - Munich";
    std::string_view first_part(name_ptr, 21);
    std::string_view second_part(name_ptr + 22, 35);
    printName(name_ptr); 
    printName(first_part);
    printName(second_part);
#endif

    return 0;
}