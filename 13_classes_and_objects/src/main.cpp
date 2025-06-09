#include "account.h"
#include <iostream>


int main(){

    Account n26;
    n26.set_name("Oben Main Account");
    n26.set_balance(1000.0);
    double my_balance = n26.get_balance();
    std::cout << "My current balance is " << my_balance << std::endl;

    if (n26.deposit(200.0)){
        std::cout << "Deposit OK" << std::endl;
    }
    else{
        std::cout << "Deposit not allowed" << std::endl;
    }

    if (n26.withdraw(500.0)){
        std::cout << "Withdraw OK" << std::endl;
    }
    else{
        std::cout << "Not sufficient funds" << std::endl;
    }

    if (n26.withdraw(1500.0)){
        std::cout << "Withdraw OK" << std::endl;
    }
    else{
        std::cout << "Not sufficient funds" << std::endl;
    }

    return 0;
}