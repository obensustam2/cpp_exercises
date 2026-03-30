#include <iostream>

void function(){
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

int main(){
    for(int j=0; j<5; j++){
        function();
    }

    return 0;
}