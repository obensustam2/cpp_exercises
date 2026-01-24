#include <iostream>
#include <string>

class Entity{
private:
    std::string m_Name;
public:
    Entity() : 
        m_Name("Unknown") {
    }

    Entity(const std::string &name) : 
        m_Name(name){
    }
    
    const std::string &get_name() const{
        return m_Name;
    } 
};


int main()
{
    Entity entity;
    std::cout << entity.get_name() << std::endl;

    Entity entity2("Oben");
    std::cout << entity2.get_name() << std::endl;

    // stack memory
    Entity *entity_ptr = nullptr;
    {
        Entity entity3("Orbay");
        entity_ptr = &entity3;
        std::cout << entity3.get_name() << std::endl;
        std::cout << entity_ptr->get_name() << std::endl;
    }

    // heap memory
    Entity *entity_ptr2 = nullptr;
    {
        entity_ptr2 = new Entity("Orcun");
        std::cout << entity_ptr2->get_name() << std::endl;
        delete entity_ptr2;
    }

    return 0;
}