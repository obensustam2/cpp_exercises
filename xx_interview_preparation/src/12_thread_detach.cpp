#include <iostream>
#include <thread>
#include <chrono>


void backgroundTask(){
    std::cout << "backgroundTask ID: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "backgroundTask finished" << std::endl;
}

int main(){
    std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
    
    std::thread baby_thread(backgroundTask);
    baby_thread.detach();

    for(int i=0;i<5;i++){
        std::cout << "I don't wait the backgroundTask completion to run" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}