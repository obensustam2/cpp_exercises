#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

class Account{
private:
    std::string name;
    double balance;

public:
    std::string get_name();
    double get_balance();
    void set_name(std::string);
    void set_balance(double);
    bool deposit(double);
    bool withdraw(double);
    
    
};


#endif // _ACCOUNT_H_