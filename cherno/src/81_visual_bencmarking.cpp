#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <thread>


struct ProfileResult{
    std::string Name;
    long long Start, End;
};


struct InstrumentationSession{
    std::string Name;
};


class Instrumentor{
private:
    InstrumentationSession* m_CurrentSession;
    std::ofstream m_OutputStream;
    int m_ProfileCount;

public:
    Instrumentor() : 
        m_CurrentSession(nullptr), m_ProfileCount(0) {
    }

    void beginSession(const std::string& name, const std::string& filepath = "/home/oben/Projects/cpp_exercises/cherno/config/results.json"){
        m_OutputStream.open(filepath);
        writeHeader();
        m_CurrentSession = new InstrumentationSession{name};
    }

    void writeHeader(){
        m_OutputStream << "{\n";
        m_OutputStream << "    \"otherData\": {},\n";
        m_OutputStream << "    \"traceEvents\": [\n";
        m_OutputStream.flush();
    }

    void writeProfile(const ProfileResult& result){
        if(m_ProfileCount++ > 0){
            m_OutputStream << ",\n";
        }

        std::string name = result.Name;
        std::replace(name.begin(), name.end(), '"', '\'');

        m_OutputStream << "        {\n";
        m_OutputStream << "            \"cat\": \"function\",\n";
        m_OutputStream << "            \"dur\": " << (result.End - result.Start) << ",\n";
        m_OutputStream << "            \"name\": \"" << name << "\",\n";
        m_OutputStream << "            \"ph\": \"X\",\n";
        m_OutputStream << "            \"pid\": 0,\n";
        m_OutputStream << "            \"tid\": 0,\n";
        m_OutputStream << "            \"ts\": " << result.Start << "\n";
        m_OutputStream << "        }";

        m_OutputStream.flush();
    }

    void endSession(){
        writeFooter();
        m_OutputStream.close();
        delete m_CurrentSession;
        m_CurrentSession = nullptr;
        m_ProfileCount = 0;
    }

    void writeFooter(){
        m_OutputStream << "\n    ]\n";
        m_OutputStream << "}\n";
        m_OutputStream.flush();
    }

    static Instrumentor& get(){
        static Instrumentor* instance = new Instrumentor();
        return *instance;
    }
};



class InstrumentationTimer{
private:
    const char* timerName;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTimePoint;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTimePoint;
    bool timerStopped;

public:
    InstrumentationTimer(const char* name) : timerName(name), timerStopped(false){
        startTimePoint = std::chrono::high_resolution_clock::now();
    }

    ~InstrumentationTimer(){
        if(!timerStopped){
            stopTimer();
        }
    }

    void stopTimer(){
        endTimePoint = std::chrono::high_resolution_clock::now();

        long long start = std::chrono::time_point_cast<std::chrono::microseconds>(startTimePoint).time_since_epoch().count();
        long long end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();

        Instrumentor::get().writeProfile({timerName, start, end});

        timerStopped = true; // exists to make the class safe against both usage patterns.
    }
};

void function1(){
    InstrumentationTimer timer("Function1");

    for(int i=0; i<1000; i++){
        std::cout << "Hello World #" << i << std::endl;
    }
}

void function2(){
    InstrumentationTimer timer("Function2");

    for(int i=0; i<1000; i++){
        std::cout << "Hello World #" << sqrt(i) << std::endl;
    }
}

void runBenchmarks(){
    InstrumentationTimer timer("RunBenchmarks");

    std::cout << "Running benchmarks" << std::endl;
    std::thread a(function1);
    std::thread b(function2);

    a.join();
    b.join();
}



int main(){

    Instrumentor::get().beginSession("Profile");
    runBenchmarks();
    Instrumentor::get().endSession();

    return 0;
}