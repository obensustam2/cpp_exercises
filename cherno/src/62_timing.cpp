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
        default:
            std::cout << "Invalid choice. Run without arguments to see usage.\n";
            return 1;
    }

    return 0;
}