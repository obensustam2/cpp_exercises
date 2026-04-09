#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


enum class FSTREAM_OP{
    READ_BY_WORD,
    READ_BY_LINE,
    READ_ENTIRE,
    WRITE,
    APPEND,
    READ_WRITE
};

int main(){
    
    FSTREAM_OP selection = FSTREAM_OP::READ_WRITE;

    switch (selection){

        // Reading word by word
        case (FSTREAM_OP::READ_BY_WORD): {
            std::ifstream file("/home/oben/Projects/cpp_exercises/cherno/config/input.txt");
            std::string word;
            if (file.is_open()) {
                while (file >> word) {
                    std::cout << word << std::endl;
                }
            } else {
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        // Reading line by line
        case (FSTREAM_OP::READ_BY_LINE): { 
            std::ifstream file("/home/oben/Projects/cpp_exercises/cherno/config/input.txt");
            std::string line;
            if(file.is_open()){
                while(std::getline(file, line)){
                    std::cout << line << std::endl;
                }
            }
            else{
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        // Reading entire file into a string
        case (FSTREAM_OP::READ_ENTIRE): { 
            std::ifstream file("/home/oben/Projects/cpp_exercises/cherno/config/input.txt");
            std::ostringstream buffer; //sstream definition
            if(file.is_open()){
                buffer << file.rdbuf();
                std::string content = buffer.str();
                std::cout << content << std::endl;
            }
            else{
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        // Writing into a new file
        case (FSTREAM_OP::WRITE): {
            std::ofstream outFile("/home/oben/Projects/cpp_exercises/cherno/config/output.txt");
            if(outFile.is_open()){
                outFile << "Hello World\n";
                outFile << "Second Line\n";
                std::cout << "File written succesfully" << std::endl;
            }
            else{
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        // Appending to a file
        case (FSTREAM_OP::APPEND): {
            std::ofstream appendFile("/home/oben/Projects/cpp_exercises/cherno/config/output.txt", std::ios::app);
            if(appendFile.is_open()){
                appendFile << "Appended Line\n";
                std::cout << "File appended successfully" << std::endl;
            }
            else{
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        // Reading and writing the same file
        case (FSTREAM_OP::READ_WRITE): {
            std::fstream rwFile("/home/oben/Projects/cpp_exercises/cherno/config/output.txt", 
                std::ios::in | std::ios::out | std::ios::app);
            if(rwFile.is_open()){
                rwFile << "Read/Write Line\n";
                rwFile.seekg(0); // seek back to beginning for reading
                std::string line;
                while(std::getline(rwFile, line)){
                    std::cout << line << std::endl;
                }
            }
            else{
                std::cout << "File not opened" << std::endl;
            }
            break;
        }

        default:
            std::cout << "Default" << std::endl;
            break;
    }

    return 0;
}




    