#include <iostream>

int main(){
    
    int my_array [5] = {1,2,3,4,5};
    
    std::cout << "My first element: " << my_array[0] << std::endl;
    
    /* Cases both not possible
    std::cout << my_array[5] << std::endl;
    std::cin >> my_array[6];
    */

    my_array [0] = 88;
    std::cout << "My new first element: " << my_array[0] << std::endl;

    int my_2d_array [3][4] = {}; // [row][column]
    std::cout << "Last element on 2d array: " << my_2d_array[2][3] << std::endl;

    int my_new_2d_array [3] [4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    std::cout << "Second element on new 2d array: " << my_new_2d_array[0][1] << std::endl;

    return 0;
}
