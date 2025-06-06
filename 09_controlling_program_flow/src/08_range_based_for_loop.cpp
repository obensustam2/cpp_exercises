#include <iostream>
#include <vector>
#include <iomanip>

int main() {

    // int scores [] = {10,20,30};
    // for (auto score : scores){
    //     std::cout << score << std::endl;
    // }


    // double sum = 0.0;
    // std::vector <double> temperatures = {22.33, 15.66, 40.44} ;
    // for (double temperature : temperatures){
    //     sum += temperature;
    // }
    // if (temperatures.size() != 0){
    //     std::cout << std::fixed << std::setprecision(2) ;
    //     std::cout << "Average: " << sum/temperatures.size() << std::endl;
    // }


    // for (auto val : {1,2,3,4,5}){
    //     std::cout << val << std::endl;
    // }


    // for (auto c: "This is a test"){
    //     if (c != ' '){
    //         std::cout << c;
    //     }
    // }
    // std::cout << std::endl;


    for (auto c: "This is a test"){
        if (c == ' '){
            std::cout << "\t";
        }
        else{
            std::cout << c;
        }
    }
    std::cout << std::endl;







    return 0;
}