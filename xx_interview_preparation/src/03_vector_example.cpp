#include <iostream>
#include <vector>


int main() {
    std::vector<int> v;
    std::cout << "Initial capacity: " << v.capacity() << std::endl;

    for (int i = 0; i < 25; i++) {
        v.push_back(i);
        std::cout << "Size: " << v.size() 
             << ", Capacity: " << v.capacity() << std::endl;
    }
}
