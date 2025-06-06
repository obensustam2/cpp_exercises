#include <iostream>

int main(){
    int package_length, package_width, package_height;
    std::cout << "Enter package dimensions which are length, width and height in order (inches): ";
    std::cin >> package_length >> package_width >> package_height ;

    int max_length_per_dimension = 10;

    if (package_length > max_length_per_dimension || package_width > max_length_per_dimension || package_height > max_length_per_dimension){
        std::cout << "We can't ship when one dimension or more is higher than 10 inches" << std::endl;
    }

    else {
        double base_cost = 2.50 ;
        int volume = package_length * package_width * package_height;
        std::cout << "Package volume is: " << volume << std::endl;

        double tier1_surcharge = 0.1;
        double tier2_surcharge = 0.25;
        
        int tier1_threshold = 100;
        int tier2_threshold = 500;

        double package_cost = base_cost;

        if (volume > tier2_threshold){
            std::cout << "Adding tier 2 surcharge" << std::endl;
            package_cost += package_cost*tier2_surcharge;
        }
        else if (volume > tier1_threshold){
            std::cout << "Adding tier 1 surcharge" << std::endl;
            package_cost += package_cost*tier1_surcharge; 
        }

        std::cout << "Package costs $" << package_cost << std::endl;
    }

    return 0;
}