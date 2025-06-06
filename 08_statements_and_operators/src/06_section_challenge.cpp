#include <iostream>

int main(){

    int total_cents = 0;

    int dollars = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    int remaning_amount = 0;

    std::cout << "Enter an amount in cents: ";
    std::cin >> total_cents;

    dollars = total_cents / 100;
    remaning_amount = total_cents % 100;

    quarters = remaning_amount / 25;
    remaning_amount = remaning_amount % 25;

    dimes = remaning_amount / 10;
    remaning_amount = remaning_amount % 10;

    nickels = remaning_amount / 5;
    remaning_amount = remaning_amount % 5;

    pennies = remaning_amount;

    std::cout << "dollars: " << dollars << std::endl;
    std::cout << "quarters: " << quarters << std::endl;
    std::cout << "dimes: " << dimes << std::endl;
    std::cout << "nickels: " << nickels << std::endl;
    std::cout << "pennies: " << pennies << std::endl;

    return 0;
}