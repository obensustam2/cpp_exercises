#include <iostream>

int main(){

    std::cout << "Hello, welcome to Frank's Carpet Cleaning Service" << std::endl;
    
    int num_rooms = 0;
    std::cout << "How many rooms do you want to be cleaned? ";
    std::cin >> num_rooms;
    std::cout << "Selected number of rooms: " << num_rooms << std::endl;

    const int price_per_room = 30;
    std::cout << "Price per room: " << price_per_room << std::endl;
    std::cout << "Total Cost: " << num_rooms * price_per_room << std::endl;

    const double tax_rate = 0.06;
    std::cout << "Tax: " << num_rooms * price_per_room * tax_rate << std::endl;
    
    std::cout << "Total Estimate: " << (num_rooms * price_per_room) + (num_rooms * price_per_room * tax_rate) << std::endl;

    const int valid_days = 30; 
    std::cout << "The estimate is valid for 30 days";
    std::cout << "The estimate is valid for: " << valid_days << " days." << std::endl;

    return 0;
}
