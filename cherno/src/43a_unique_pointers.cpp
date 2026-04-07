#include <iostream>
#include <memory>


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


int main(){
    std::unique_ptr<Robot> rbt_ptr1 = std::make_unique<Robot>(7);
    rbt_ptr1->move(7);
    move(*rbt_ptr1, 7);

    std::unique_ptr<Robot> rbt_ptr2 = std::move(rbt_ptr1);
    rbt_ptr2->id = 5;

    if (rbt_ptr1 == nullptr) {
        std::cout << "rbt_ptr1 gave up ownership" << std::endl;
    }
    else{
        std::cout << "rbt_ptr1 still owns it" << std::endl;
    }
    
    move(*rbt_ptr2, 5);
    move2(rbt_ptr2.get(), 5);

    return 0;
}