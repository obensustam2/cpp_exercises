#include <iostream>
#include <string>

class Robot{
private:
    std::string name;
    int id;
    
public:
    // Constructor with name conflict
    Robot(const std::string &name, int id){
        this->name = name; // resolves conflict with parameter
        this->id = id;
    }

    // Method that returns the current object for chaining
    Robot& setName(const std::string &newName){
        this->name = newName;
        return *this; // returning current object
    }

     // Pass current object to another function
    void sendToFunction(){
        displayRobot(this); // passing this pointer
    }

    // Static function to display robot info from pointer
    static void displayRobot(Robot *r_ptr){
        std::cout << "Display: Robot " << r_ptr->name << " with ID " << r_ptr->id << std::endl;
    }
};


int main(){
    Robot r("Alpha", 1);

    r.setName("Beta").setName("Gamma");

    r.sendToFunction();

    return 0;
}