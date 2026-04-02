#include <iostream>
#include <thread>
#include <string>
#include <atomic>
#include <mutex>
#include <chrono>

void task() {
    std::cout << "Running in a thread\n";
}

void greet(std::string name) {
    std::cout << name << std::endl;
}

int counter = 0;
void increment() {
    for (int i = 0; i < 100000; i++)
        counter++;
}

std::atomic<int> a_counter = 0;
void a_increment() {
    for (int i = 0; i < 100000; i++)
        a_counter++;
}

int m_counter = 0;
std::mutex mtx;
void m_increment() {
    for (int i = 0; i < 100000; i++) {
        mtx.lock();
        m_counter++;
        mtx.unlock();
    }
}

int lg_counter = 0;
std::mutex lg_mtx;
void lg_increment() {
    for (int i = 0; i < 100000; i++) {
        std::lock_guard<std::mutex> lock(lg_mtx);
        lg_counter++;
    }
}

void slow_task(std::string label) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    std::cout << "[" << label << "] finished\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./61_threads <example>\n";
        std::cout << "  1 - single thread, no argument\n";
        std::cout << "  2 - single thread, with argument\n";
        std::cout << "  3 - multithread, no protection (data race)\n";
        std::cout << "  4 - multithread, atomic\n";
        std::cout << "  5 - multithread, mutex\n";
        std::cout << "  6 - multithread, lock_guard\n";
        std::cout << "  7 - join vs detach\n";
        return 1;
    }

    int choice = std::stoi(argv[1]);

    switch (choice) {
        case 1: {
            std::thread t(task);
            t.join();
            break;
        }
        case 2: {
            std::thread t(greet, "Oben");
            t.join();
            break;
        }
        case 3: {
            std::thread t1(increment);
            std::thread t2(increment);
            t1.join();
            t2.join();
            std::cout << "Result: " << counter << "\n";
            break;
        }
        case 4: {
            std::thread t1(a_increment);
            std::thread t2(a_increment);
            t1.join();
            t2.join();
            std::cout << "Result: " << a_counter << "\n";
            break;
        }
        case 5: {
            std::thread t1(m_increment);
            std::thread t2(m_increment);
            t1.join();
            t2.join();
            std::cout << "Result: " << m_counter << "\n";
            break;
        }
        case 6: {
            std::thread t1(lg_increment);
            std::thread t2(lg_increment);
            t1.join();
            t2.join();
            std::cout << "Result: " << lg_counter << "\n";
            break;
        }
        case 7: {
            std::cout << "-- join --\n";
            std::cout << "[main] starting thread\n";
            std::thread t1(slow_task, "join thread");
            std::cout << "[main] waiting for thread...\n";
            t1.join();
            std::cout << "[main] thread done, main continues\n";

            std::cout << "\n-- detach --\n";
            std::cout << "[main] starting thread\n";
            std::thread t2(slow_task, "detach thread");
            t2.detach();
            std::cout << "[main] did not wait — main already here\n";
            std::cout << "[main] sleeping to give detached thread a chance...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            std::cout << "[main] done\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Run without arguments to see usage.\n";
            return 1;
    }

    return 0;
}