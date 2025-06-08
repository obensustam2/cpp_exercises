# BUILD
```
touch CMakeLists.txt
mkdir build
cd build
cmake .. 
make 
./my_program
```

## NOTES
### Preprocessor
The preprocessor runs before actual compilation. It handles all lines starting with #, like:
```
#include <iostream>  // includes the standard I/O library
#define PI 3.14159   // defines a constant
#ifdef DEBUG         // conditional compilation
```

### Standard Template Library vs Standard Library 
| Term                     | Contains                      | Examples                                          |
| ------------------------ | ----------------------------- | ------------------------------------------------- |
| **STL**                  | Templates for data structures | `vector`, `map`, `sort`, `iterator`               |
| **C++ Standard Library** | STL + many other libraries    | `string`, `iostream`, `thread`, `regex`, `memory` |

### Standard Library Headers
```
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
```

### Variable
A variable is just a name (or label) for a location in your computer's memory where a value is stored.
```
int age = 25;
size_t position; // unsigned int or unsigned long 
```
The computer reserves a spot in memory big enough to store an int (usually 4 bytes).
- It puts the value 25 into that memory.
- It gives that memory location a name — in this case, age.
- So when you use age, you're referring to that memory location.

### Namespace
All ROS 2 C++ functionality is grouped under the **rclcpp** namespace. This keeps the API structured and makes it clear where functions and classes come from.
```
rclcpp::shutdown();
```
rclcpp::shutdown() clearly tells the compiler "use ROS 2’s shutdown"

### Arguments
```
int main(int num_args, char *args[]){
    std::cout << "Number of arguments: " << num_args << "\n";
    std::cout << "5th argument is: " << args[4] << "\n";
    return 1;
}
```

### User Input
```
int num_rooms = 0;
std::cout << "How many rooms do you want to be cleaned? ";
std::cin >> num_rooms;
```

### Constant Variable
```
const double tax_rate = 0.06;
```

### Byte Size
```
sizeof(char)
```

### Long Variable
```
long double large_amount = 2.7e120;
```

### Arrays
1-D Array
```
int my_array [5] = {1,2,3,4,5};
std::cout << my_array[0] << std::endl;
```

Multi-D Array

<img src="00_docs/images/multi_dim_arrays.png" alt="2D Array" width="360"/>


### Vectors
```
#include <iostream>
#include <vector>

int main()
{
    std::vector <double> number_vector = {0.5, 0.6, 0.7, 0.8, 0.9};
    std::cout << number_vector.at(0) << std::endl; 

    number_vector.at(0) = 1000;

    number_vector.push_back(1.0);

    number_vector.insert(number_vector.begin(), -0.6);

    std::cout << "Length of the vector is: " << number_vector.size() << std::endl;

    number_vector.pop_back();

    std::vector <std::vector<int>> my_2d_vector = {
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << my_2d_vector.at(1).at(2) << std::endl; 
    
    return 0;
}  
```

### Operator
- Operator = The symbol that performs an action
- Operand = The value or variable the operator acts on
```
int a = 10;
int b = 5;
int c = a + b;
```
- "+" is the operator
- a and b are the operands
- The operator + adds the two operands

### static_cast
```
std::cout << "Precise average is: " << static_cast<double>(total) / count << std::endl;
```

### Comparision
11.99999999999999999999999 and 12.0 could be equal for C++ code so be careful with the library usage

### Compound Assignment
| Operator | Meaning                | Equivalent To         |         |     |
| -------- | ---------------------- | --------------------- | ------- | --- |
| `+=`     | Add and assign         | `x = x + y`           |         |     |
| `-=`     | Subtract and assign    | `x = x - y`           |         |     |
| `*=`     | Multiply and assign    | `x = x * y`           |         |     |
| `/=`     | Divide and assign      | `x = x / y`           |         |     |
| `%=`     | Modulo and assign      | `x = x % y`           |         |     |
| `&=`     | Bitwise AND and assign | `x = x & y`           |         |     |
| \`       | =\`                    | Bitwise OR and assign | \`x = x | y\` |
| `^=`     | Bitwise XOR and assign | `x = x ^ y`           |         |     |
| `<<=`    | Left shift and assign  | `x = x << y`          |         |     |
| `>>=`    | Right shift and assign | `x = x >> y`          |         |     |


```
int x = 10;
x += 5;   // x = 15
x *= 2;   // x = 30
x -= 3;   // x = 27
```

### Operator Precedence
| Precedence  | Operator(s)             | Type                  | Associativity |            |               |
| ----------- | ----------------------- | --------------------- | ------------- | ---------- | ------------- |
| 1 (Highest) | `()` `[]` `->` `.`      | Function call, member | Left to right |            |               |
| 2           | `++` `--` `+` `-` `!`   | Unary operators       | Right to left |            |               |
| 3           | `*` `/` `%`             | Multiplicative        | Left to right |            |               |
| 4           | `+` `-`                 | Additive              | Left to right |            |               |
| 5           | `<` `<=` `>` `>=`       | Relational            | Left to right |            |               |
| 6           | `==` `!=`               | Equality              | Left to right |            |               |
| 7           | `&&`                    | Logical AND           | Left to right |            |               |
| 8           |                         | Logical OR            | Left to right |            |               |
| 9           | `=` `+=` `-=` `*=` `/=` | Assignment            | Right to left |            |               |
| 10 (Low)    | `,`                     | Comma                 | Left to right |            |               |


### Enumerator
```
enum Color {
    red, green, blue
};

Color screen_color = green;
```

### Precision Set
```
#include <iomanip>

if (temperatures.size() != 0){
    std::cout << std::fixed << std::setprecision(2) ;
    std::cout << "Average: " << sum/temperatures.size() << std::endl;
}
```

### If-Else
```
if (score >= 90)
{
    letter_grade = 'A';
}
else if (score >= 80)
{
    letter_grade = 'B';
}
else if (score >= 70){
    letter_grade = 'C';
}
else if (score >= 60){
    letter_grade = 'D';
}
else{
    letter_grade = 'F';
}
```

### Switch-Case
In C++, you cannot use switch with double or std::string directly. The switch statement only works with integral or enumeration types, such as:
- int
- char
- enum
```
int day;

std::cout << "Enter a number (1-7): ";
std::cin >> day;

switch (day) {
    case 1:
        std::cout << "Monday\n";
        break;
    case 2:
        std::cout << "Tuesday\n";
        break;
    case 3:
        std::cout << "Wednesday\n";
        break;
    case 4:
        std::cout << "Thursday\n";
        break;
    case 5:
        std::cout << "Friday\n";
        break;
    case 6:
        std::cout << "Saturday\n";
        break;
    case 7:
        std::cout << "Sunday\n";
        break;
    default:
        std::cout << "Invalid number! Please enter a number between 1 and 7.\n";
}
```

### Ternary Operator (Conditional Operator)
```
int num1, num2, bigger, smaller;
std::cout << "Enter two integers seperated by space: ";
std::cin >> num1 >> num2;

if (num1 != num2) {
    bigger = (num1 > num2) ? num1 : num2;
    smaller = (num1 < num2) ? num1 : num2;
    std::cout << "Bigger is " << bigger << std::endl;
    std::cout << "Smaller is " << smaller << std::endl;
}
```

```
    for (int i = 1; i <=100; i++)
    {
        std::cout << i;
        std::cout << ((i%10 == 0) ? "\n" : " ");
    }
```

### For Loop
```
#include <iostream>
#include <vector>

int main() {

    for (int i = 0; i < 5; i++){
        std::cout << i << std::endl;
    }

    for (int i = 10; i > 0; i--){
        std::cout << i << std::endl;
    }

    for (int i=0; i<=100; i+=10){
        if (i%15 == 0){
        std::cout << i << std::endl;
        } 
    }

    for (int i=1, j=5; i<=5; i++, j++){
        std::cout << i << " + " << j << " = " << i+j << std::endl;
    }

    std::vector<int> my_vector = {10,20,30,40};
    for (int i = 0; i<my_vector.size() ; i++){
        std::cout << my_vector.at(i) << std::endl;
    }

    return 0;
}
```

### Range Based For Loop
The term range refers to a collection of elements you can iterate over — like arrays, vectors, lists, maps, and any container that provides begin() and end() functions (which define a range of iterators).

```
#include <iostream>
#include <vector>

int main() {

    double sum = 0.0;
    std::vector <double> temperatures = {22.3, 15.6, 40.4} ;
    for (auto temperature : temperatures){
        sum += temperature;
    }
    std::cout << "Average: " << sum/temperatures.size() << std::endl;

    return 0;
}
```

### While Loop
```
#include <iostream>

int main() {

    bool done = false;
    int number = 0;
    while (!done)
    {
        std::cout << "Enter an integer between 1 and 5: ";
        std::cin >> number;
        if (number<1 || number>5){
            std::cout << "Out of range try again." << std::endl;
        }
        else{
            std::cout << "Thanks!" << std::endl;
            done = true;
        }
    }

    return 0;
}
```

### Do While Loop
If you know that you must perform at least one iteration of the loop, then you should consider the do while loop over while loop.
```
#include <iostream>

int main() {

    char selection;

    do {
        std::cout << "\n------------" << std::endl;
        std::cout << "1: Do this" << std::endl;
        std::cout << "2: Do that" << std::endl;
        std::cout << "3: Do something else" << std::endl;
        std::cout << "Q: Quit" << std::endl;
        std::cout << "Enter your selection: ";
        std::cin >> selection;

        switch (selection){
            case '1':
                std::cout << "I am doing this." << std::endl;
                break ;
            case '2':
                std::cout << "I am doing that." << std::endl;
                break ;
            case '3':
                std::cout << "I am doing something else." << std::endl;
                break ;
            case 'Q':
            case 'q':
                std::cout << "I am exitting from loop." << std::endl;
                break ;
            default:
                std::cout << "Wrong option" << std::endl;
        }

    } while(selection != 'q' && selection != 'Q') ;
    

    return 0;
}
```

### Continue and Break
#### Continue
When a continue statement is executed in the loop, no further statements in the body of the loop or executed and control immediately goes directly to the beginning of the loop for the next iteration. So you can think of this as skip processing in the rest of this iteration and go to the beginning of the loop.

#### Break
When the brake statement is executed in the loop, no further statements in the body are executed and the loop is terminated. So controllers transfer to the statement immediately following the loop.

```
#include <iostream>
#include <vector>

int main() {

    std::vector <int> my_vector = {1,2,-1,3,-1,-99,7,8,10};

    for (int element : my_vector){
        if (element == -99){
            break;
        }
        else if (element == -1){
            continue;
        }
        else{
            std::cout << element << std::endl;
        }
    }

    return 0;
}
```
```
1
2
3
```

### Infinite Loops
For Loop
```
    for(;;){
        std::cout << "This will print forver" << std::endl;
    }
```

While Loop
```
    while(true){
        std::cout << "This will print forver" << std::endl;
    }
```

Do-While Loop
```
    do{
        std::cout << "This will print forver" << std::endl;
    } while(true);
```

### Nested Loops
```
#include <iostream>
#include <vector>

int main (){

    int num_items;
    std::cout << "How many items you have?: ";
    std::cin >> num_items;

    std::vector <int> my_vector;

    for(int i=1;i<=num_items;i++){
        int vector_item;
        std::cout << "Enter vector item " << i << ": ";
        std::cin >> vector_item;
        my_vector.push_back(vector_item);
    }

    std::cout << "\nDisplaying Histogram" << std::endl;
    for (auto val : my_vector){
        for(int i=1; i<=val; i++){
            if(i%5 == 0){
                std::cout << " ";
            }
            else{
                std::cout << "+";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}
```

### C++ Strings
```
#include <iostream>
#include <string>

int main(){

    std::string s1 = "Apple";
    std::string s2 = "Kanana";

    s2.at(0) = 'B';
    std::cout << s2; // "Banana"

    std::cout << std::boolalpha;
    std::cout << (s1 < s2); // true ('A' comes before 'B' in the ASCII table)

    std::string s3 =  s1 + " and " + s2 + " juice"; // "Apple and Banana juice"
    
    std::string my_text = "My name is Oben";
    std::cout << my_text.size() << std::endl;   // 15
    std::cout << my_text.length() << std::endl; // 15

    for (int i = 0; i < s1.length(); ++i) 
        std::cout << s1.at(i);     
    std::cout << std::endl; // "Apple"
  
    s1 = "This is a test";
    std::cout << s1.substr(0,4) << std::endl;  // "This"
    std::cout << s1.substr(5,2) << std::endl;  // "is"
    std::cout << s1.substr(10,4) << std::endl; // "test"

    s1.erase(0,5);    
    std::cout << s1 << std::endl; // "is a test"   

    std::string full_name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);
    std::cout << full_name << std::endl ; // "Oben Sustam"
    std::cin >> full_name;
    std::cout << full_name << std::endl; // "Oben"

    s1 = "The secret word is Boo";
    std::string word;
    std::cout << "Enter the word to find: ";
    std::cin >> word;
    int position = s1.find(word);
    if (position < s1.length()) 
        std::cout << "Found " << word << " at position: " << position << std::endl;
    else
        std::cout << "Sorry, " << word <<  " not found" << std::endl;
        
    return 0;
}
```

### Functions
#### Random number generation
```
#include <iostream>
#include <ctime> // time
#include <cstdlib> // random

int main() {

    // Random number generation
    int random_number;
    int count = 10;
    int min = 1;
    int max = 6;

    // seed the random generator, if not you will get the same sequence random numbers
    std::cout << "RAND_MAX on my system is: " << RAND_MAX << std::endl;
    srand(time(nullptr));
    
    for (int i=0; i<count; i++){
        random_number = rand() % (max - min + 1) + min;
        std::cout << random_number << std::endl;
    }

    return 0;
}
```

#### Nearest integer floating-point operations
```
#include <iostream>
#inclue <cmath>

int main(){
    double num = 31.7;
    std::cout << "The ceil of " << num << " is " << ceil(num) << std::endl;   // 32
    std::cout << "The floor of " << num << " is " << floor(num) << std::endl; // 31
    std::cout << "The round of " << num << " is " << round(num) << std::endl; // 32
    return 0;
}
```

#### Power functions
```
#include <iostream>
#inclue <cmath>

int main(){

    std::cout << "Enter a double number: ";
    std::cin >> num;

    std::cout << "The square root of " << num << " is " << sqrt(num) << std::endl;
    std::cout << "The cubed root of " << num << " is " << cbrt(num) << std::endl;

    double power;
    std::cout << "Enter a power: ";
    std::cin >> power;
    std::cout << num << " power " << power << " is " << pow(num, power) << std::endl;
    return 0;
}
```

#### Trigonometric functions
```
#include <iostream>
#inclue <cmath>

int main(){
    double num = 30;
    std::cout << "The sine of " << num << " is " << sin(num*(M_PI/180)) << std::endl;
    std::cout << "The cosine of " << num << " is " << cos(num*(M_PI/180)) << std::endl;

    return 0;
}
```

#### Function Prototypes
```
#include <iostream>
#include <cmath>

double area_circle(double);
double volume_cylinder(double, double);

int main() {
    double radius, height;
    std::cin >> radius >> height;
    double my_volume = volume_cylinder(radius, height);
    std::cout << my_volume << std::endl;
    return 0;
}

double area_circle(double r){
    double area = M_PI * pow(r,2);
    return area;
}

double volume_cylinder(double radius, double height){
    double volume = area_circle(radius) * height;
    return volume;
}
```

#### Default arguments
Put the default arguments in prototypes
```
#include <iostream>
#include <iomanip>

double calc_cost(double base_cost, double tax_rate = 0.4, double shipping = 0.0);

int main(){
    double cost = 0.0;
    cost = calc_cost(100.0, 0.08, 4.25);
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Cost is: " << cost << std::endl; // 112.250
    cost = calc_cost(100.0);
    std::cout << "Cost is: " << cost << std::endl; // 140.000
    return 0;
}

double calc_cost(double base_cost, double tax_rate, double shipping){
    return base_cost += (base_cost*tax_rate) + shipping;
}
```

#### Overloading Functions (Polymorphism)
```
#include <iostream>
#include <string>
#include <vector>

void print(int);
void print(double);
void print(std::string);
void print(std::string, std::string);
void print(std::vector <std::string>);


int main(){
    print(10);
    print(10.3);
    print('a');
    print("Oben"); // C-style string is converted to C++ string
    print({"Hello", "my", "name", "is", "Oben"});

    return 0;
}


void print(int num){
    std::cout << "Printing int: " << num << std::endl;
}

void print(double num){
    std::cout << "Printing double: " << num << std::endl;
}

void print(std::string text){
    std::cout << "Printing string: " << text << std::endl;
}

void print(std::string text, std::string text2){
    std::cout << "Printing 2 string: " << text << " " << text2 << std::endl;
}

void print(std::vector <std::string> text_vec){
    std::cout << "Printing vector: ";
    for(std::string text : text_vec){
        std::cout << text << " ";
    }
    std::cout << std::endl;
}
```

Output
```
Printing int: 10
Printing double: 10.3
Printing int: 97
Printing string: Oben
Printing vector: Hello my name is Oben 
```
#### Pass by Reference
```
void double_data2(int &val){
    val *= 2;
}

void trial2(){
    int value2 = 10;
    std::cout << "Value: " << value2 << std::endl; // 10
    double_data2(value2);
    std::cout << "Value: " << value2 << std::endl; // 20
    double_data2(value2);
    std::cout << "Value: " << value2 << std::endl; // 40
}

int main(){
    trial2();
    return 0;
}
```

#### Pass by Value vs Pass by Reference
| Feature                         | **Pass by Value**                                                         | **Pass by Reference**                                                                |
| ------------------------------- | ------------------------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| **Definition**                  | A copy of the argument is passed to the function.                         | A reference (alias) to the original argument is passed.                              |
| **Modification of Argument**    | Changes made inside the function **do not** affect the original variable. | Changes made inside the function **affect** the original variable.                   |
| **Memory Usage**                | More memory (copy is made).                                               | Less memory (no copy, uses the original variable).                                   |
| **Performance**                 | Slower for large objects (due to copying).                                | Faster for large objects (no copying).                                               |
| **Syntax Example**              | `void foo(int x);`                                                        | `void foo(int& x);`                                                                  |
| **Safe from Side Effects?**     | ✅ Yes (original data is safe)                                             | ❌ No (can accidentally modify original data)                                         |
| **Typical Use Cases**           | Use when you **don't want** the function to modify the original data.     | Use when you **want** the function to modify the original data, or to avoid copying. |
| **Can be used with Constants?** | Yes                                                                       | Yes (use `const` reference to prevent modification)                                  |
| **Example Call**                | `foo(num);` (copies `num`)                                                | `foo(num);` (references `num`)                                                       |


#### Const usage for printing with reference inputs
```
#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;


void print_guest_list(const std::string &g1, const std::string &g2, const std::string &g3);
void clear_guest_list(std::string &g1, std::string &g2, std::string &g3);


int main() {

    string guest_1 {"Larry"};
    string guest_2 {"Moe"};
    string guest_3 {"Curly"};
    
    print_guest_list(guest_1, guest_2, guest_3);
    clear_guest_list(guest_1, guest_2, guest_3);
    print_guest_list(guest_1, guest_2, guest_3);
    
    return 0;
}


void print_guest_list(const std::string &g1, const std::string &g2, const std::string &g3) {
    
    cout << g1 << endl;
    cout << g2 << endl;
    cout << g3 << endl;
}


void clear_guest_list(std::string &g1, std::string &g2, std::string &g3) {
    g1 = " ";    
    g2 = " "; 
    g3 = " "; 
}
```

#### Local Global - Scope Rules
| Concept          | Explanation                                                                                                     |
| ---------------- | --------------------------------------------------------------------------------------------------------------- |
| **Scope**        | A variable is only accessible within the block it is declared in and its inner blocks.                          |
| **Shadowing**    | A variable in an inner scope can have the same name as one in an outer scope, temporarily hiding the outer one. |
| **Lifetime**     | Inner `num` (value 200) only exists within its block. Once the block ends, it's destroyed.                      |
| **Outer Access** | Inner blocks can access variables from outer blocks unless they’re shadowed.                                    |

```
#include <iostream>

int num = 300;

int main() {
    
    int num = 100;  
    int num1 = 500; 
    
    std::cout << "Local num is : " << num << " in main" << std::endl; // 100
    
    {   
        int num = 200;  
        std::cout << "Local num is: " << num << " in inner block in main" << std::endl; // 200
        std::cout << "Inner block in main can see out - num1 is: " << num1 << std::endl; // 500
    }
    
    std::cout << "Local num is : " << num << " in main" << std::endl; // 100

    return 0;
}
```

#### static variable
```
void static_local_example() {
    static int num = 5000;      // local to static_local_example static - retains it value between calls
    std::cout << "\nLocal static  num is: " << num << " in static_local_example - start" << std::endl;
    num += 1000;
    std::cout << "Local static  num is: " << num << " in static_local_example - end" << std::endl;
}

int main() {
    static_local_example();
    static_local_example();
    static_local_example();
    return 0;
}
```

```
Local static num is: 5000 in static_local_example - start
Local static num is: 6000 in static_local_example - end

Local static num is: 6000 in static_local_example - start
Local static num is: 7000 in static_local_example - end

Local static num is: 7000 in static_local_example - start
Local static num is: 8000 in static_local_example - end
```

#### Function Calls - Memory Stack - Recursive Function

<img src="00_docs/images/memory_stack.png" alt="Memory Stack" width="240"/>

```
#include <iostream>

unsigned long long factorial(unsigned long long val);

int main (){
    unsigned long long input;
    std::cout << "Enter factorial input: ";
    std::cin >> input;
    int result = factorial(input);
    std::cout << input << "! = " << result << std::endl;
    return 0;
}

unsigned long long factorial(unsigned long long val){
    if(val == 1){
        return 1;
    }
    return val * factorial(val-1);
}
```

### Pointers and References

**Properties**
- Pointer size is independent from which variable address it points.

#### Simple Pointers

<img src="00_docs/images/pointer.png" alt="Pointer" width="240"/>

```
#include <iostream>
#include <vector>
#include <string>

int main() {
    int num = 10;
    std::cout << "Value of num is " << num << std::endl;  
    std::cout << "Size of num is " << sizeof(num) << " bytes" << std::endl;    
    std::cout << "Address of num is " << &num << std::endl;

    int *p;
    std::cout << "\nValue of p is " << p << std::endl;  // Garbage
    std::cout << "Size of p is " << sizeof(p) << " bytes" << std::endl;    
    std::cout << "Address of p is " << &p << std::endl; 

    p = nullptr ;
    std::cout << "New value of p is " << p << std::endl; 


    int *p1 = nullptr;
    double *p2 = nullptr;
    unsigned long long *p3 = nullptr;
    std::vector <std::string> *p4 = nullptr;
    std::string *p5 = nullptr;
    
    std::cout << "\nSize of p1 is " << sizeof(p1) << std::endl;
    std::cout << "Size of p2 is " << sizeof(p2) << std::endl;
    std::cout << "Size of p3 is " << sizeof(p3) << std::endl;
    std::cout << "Size of p4 is " << sizeof(p4) << std::endl;
    std::cout << "Size of p5 is " << sizeof(p5) << std::endl;


    int score = 10;
    int *score_ptr = nullptr;
    score_ptr = &score;
    std::cout << "\nValue of score is   " << score << std::endl;
    std::cout << "Address of score is   " << score_ptr << std::endl;
    std::cout << "Value of score_ptr is " << score_ptr << std::endl;

    return 0;
}
```

```
Value of num is 10
Size of num is 4 bytes
Address of num is 0x7fff6360f448

Value of p is 0x7b2ee8628e88
Size of p is 8 bytes
Address of p is 0x7fff6360f450
New value of p is 0

Size of p1 is 8
Size of p2 is 8
Size of p3 is 8
Size of p4 is 8
Size of p5 is 8

Value of score is   10
Address of score is   0x7fff6360f44c
Value of score_ptr is 0x7fff6360f44c
```

#### Dereference Pointers

<img src="00_docs/images/dereference_pointers.png" width="480"/>

```
int main() {
    int score = 100;
    int *score_ptr = &score;
    std::cout << *score_ptr << std::endl; // 100

    *score_ptr = 200;
    std::cout << *score_ptr << std::endl; // 200
    std::cout << score << std::endl; // 200

    return 0;
}
```

#### Dynamic Memory
```
#include <iostream>

int main(){
    int *int_ptr = nullptr;
    int_ptr = new int;
    std::cout << int_ptr << std::endl; // Heap address
    delete int_ptr;

    return 0;
}
```

| Feature               | **Stack Overflow**                                      | **Memory Leak**                                  |
| --------------------- | ------------------------------------------------------- | ------------------------------------------------ |
| 📍 **Where**          | Stack (fixed-size, function call memory)                | Heap (dynamic memory you manage)                 |
| ⚙️ **Cause**          | Too many nested function calls or large local variables | Not freeing heap memory (`new` without `delete`) |
| 📉 **How it grows**   | Very quickly — usually instantly                        | Slowly over time                                 |
| 💥 **Crash behavior** | Immediate crash (`stack overflow`)                      | Slows down, then crashes (`out of memory`)       |
| 🔧 **Fix**            | Reduce recursion or local variable size                 | Use `delete` or smart pointers                   |

#### Pointer Arithmetic 
```
int main(){
    std::string s1 = "Frank";
    std::string s2 = "Frank";
    std::string s3 = "James";
    std::string *p1 = &s1;
    std::string *p2 = &s2;
    std::string *p3 = &s1;
    std::cout << std::boolalpha;
    std::cout << "\n" << p1 << " == " << p2 << ": " << (p1==p2) << std::endl;
    std::cout << p1 << " == " << p3 << ": " << (p1==p3) << std::endl;
    std::cout << *p1 << " == " << *p2 << ": " << (*p1==*p2) << std::endl;
    std::cout << *p1 << " == " << *p3 << ": " << (*p1==*p3) << std::endl;
    p3 = &s3 ;
    std::cout << *p1 << " == " << *p3 << ": " << (*p1==*p3) << std::endl;

    return 0;
}
```

```
0x7ffd1ef50cb0 == 0x7ffd1ef50cd0: false
0x7ffd1ef50cb0 == 0x7ffd1ef50cb0: true
Frank == Frank: true
Frank == Frank: true
Frank == James: false
```

#### Pass by Reference with Pointers
- void swap(int *a, int *b){ **---------->** int *a is equal to memory address
- *a = *b; **---------------------------->** *a is equal to value of the variable at that address

```
#include <iostream>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int x = 100;
    int y = 200;
    std::cout << "X: " << x << " Y: " << y << std::endl; 
    swap(&x, &y);
    std::cout << "X: " << x << " Y: " << y << std::endl;
    return 0;
}
```

```
X: 100 Y: 200
X: 200 Y: 100
```

```
void display(const std::vector <std::string> *const v){
    // (*v).at(0) = "Oben"; // Compile error (const std::vector <std::string>)
    for (std::string s : *v){
        std::cout << s << " ";
    }
    std::cout << std::endl;
    // v = null_ptr // Compile error (*const v)
}

void example2(){
    std::vector <std::string> stooges = {"Larry", "Moe", "Curly"};
    display(&stooges);
}


int main(){
    // example1();
    example2();

    return 0;
}
```


#### Some Pointer Problems
##### Uninitialized Pointer
Wrong
```
#include <iostream>

void bad_example() {
    int *ptr;           // ❌ uninitialized pointer — points to random memory
    *ptr = 42;          // ❌ undefined behavior: writing to an unknown address
    std::cout << *ptr << std::endl;
}
```

Correct 
```
#include <iostream>

void good_example() {
    int value = 0;
    int *ptr = &value;  // ✅ initialized to point to valid memory
    *ptr = 42;
    std::cout << *ptr << std::endl;  // prints 42
}
```

Dynamic Correct
```
void good_heap_example() {
    int *ptr = new int;  // ✅ memory on heap
    *ptr = 42;
    std::cout << *ptr << std::endl;
    delete ptr;          // ✅ clean up
}
```

###### Memory Leak
Wrong
```
void memory_leak_example() {
    int *ptr = new int(42);  // heap allocation

    ptr = new int(99);       // ❌ old pointer is overwritten!

    // No delete for the first allocation → memory leak!
    delete ptr;              // only frees the second allocation
}
```

Correct
```
void no_memory_leak() {
    int *ptr = new int(42);
    delete ptr;              // ✅ clean up before reassigning

    ptr = new int(99);
    delete ptr;              // ✅ clean up again
}
```

#### Reference
```
int main(){
    int num = 100;
    int &ref = num;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
    num = 500;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;
    ref = -300;
    std::cout << num << std::endl;
    std::cout << ref << std::endl;
    std::cout << &ref << std::endl;    
    return 0;
}
```

```
100
100
0x7ffe0551263c
500
500
0x7ffe0551263c
-300
-300
0x7ffe0551263c
```

#### lvalue and rvalue
| Term       | Meaning                                                                                     |
| ---------- | ------------------------------------------------------------------------------------------- |
| **lvalue** | **Left value**: has a **persistent memory address**, can appear on the left or right of `=` |
| **rvalue** | **Right value**: a **temporary value**, can only appear on the right of `=`                 |
