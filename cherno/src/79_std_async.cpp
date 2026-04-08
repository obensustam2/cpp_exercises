#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <vector>
#include <mutex>

std::mutex sensor_mtx;
double reading = 5.0;
std::vector<double> sensor_readings;

void load_mesh(){
    std::cout << "load_mesh: started loading" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "load_mesh: loading completed" << std::endl;
}

int move_robot(){
    std::cout << "move_robot: started moving" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "move_robot: moving completed" << std::endl;
    return 0;
}

double read_sensor(){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::lock_guard<std::mutex> lock(sensor_mtx);
    reading = reading * 1.5;
    sensor_readings.push_back(reading);

    return reading;
}


template<typename T>
void measure_time(T func, int loop_num){
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();

    for(int i=0; i<loop_num; i++){
        func();
    }

    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "Elapsed Time: " << elapsed.count() << " ms" << std::endl;
}

template<typename T>
void measure_time_with_asyn_func(T func, int loop_num){
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    
    // invoke_result_t<T>: give me the return type of called function
    // std::future<XX>: holds the pending result with XX type
    std::vector<std::future<std::invoke_result_t<T>>> futures; 
    for(int i=0; i<loop_num; i++){
        futures.push_back(std::async(std::launch::async, func));
    }

    for (auto& f : futures) {
        f.get();  // wait for each task to finish
    }

    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
    std::cout << "Async Function Elapsed Time: " << elapsed.count() << " ms" << std::endl;
}

int main(){

    measure_time(load_mesh, 4);
    std::cout << "----------------------" << std::endl;
    measure_time_with_asyn_func(load_mesh, 4);
    std::cout << "----------------------" << std::endl;

    measure_time(move_robot, 4);
    std::cout << "----------------------" << std::endl;
    measure_time_with_asyn_func(move_robot, 4);
    std::cout << "----------------------" << std::endl;

    measure_time(read_sensor, 5);
    std::cout << "All sensor readings:" << std::endl;
    for (double r : sensor_readings) {
        std::cout << r << " ";
    }
    std::cout << "\n----------------------" << std::endl;
    
    sensor_readings = {};
    reading = 5;
    measure_time_with_asyn_func(read_sensor, 5);
    std::cout << "All sensor readings:" << std::endl;
    for (double r : sensor_readings) {
        std::cout << r << " ";
    }
    std::cout << "\n";

    return 0;
}