#include <iostream>
#include <map>
#include <string>

std::map<std::string, int> student_list = {
    {"ben", 9}, {"rbay", 8}, {"cun", 0}
}; 

void test_1_map(){
    std::cout << student_list.at("cun") << std::endl;

    for(auto& [k, v] : student_list){
        std::cout << k << ":" << v << std::endl;
    }
}


long long factorial(int n){
    long long result = 1;
    for(int i = n; i>0; i--){
        result = result * i;
    }    
    return result;
}

void test_2_factorial(){
    long long res = factorial(20);
    std::cout << res << std::endl;
}


void test_3_increment(){
    int x = 5;
    int y = x++;
    std::cout << "x: " << x << ", y: " << y << std::endl; // x: 6, y: 5
    std::cout << "x: " << x++ << std::endl; // x: 6

    int a = 5;
    int b = ++a; 
    std::cout << "a: " << a << ", b: " << b << std::endl; // a: 6, b: 6
}


// ═══════════════════════════════════════
// Test 4 — Inheritance
// ═══════════════════════════════════════
namespace test_4 {
    class A{
    public:
        A(){
            std::cout<<"A::A\n";
        }

        ~A(){
            std::cout<<"A::~A\n";
        }
    };

    class B: public A{
    public:  
        B(){
            std::cout<<"B::B\n";
        }

        ~B(){
            std::cout<<"B::~B\n";
        }
    };

    class C: public B{
    public:  
        C(){
            std::cout<<"C::C\n";
        }

        ~C(){
            std::cout<<"C::~C\n";
        }
    };

    void run(){
        C c;
    }
}


// ═══════════════════════════════════════
// Test 5 — Template: Each Instantiation is a Distinct Function
// ═══════════════════════════════════════
namespace test_5 {
    template <class T> 
    void template_funtion(T) {
        static int i = 0;
        std::cout << ++i << std::endl;
    }

    void run(){
        template_funtion(1);
        template_funtion(1.0);
        template_funtion(9.5);
        template_funtion(9);
    }
}

int main(){

    // test_1_map();
    // test_2_factorial();
    // test_3_increment();
    // test_4::run();
    test_5::run();

    return 0;
}

