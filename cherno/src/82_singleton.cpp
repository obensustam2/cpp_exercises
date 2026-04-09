#include <iostream>
#include <string>

class Database{
private:
    std::string m_Name;

    Database(const std::string& name) : m_Name(name){}

public:
    static Database& get(){
        static Database* instance = new Database("MyDB");
        return *instance;
    }

    void query(const std::string& sq1){
        std::cout << "[ " << m_Name << " ] Running" << sq1 << std::endl;
    }
};

int main(){
    Database::get().query("SELECT * FROM users");
    Database::get().query("SELECT * FROM orders");

    return 0;
}