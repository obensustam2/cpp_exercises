#include <iostream>
#include <vector>

int main(){

    char key ;
    std::vector <int> my_vector = {}; 
    int sum = 0;
    int smallest_item = 0;
    int largest_item = 0; 
    
    do
    {    
        std::cout << "P for display vector" << std::endl;
        std::cout << "A for add to vector" << std::endl;
        std::cout << "M for average of elements" << std::endl;
        std::cout << "S for smallest element" << std::endl;
        std::cout << "L for largest element" << std::endl;
        std::cout << "Q for terminating the code" << std::endl;
        std::cin >> key;

        switch (key){
            case 'p':
            case 'P':
                std::cout << "[ ";
                for(int element : my_vector){
                    std::cout << element << " ";
                }
                std::cout << "]\n";
                break;
            
            case 'a':
            case 'A':
                int num;
                std::cout << "Please enter your desired integer element: ";
                std::cin >> num;
                my_vector.push_back(num);
                std::cout << num << " is added" << std::endl;
                break;
            
            case 'm':
            case 'M':
                for (int element : my_vector){
                    sum +=element;
                }
                std::cout << "Average is " << static_cast<double>(sum) / my_vector.size() << std::endl;
                break;

            case 's':
            case 'S':
                smallest_item = my_vector.at(0);
                for (int i =0; i<my_vector.size(); i++){
                    if (my_vector.at(i) < smallest_item){
                        smallest_item = my_vector.at(i);
                    }
                }
                std::cout << "Smallest Item " << smallest_item << std::endl;
                break;

            case 'l':
            case 'L':
                largest_item = my_vector.at(0);
                for (int i =0; i<my_vector.size(); i++){
                    if (my_vector.at(i) > largest_item){
                        largest_item = my_vector.at(i);
                    }
                }
                std::cout << "Largest Item " << largest_item << std::endl;
                break;

            case 'q':
            case 'Q':
                std::cout << "Terminating program." << std::endl;
                break;

            default:
                std::cout << "Wrong key, enter again." << std::endl;
        }

        std::cout << std::endl;


    } while (key != 'q' && key != 'Q');

    
    return 0;
}