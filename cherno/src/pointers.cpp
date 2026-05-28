#include <memory>
#include <iostream>
#include <string>
#include <vector>


// ═══════════════════════════════════════
// Test 1 — stack vs heap 
//          - scope exercise
// ═══════════════════════════════════════
namespace test_1 {
    int* globalPtr = nullptr;

    int* createHeap(){
        return new int(42);
    }

    void storeStack(){
        int x = 99;
        globalPtr = &x;
        std::cout << "globalPtr: " << *globalPtr << std::endl;
    }

    void overwrite(){
        int a = 111;
        int b = 222;
        int c = 333;
    }

    void run(){
        int* heapPtr = createHeap();
        std::cout << "Step 1 heapPtr points: " << *heapPtr << std::endl; // 42
        std::cout << "Step 1 heapPtr address: " << heapPtr << std::endl; 

        storeStack();
        overwrite();
        std::cout << "Step 2 globalPtr: " << *globalPtr << std::endl; // 111
        // Stale Pointer Dereferencing

        delete heapPtr;
        // heapPtr is now DANGLING! It still points to that address, 
        // but the system thinks that memory is empty.

        std::cout << "Step 3 heapPtr points after delete: " << *heapPtr  << std::endl;
        std::cout << "Step 3 heapPtr address after delete: " << heapPtr << std::endl; 
        std::cout << "Step 3 is heapPtr null?: "     << (heapPtr == nullptr) << std::endl; // 0

        // delete heapPtr;
        heapPtr = nullptr;
        // std::cout << "Step 4 heapPtr points after nullptr: " << *heapPtr  << std::endl;
        std::cout << "Step 4 heapPtr address after nullptr: " << heapPtr << std::endl; 
        std::cout << "Step 4 is heapPtr null?: "     << (heapPtr == nullptr) << "\n" << std::endl; // 1
    }

}


// ═══════════════════════════════════════
// Test 2 — reference vs pointer 
//           - optional parameter (can be null)
// ═══════════════════════════════════════
namespace test_2 {
    void processRef(int data, std::string& logger){
        logger += "processed ";
    }

    void processPtr(int data, std::string* logger){
        if (logger != nullptr) {
            *logger += "processed ";
        }
    }

    void run(){
        std::string log;

        processPtr(42, &log);
        processRef(45, log);
        processPtr(42, nullptr); // without logger — reference can't do this

        std::cout << "log: " << log << "\n" << std::endl;
    }
}


// ═══════════════════════════════════════
// Test 3 — reference vs pointer 
//           - reassign to different variable
// ═══════════════════════════════════════
namespace test_3{
    void run(){
        int a = 10;
        int b = 20;

        int& ref = a;
        ref = b;
        std::cout << a << std::endl; // 20 - a is not a anymore
        std::cout << b << std::endl; // 20
        
        a = 10;
        b = 20;
        int* ptr = &a;
        std::cout << "ptr points to a:  " << *ptr << std::endl;  // 10
        std::cout << a << std::endl; // 10
        ptr = &b;
        std::cout << "ptr points to b:  " << *ptr << "\n" << std::endl;  // 20
        std::cout << b << std::endl; // 20
    }  
} 


// ═══════════════════════════════════════
// Test 4 — unique_pointer
// ═══════════════════════════════════════
namespace test_4{
    struct Sensor
    {
        std::string name;

        Sensor(std::string n) : name(n){
            std::cout << name << " created" << std::endl;
        }

        ~Sensor(){
            std::cout << name << " deleted" << std::endl;
        }

        void read(){
            std::cout << name << " read " << 42 << std::endl;
        }
    };

    void step_1_creation_and_get(){
        std::unique_ptr<Sensor> s1 = std::make_unique<Sensor>("IMU");
        std::cout << "s1 Object address (heap):  " << s1.get() << std::endl;
        std::cout << "s1 Pointer address (stack): " << &s1 << std::endl;
        s1->read();
    }

    void step_2_reset(){
        std::unique_ptr<Sensor> s2 = std::make_unique<Sensor>("GPS");

        s2.reset(new Sensor("LIDAR")); 

        s2->read();

        s2.reset(); 

        std::cout << "s2 is null :" << ((s2 == nullptr) ? 1 : 0) << std::endl;
    }

    void step_3_move(){
        std::unique_ptr<Sensor> s3 = std::make_unique<Sensor>("Barometer");
        std::unique_ptr<Sensor> s4 = std::move(s3);

        std::cout << "s3 is null: " << (s3 == nullptr ? "yes" : "no") << "\n";
        s4->read();
    }


    void take_sensor(std::unique_ptr<Sensor> s){
        std::cout << "inside takeSensor:" << std::endl;;
        s->read();
    }   

    void step_4_pass_by_value(){
        std::unique_ptr<Sensor> s5 = std::make_unique<Sensor>("Accelerometer");
        take_sensor(std::move(s5)); // take_sensor(s5) would fail because you are trying to copy a unique pointer
        std::cout << "s5 still alive after borrow: " << (s5 != nullptr ? "yes" : "no") << std::endl;
    }


    void borrow_sensor(const std::unique_ptr<Sensor>& s){
        std::cout << "inside borrowSensor:" << std::endl;
        s->read();
    }   // s not destroyed — just borrowed

    void step_5_pass_by_reference(){
        std::unique_ptr<Sensor> s6 = std::make_unique<Sensor>("Gyroscope");
        borrow_sensor(s6);
        std::cout << "s6 still alive after borrow: " << (s6 != nullptr ? "yes" : "no") << std::endl;
    }


    std::unique_ptr<Sensor> return_from_function(std::string name){
        std::cout << "inside return from function:\n";
        return std::make_unique<Sensor>(name);
    }

    void step_6_return_from_function(){
        std::unique_ptr<Sensor> s7 = return_from_function("Magnetometer");
        s7->read();
    }


    void run(){
        step_1_creation_and_get();
        std::cout << "\n";
        step_2_reset();
        std::cout << "\n";
        step_3_move();
        std::cout << "\n";
        step_4_pass_by_value();
        std::cout << "\n";
        step_5_pass_by_reference();
        std::cout << "\n";
        step_6_return_from_function();
        std::cout << "\n";
    }
}


// ═══════════════════════════════════════
// Test 5 — shared_pointer
// ═══════════════════════════════════════
namespace test_5{
    struct Sensor
    {
        std::string name;

        Sensor(std::string n) : name(n){
            std::cout << name << " created" << std::endl;
        }

        ~Sensor(){
            std::cout << name << " deleted" << std::endl;
        }

        void read(){
            std::cout << name << " read " << 42 << std::endl;
        }
    }; 
    
    void step_1_creation_and_use_count(){
        std::shared_ptr<Sensor> s1 = std::make_shared<Sensor>("IMU");
        std::cout << "use count after creation " << s1.use_count() << std::endl;
        std::cout << "s1 object address (heap): " << s1.get() << std::endl;
        std::cout << "s1 pointer address (stack): " << &s1 << std::endl;
    }

    void step_2_multiple_owners(){
        std::shared_ptr<Sensor> s2 = std::make_shared<Sensor>("GPS");
        std::cout << "s2 object address (heap): " << s2.get() << std::endl;
        std::cout << "s2 pointer address (stack): " << &s2 << std::endl;
        std::cout << "use_count after s2: " << s2.use_count() << std::endl;

        {
            std::shared_ptr<Sensor> s3 = s2;
            std::cout << "s3 object address (heap): " << s3.get() << std::endl;
            std::cout << "s3 pointer address (stack): " << &s3 << std::endl;   
            std::cout << "use_count after s3: " << s2.use_count() << std::endl;  

            std::shared_ptr<Sensor> s4 = s3;  
            std::cout << "s4 object address (heap): " << s4.get() << std::endl;
            std::cout << "s4 pointer address (stack): " << &s4 << std::endl;
            std::cout << "use_count after s4: " << s2.use_count() << std::endl;  

            s3->read();
            s4->read();
        } 

        std::cout << "use_count after scope: " << s2.use_count() << std::endl; 
        std::cout << "s2 still alive: " << (s2 != nullptr ? "yes" : "no") << std::endl;
    }


    void take_sensor(std::shared_ptr<Sensor> s){
        std::cout << "inside take_sensor use_count: " << s.use_count() << std::endl;
        s->read();
    }

    void step_3_pass_by_value(){
        std::shared_ptr<Sensor> s5 = std::make_shared<Sensor>("LIDAR");
        std::cout << "before call use_count: " << s5.use_count() << std::endl;

        take_sensor(s5);

        std::cout << "after call use_count:  " << s5.use_count() << std::endl;  
        std::cout << "s5 still alive: " << (s5 != nullptr ? "yes" : "no") << std::endl;
    }


    void borrow_sensor(std::shared_ptr<Sensor>& s){
        std::cout << "inside borrow sensor use_count: " << s.use_count() << std::endl;
        s->read();
    }

    void step_4_pass_by_reference(){
        std::shared_ptr<Sensor> s6 = std::make_shared<Sensor>("Barometer");
        std::cout << "before call use_count: " << s6.use_count() << std::endl;

        borrow_sensor(s6);

        std::cout << "after call use_count: " << s6.use_count() << std::endl;  
    }


    std::shared_ptr<Sensor> return_from_function(std::string name){
        std::cout << "inside return from function:\n";
        return std::make_shared<Sensor>(name);
    }

    void step_5_return_from_function(){
        std::shared_ptr s7 = return_from_function("Magnetometer");
        std::cout << "use_count after factory: " << s7.use_count() << std::endl;
        s7->read();
        std::cout << "sensor survived past the function that created it" << std::endl;
    }


    void step_6_container(){
        std::shared_ptr<Sensor> s8 = std::make_shared<Sensor>("Thermometer");
        std::cout << "use_count before vector: " << s8.use_count() << std::endl;

        std::vector<std::shared_ptr<Sensor>> sensorList;
        sensorList.push_back(s8); // it copies s8
        sensorList.push_back(s8);
        std::cout << "use_count in vector: " << s8.use_count() << std::endl;

        sensorList.clear();
        std::cout << "use_count after clear: " << s8.use_count() << std::endl; 
    }

    void step_7_reset(){
        std::shared_ptr<Sensor> s9 = std::make_shared<Sensor>("Gyroscope");
        std::shared_ptr<Sensor> s10 = s9;
        std::cout << "use_count before reset: " << s9.use_count() << std::endl;

        s10.reset(); // makes s10 nullptr
        std::cout << "use_count after s10.reset(): " << s9.use_count() << std::endl; 
        std::cout << "s10 is null: " << (s10 == nullptr ? "yes" : "no") << std::endl;
        std::cout << "s9 is null: " << (s9 == nullptr ? "yes" : "no") << std::endl;
        
        s9.reset();  
        std::cout << "use_count after s9.reset(): " << s9.use_count() << std::endl;
        std::cout << "s9 is null: " << (s9 == nullptr ? "yes" : "no") << std::endl;
    }


    void run(){
        step_1_creation_and_use_count();
        std::cout << "\n";
        step_2_multiple_owners();
        std::cout << "\n";
        step_3_pass_by_value();
        std::cout << "\n";
        step_4_pass_by_reference();
        std::cout << "\n";
        step_5_return_from_function();
        std::cout << "\n";
        step_6_container();
        std::cout << "\n";
        step_7_reset();
        std::cout << "\n";
    }
}


// ═══════════════════════════════════════
// Test 6 — weak_pointer
// ═══════════════════════════════════════
namespace test_6{
    struct Sensor {
        std::string name;

        Sensor(std::string n) : name(n) {
            std::cout << name << " created" << std::endl;
        }

        ~Sensor() {
            std::cout << name << " deleted" << std::endl;
        }

        void read() {
            std::cout << name << " read " << 42 << std::endl;
        }
    };

    void step_1_creation(){
        std::shared_ptr<Sensor> s1 = std::make_shared<Sensor>("IMU");
        std::cout << "use_count before weak_ptr: " << s1.use_count() << std::endl;

        std::weak_ptr<Sensor> w1 = s1;
        std::cout << "use_count after weak_ptr:  " << s1.use_count() << std::endl; 

        std::cout << "w1 expired: " << (w1.expired() ? "yes" : "no") << std::endl; 
    } // s1 dies → use_count → 0 → Sensor deleted, w1 is now expired

    void step_2_lock(){
        std::shared_ptr<Sensor> s2 = std::make_shared<Sensor>("GPS");
        std::weak_ptr<Sensor> w2 = s2;
        // s2.reset();

        if(std::shared_ptr<Sensor> locked = w2.lock()){
            std::cout << "lock() succeeded — use_count inside lock: " << locked.use_count() << std::endl;
            locked->read();
        } else{
            std::cout << "lock() failed because s2 pointer has reset — use_count inside lock: " << locked.use_count() << std::endl;
        }

        std::cout << "use_count after lock scope: " << s2.use_count() << std::endl; 
    }

    void step_3_expired(){
        std::weak_ptr<Sensor> w3; 

        {
            std::shared_ptr<Sensor> s3 = std::make_shared<Sensor>("LIDAR");
            w3 = s3;
            std::cout << "w3 expired inside scope:   " << (w3.expired() ? "yes" : "no") << std::endl; 
        }  

        std::cout << "w3 expired outside scope:  " << (w3.expired() ? "yes" : "no") << std::endl;

        if (std::shared_ptr<Sensor> locked = w3.lock()) {
            std::cout << "lock() succeeded" << std::endl;
        } else {
            std::cout << "lock() failed — object already deleted" << std::endl;
        }
    }


    void observe_sensor(std::weak_ptr<Sensor> w){
        std::cout << "inside observe_sensor" << std::endl;

        if (std::shared_ptr<Sensor> locked = w.lock()) {
            std::cout << "lock() succeeded — object still alive" << std::endl;
            locked->read();
        } else {
            std::cout << "lock() failed — object already deleted" << std::endl;
        }
    }

    void step_4_pass_to_function(){
        std::shared_ptr<Sensor> s4 = std::make_shared<Sensor>("Barometer");
        std::weak_ptr<Sensor> w4 = s4;

        std::cout << "calling observe while alive:" << std::endl;
        observe_sensor(w4);

        s4.reset();
        std::cout << "s4 = nullptr: " << (s4 == nullptr ? "yes" : "no") << std::endl;
        std::cout << "calling observe after delete:" << std::endl;
        observe_sensor(w4);   
    }


    void step_5_circular_reference_problem(){
        struct BadNode {
            std::string name;
            std::shared_ptr<BadNode> next;   // ❌ strong — causes cycle

            BadNode(std::string n) : name(n) {
                std::cout << name << " created" << std::endl;
            }
            ~BadNode() {
                std::cout << name << " deleted" << std::endl;
            }
        };

        std::shared_ptr<BadNode> a = std::make_shared<BadNode>("Node A");
        std::cout << "a use_count: " << a.use_count() << std::endl; 

        std::shared_ptr<BadNode> b = std::make_shared<BadNode>("Node B");
        std::cout << "b use_count: " << b.use_count() << std::endl;

        a->next = b; 
        std::cout << "a use_count: " << a.use_count() << std::endl; // 1
        std::cout << "b use_count: " << b.use_count() << std::endl; // 2

        b->next = a; 
        std::cout << "a use_count: " << a.use_count() << std::endl; // 2
        std::cout << "b use_count: " << b.use_count() << std::endl; // 2
    }

    void step_6_circular_reference_fixed(){
        struct GoodNode {
            std::string name;
            std::shared_ptr<GoodNode> next;   // strong — forward link
            std::weak_ptr<GoodNode>   prev;   // weak  — back link ✅

            GoodNode(std::string n) : name(n) {
                std::cout << name << " created" << std::endl;
            }
            ~GoodNode() {
                std::cout << name << " deleted" << std::endl;
            }
        };

        std::shared_ptr<GoodNode> a = std::make_shared<GoodNode>("Node A");
        std::shared_ptr<GoodNode> b = std::make_shared<GoodNode>("Node B");

        a->next = b;
        std::cout << "a use_count: " << a.use_count() << std::endl; // 1
        std::cout << "b use_count: " << b.use_count() << std::endl; // 2

        b->prev = a;   
        std::cout << "a use_count: " << a.use_count() << std::endl; // 1
        std::cout << "b use_count: " << b.use_count() << std::endl; // 2
    } // a use_count: 1→0 → Node A deleted ✅, b use_count: 2→1→0 → Node B deleted ✅
    

    void run(){
        step_1_creation();
        std::cout << "\n";
        step_2_lock();
        std::cout << "\n";  
        step_3_expired();
        std::cout << "\n";  
        step_4_pass_to_function();
        std::cout << "\n"; 
        step_5_circular_reference_problem();
        std::cout << "\n"; 
        step_6_circular_reference_fixed();
        std::cout << "\n"; 

    }
}


int main(){

    // test_1::run();
    // test_2::run();
    // test_3::run();
    // test_4::run();
    // test_5::run();
    // test_6::run();

    return 0;
}