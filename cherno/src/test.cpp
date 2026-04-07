#include <iostream>
#include <memory>
#include <tuple>
#include <string>


struct Robot{
    int id;
    int distance;

    Robot(int id) : id(id), distance(0){
        std::cout << "Robot created with id: " << id << std::endl;
    }

    ~Robot(){
        std::cout << "Robot destroyed with id: " << id <<  std::endl;
    }

    void move(int meter){
        distance += meter;
        std::cout << "Robot moved to distance: " << distance << std::endl;
    }
};


void move(Robot& r, int val){
    r.move(val);
}

void move2(Robot* ptr, int val){
    ptr->move(val);
}


std::tuple<int, std::string, bool> tupleFunc(){
    return {29, "Oben", true};
}


int main(){
    std::shared_ptr<Robot> rbt_ptr1 = std::make_shared<Robot>(7);
    std::cout << "refs to robot: " << rbt_ptr1.use_count() << std::endl;
    move(*rbt_ptr1, 7);

    std::shared_ptr<Robot> rbt_ptr2 = rbt_ptr1;

    if (rbt_ptr1 == nullptr) {
        std::cout << "rbt_ptr1 gave up ownership" << std::endl;
    }
    else{
        std::cout << "rbt_ptr1 still owns it" << std::endl;
    }
    
    std::cout << "refs to robot: " << rbt_ptr2.use_count() << std::endl;
    rbt_ptr2->id = 5;

    move(*rbt_ptr2, 5);
    move2(rbt_ptr2.get(), 5);

    {
        std::shared_ptr<Robot> rbt_ptr3 = rbt_ptr1;
        rbt_ptr3->id = 9;
        std::cout << "refs to robot: " << rbt_ptr1.use_count() << std::endl;
        move(*rbt_ptr3, 9);
    }

    std::cout << "refs to robot: " << rbt_ptr1.use_count() << std::endl;

    // Tuple
    auto [age, name, isOld] = tupleFunc();
    std::cout << "Username: " << name << ", age: " << age << ", is old: " << isOld << std::endl;

    return 0;
}