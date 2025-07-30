#include "04_account.h"

void Account::set_name(std::string n){
    name = n;
}

std::string Account::get_name(){
    return name;
}

bool Account::deposit(double dep){
    balance += dep;
    return true;
}

bool Account::withdraw(double with){
    if(balance-with >= 0){
        balance -= with;
        return 1;
    }
    else{
        return 0;
    }
}

void Account::set_balance(double bal){
    balance = bal;
}

double Account::get_balance(){
    return balance;
}