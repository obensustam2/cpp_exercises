#include <iostream>
#include <memory>

class Sensor{
public:
    Sensor(){
        std::cout << "Sensor created" << std::endl;
    }
    ~Sensor(){
        std::cout << "Sensor destroyed" << std::endl;
    }
    double read(){
        return 42.0;
    }
};


class CameraNode {
private: 
    std::shared_ptr<Sensor> sensor_;

public:
    explicit CameraNode(std::shared_ptr<Sensor> s) : sensor_(s){}
    void process(){
        std::cout << "Camera got " << sensor_->read() << std::endl;
    }
};


class LoggerNode {
private: 
    std::shared_ptr<Sensor> sensor_;

public:
    explicit LoggerNode(std::shared_ptr<Sensor> s) : sensor_(s){}
    void log(){
        std::cout << "Logger got " << sensor_->read() << std::endl;
    }
};


int main(){
    std::cout << "Line: " << __LINE__ << std::endl;  
    std::shared_ptr<Sensor> sensor_ptr = std::make_shared<Sensor>(); // ref count: 1
    std::cout << "Line: " << __LINE__ << std::endl;  
    CameraNode camera(sensor_ptr);  // ref count: 2
    std::cout << "Line: " << __LINE__ << std::endl;  
    LoggerNode logger(sensor_ptr);  // ref count: 3
    std::cout << "Line: " << __LINE__ << std::endl;  
    camera.process();
    std::cout << "Line: " << __LINE__ << std::endl;  
    logger.log();
    std::cout << "Line: " << __LINE__ << std::endl;  
    return 0;
}