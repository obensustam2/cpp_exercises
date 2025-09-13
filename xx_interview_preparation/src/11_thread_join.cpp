#include <iostream>
#include <thread>
#include <chrono>
#include <string>

static bool is_finished = false;

void doWork(std::string name){

    std::cout << "Started Thread doWork id: " << std::this_thread::get_id() << std::endl;

    while(!is_finished){
        std::cout << "Working for " << name << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}

void doTravel(){

    std::cout << "Started Thread doTravel id: " << std::this_thread::get_id() << std::endl;

    while(!is_finished){
        std::cout << "Traveling......." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

}

int main(){

    std::cout << "Started Thread Main id: " << std::this_thread::get_id() << std::endl;

    int n = std::thread::hardware_concurrency();
    std::cout << "Logical CPU cores: " << n << std::endl;
    
    std::thread worker(doWork, "Oben");
    std::thread traveler(doTravel);

    std::cin.get();
    is_finished = true;
    
    worker.join(); // block main thread until worker thread function completes
    traveler.join();
    std::cout << "Started Thread Main id: " << std::this_thread::get_id() << std::endl;

    std::cout << "Worker thread has done the job." << std::endl;

    std::cin.get();
    std::cout << "Exiting the program." << std::endl;
}