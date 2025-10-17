#include <iostream>

class Log{

public:
    enum Level{
        Info,
        Warning,
        Error
    };

    void setLevel(Level newLevel){
        m_logLevel = newLevel;
    }

    void info(const char *message){
        if(m_logLevel == Level::Info){
            std::cout << "INFO: " << message << std::endl;
        }
    }

    void warn(const char *message){
        if(m_logLevel == Level::Warning){
            std::cout << "WARNING: " << message << std::endl;
        }
    }

    void error(const char *message){
        if(m_logLevel == Level::Error){
            std::cout << "ERROR: " << message << std::endl;
        }
    }

private:
    Level m_logLevel = Level::Info;
};

int main(){
    Log log;
    log.setLevel(Log::Level::Error);
    log.info("Hello");
    log.warn("Hello");
    log.error("Hello");

    return 0;
}