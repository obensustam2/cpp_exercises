#include "18_classes.h"

int main(){
    Account n26;
    n26.set_name("Oben");
    n26.set_balance(1000);
    std::cout << "Account holder: " << n26.get_name() << std::endl;
    std::cout << "Account balance: " << n26.get_balance() << std::endl;

    n26.deposit(500);
    std::cout << "Balance after deposit: " << n26.get_balance() << std::endl;

    if(n26.withdraw(2200)){
        std::cout << "Balance after withdraw: " << n26.get_balance() << std::endl;
    }
    else{
        std::cout << "Not enough money in account" << std::endl;
    }

    return 0;
}