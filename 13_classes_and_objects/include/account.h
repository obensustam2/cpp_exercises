#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>
#include <iostream>

class Account{
private:
    std::string name;
    double balance;

public:
    void set_balance(double bal);
    double get_balance();
    void set_name(std::string name);
    std::string get_name();
    bool deposit(double amount);
    bool withdraw(double amount);
};


#endif // _ACCOUNT_H_