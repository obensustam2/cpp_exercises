#include <iostream>
#include <optional>
#include <sstream>
#include <fstream>


std::optional<std::string> read_file(const std::string& path){
    std::ifstream file(path);

    if(!file.is_open()){
        return std::nullopt;
    }

    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}



int main(){
    std::optional<std::string> content = read_file("/home/oben/Projects/cpp_exercises/cherno/config/config.txt");

    if(!content.has_value()){
        std::cerr << "File not found/opened" << std::endl;
        return 1;
    }

    std::cout << *content << std::endl;

    return 0;
}