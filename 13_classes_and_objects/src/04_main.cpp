#include "04_account.h"

int main(){
    Account n26;
    n26.set_name("Oben Sustam");
    n26.set_balance(1000);
    std::cout << "Username: " << n26.get_name() << std::endl;
    std::cout << "Balance: " << n26.get_balance() << std::endl;
    n26.deposit(500);
    std::cout << "Balance after deposit: " << n26.get_balance() << std::endl;

    if(n26.withdraw(200)){
        std::cout << "Balance after withdraw: " << n26.get_balance() << std::endl;
    }
    else{
        std::cout << "Not enough money" << std::endl;
    }

    if(n26.withdraw(2200)){
        std::cout << "Balance after withdraw: " << n26.get_balance() << std::endl;
    }
    else{
        std::cout << "Not enough money" << std::endl;
    }

    return 0;
}