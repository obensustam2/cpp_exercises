#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex mtx1, mtx2;
int counter = 0;


void increment1(int id){
    for(int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock(mtx1); // locks the mutex
        counter++; // safe access
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
} // lock goes out of scope here → mutex is automatically unlocked

void increment2(int id){
    for(int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock(mtx2);
        counter += 5;
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
}


void increment_nonmutex1(int id){
    for(int i=0; i<5; i++){
        counter++;
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
}

void increment_nonmutex2(int id){
    for(int i=0; i<5; i++){
        counter += 5;
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
}


int main(){
    std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
    
    std::thread t1(increment1, 1);
    std::thread t2(increment2, 2);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << "\n";

    return 0;
}