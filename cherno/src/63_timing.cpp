#include <iostream>
#include <chrono>
#include <thread>

void elapsed_time() {
    std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for(int counter=0; counter<100000000; counter++){}
    std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
    std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Elapsed Time: " << elapsed.count() << " ms\n";
}


class ElapsedTime {
private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::microseconds elapsed;

public:
    ElapsedTime() {
        start = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    }

    ~ElapsedTime() {
        end = std::chrono::steady_clock::now();
        elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);  // fixed
        std::cout << "Elapsed Time (constructor to destructor): " << elapsed.count() << " µs\n";
    }
};


void print_current_time(){
    std::chrono::time_point<std::chrono::system_clock> system_now = std::chrono::system_clock::now(); // time point

    time_t system_now_t = std::chrono::system_clock::to_time_t(system_now); // integer value of time point in seconds

    std::tm* local = std::localtime(&system_now_t); // breaks the total second count into calendar fields (hour, min, day, month, year...)

    char buffer[64];
    std::strftime(buffer, sizeof(buffer), "%H:%M - %d/%m/%Y", local); // formatting the local time
    std::cout << "Current Time: " << buffer << std::endl;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./62_timing <example>\n";
        std::cout << "  1 - elapsed time with function\n";
        std::cout << "  2 - elapsed time with class\n";
        return 1;
    }

    int choice = std::stoi(argv[1]);

    switch (choice) {
        case 1: {
            elapsed_time();
            break;
        }
        case 2: {
            ElapsedTime time;
            break;
        }
        case 3: {
            print_current_time();
            break;
        }
        default:
            std::cout << "Invalid choice. Run without arguments to see usage.\n";
            return 1;
    }

    return 0;
}