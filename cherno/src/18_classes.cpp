#include "18_classes.h"


std::string Account::get_name(){
    return name;
}

void Account::set_name(std::string new_name){
    name = new_name;
}

double Account::get_balance(){
    return balance;
}

void Account::set_balance(double new_balance){
    balance = new_balance;
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

bool Account::withdraw(double amount){
    if (balance-amount < 0){
        return false;
    }
    else{
        balance -= amount;
        return true;
    }
}

