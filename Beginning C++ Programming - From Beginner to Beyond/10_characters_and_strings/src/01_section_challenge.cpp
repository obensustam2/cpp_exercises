#include <iostream>
#include <string>

int main(){

    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string key = "XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr";

    std::string user_input;
    std::cout << "Enter your secret message: ";
    std::getline(std::cin, user_input);
    std::string output_en = user_input;

    for (int i=0; i<user_input.length();i++){
        int index = alphabet.find(user_input.at(i));
        if (index != key.length()){
            output_en.at(i) = key.at(index);
        }
        else{
            output_en.at(i) = user_input.at(i);
        }
    } 
    std::cout << "Encrypted Meesage: " << output_en << std::endl;


    std::string output_de = output_en;
    for (int i=0; i<output_de.length();i++){
        int index_de = key.find(output_de.at(i));
        if (index_de < key.length()){
            output_de.at(i) = alphabet.at(index_de);
        }
        else{
            output_de.at(i) = output_en.at(i);
        }
    }  
    std::cout << "Decrypted Message: " << output_de << std::endl;

    return 0;
}