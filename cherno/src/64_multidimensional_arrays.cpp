#include <iostream>
#include <vector>
#include <array>


int main(){
    size_t row = 0;
    size_t column = 2;

    // --- 2D vector ---
    std::vector<std::vector<int>> vector_2d = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "vector_2d[0][2]: " << vector_2d[row][column] << "\n";

    for(size_t i = 0; i < vector_2d.size(); i++){
        for(size_t j = 0; j < vector_2d[i].size(); j++){
            std::cout << vector_2d[i][j] << " ";
        }
        std::cout << "\n";
    }


    // --- Raw C-style 2D array ---
    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << "arr[0][2]: " << arr[row][column] << "\n";
    
    for(size_t i = 0; i < 2; i++){
        for(size_t j = 0; j < 3; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }


    // --- std::array 2D ---
    std::array<std::array<int, 3>, 2> std_arr = {{
        {1, 2, 3},
        {4, 5, 6}
    }};

    std::cout << "std_arr[0][2]: " << std_arr[row][column] << "\n";
    
    for(size_t i = 0; i < std_arr.size(); i++){
        for(size_t j = 0; j < std_arr[i].size(); j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}