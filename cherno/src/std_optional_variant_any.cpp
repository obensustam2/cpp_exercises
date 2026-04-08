
#include <iostream>
#include <optional>
#include <variant>
#include <string>
#include <any>


union Uni {
    int i;
    double d;
    bool b;
};


// Enum
enum class Season {
    Spring,
    Summer,
    Autumn,
    Winter
};

std::string seasonMessage(Season s){
    switch(s){
        case Season::Spring:
            return "Flowers blooming";
        case Season::Summer:
            return "Hot and sunny";
        case Season::Autumn:
            return "Leaves falling";
        case Season::Winter:
            return "Cold and snowy"; 
    }
    return "Unknown season";
}


void doMath(int a, int b) {

    auto add = [a, b]() {
        return a + b;
    };

    auto multiply = [a, b]() {
        return a * b;
    };

    std::cout << "Add:      " << add()      << std::endl;
    std::cout << "Multiply: " << multiply() << std::endl;
}

int main(){
    // enum class
    Season current = Season::Spring;
    std::cout << seasonMessage(current) << std::endl;

    std::cout << "--------------" << std::endl;


    // std::optional
    std::optional<int> opt = 5;
    opt = std::nullopt;

    if(opt.has_value()){
        std::cout << opt.value() << std::endl;
    }
    else{
        std::cout << "Opt has no value" << std::endl;
        std::cout << opt.value_or(7) << std::endl;
    }

    std::cout << "--------------" << std::endl;


    //union
    Uni uni;
    uni.i = 88;
    uni.d = 90.55;
    std::cout << uni.i << std::endl;
    std::cout << uni.d << std::endl;

    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << sizeof(bool) << std::endl;
    std::cout << sizeof(Uni) << std::endl;

    std::cout << "--------------" << std::endl;


    // std::variant
    std::variant<int, std::string, double> var;
    var = "Oben";
    // var = 90.56;
    std::cout << sizeof(var) << std::endl;
    std::cout << var.index() << std::endl;

    std::string* isString = std::get_if<std::string>(&var);
    if (isString != nullptr){
        std::cout << std::get<std::string>(var) << std::endl;
    }
    else{
        std::cout << "Variant doesn't hold std::string now" << std::endl;
    }

    std::cout << "--------------" << std::endl;


    // lambda
    doMath(4, 6);

    std::cout << "--------------" << std::endl;



    // std::any
    std::any anyy;
    anyy = 77;
    int* isInt = std::any_cast<int>(&anyy);
    double* isDouble = std::any_cast<double>(&anyy);

    if(isInt){
        std::cout << "isInt" << std::endl;
        std::cout << std::any_cast<int>(anyy) << std::endl;
        std::cout << (anyy.type() == typeid(int)) << std::endl;
    }

    if(isDouble){
        std::cout << "isDouble" << std::endl;
        std::cout << std::any_cast<double>(anyy) << std::endl;
        std::cout << (anyy.type() == typeid(double)) << std::endl;
    }

    std::string name = "Oben";
    std::cout << typeid(name).name() << std::endl;
    



    
    return 0;
}