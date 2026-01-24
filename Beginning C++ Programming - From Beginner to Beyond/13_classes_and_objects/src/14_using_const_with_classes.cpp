#include <iostream>

class Account{ 
private:
    double balance;

public:
    Account(int balance_val) : 
        balance(balance_val){
    }

    void set_balance(double bal){
        balance = bal;
    }

    // const method
    double get_balance() const {
        return balance;
    }
};


int main (){

    Account n26(100);
    n26.set_balance(200);
    std::cout << n26.get_balance() << std::endl;

    const Account revolut(300);
    std::cout << revolut.get_balance() << std::endl;
    // revolut.set_balance(600); // COMPILER ERROR BECAUSE set_balance IS NOT CONST METHOD

    return 0;
}