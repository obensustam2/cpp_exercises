# C++ Learning Handbook

# Table of Content
   - [Getting Started](#getting-started)
        - [RAII](#raii) 
        - [Compilation vs Linking](#compilation-vs-linking)
        - [Preprocessor](#preprocessor)
        - [Header Files Preprocessor](#header-files-preprocessor)
        - [Standard Template Library vs Standard Library](#standard-template-library-vs-standard-library)
        - [Standard Library Headers](#standard-library-headers)
        - [Variable](#variable)
        - [Namespace](#namespace)
        - [Arguments](#arguments)
        - [User Input](#user-input)
        - [Constant Variable and Methods](#constant-variable--methods)
        - [Mutable Keyword](#mutable-keyword)
        - [Byte Size](#byte-size)
        - [Long Variable](#long-variable)
        - [Signed vs Unsigned](#signed-vs-unsigned)
   - [Arrays and Vectors](#arrays-and-vectors)
        - [Arrays](#arrays)
        - [Vectors](#vectors)
   - [Statements and Operators](#statements-and-operators)
        - [Operator](#operator)
        - [static_cast](#static_cast)
        - [Comparision](#comparision)
        - [Compound Assignment](#compound-assignment)
        - [Operator Precedence](#operator-precedence)
        - [Precision Set](#precision-set)
   - [Controlling Program Flow](#controlling-program-flow)
        - [If-Else](#if-else)
        - [Switch-Case](#switch-case)
        - [Ternary Operator (Conditional Operator)](#ternary-operator-conditional-operator)
        - [For Loop](#for-loop)
        - [Range Based For Loop](#range-based-for-loop)
        - [While Loop](#while-loop)
        - [Do While Loop](#do-while-loop)
        - [Continue and Break](#continue-and-break)
        - [Infinite Loops](#infinite-loops)
        - [Nested Loops](#nested-loops)
   - [Characters and Strings](#characters-and-strings)
        - [C++ Strings](#c-strings)
   - [Functions](#functions)
        - [Random number generation](#random-number-generation)
        - [Nearest integer floating-point operations](#nearest-integer-floating-point-operations)
        - [Power Functions](#power-functions)
        - [Trigonometric Functions](#trigonometric-functions)
        - [Function Prototypes](#function-prototypes)
        - [Default Arguments](#default-arguments)
        - [Pass by Reference, Value, Pointer](#pass-by-reference-value-pointer)
        - [Const usage for printing with reference inputs](#const-usage-for-printing-with-reference-inputs)
        - [Local Global - Scope Rules](#local-global---scope-rules)
        - [Function Calls - Memory Stack - Recursive Function](#function-calls---memory-stack---recursive-function)
   - [Pointers](#pointers)
        - [Why Pointers Exist in C++](#why-pointers-exist-in-c)
        - [Stack and Heap Pointers](#stack-and-heap-pointers)
        - [Stack vs Heap Memory](#stack-vs-heap-memory)
        - [Stack and Heap Objects](#stack-and-heap-objects)
        - [Some Raw Pointer Problems](#some-raw-pointer-problems)
            - [Stack Overflow (Stack Memory)](#stack-overflow-stack-memory)
            - [Memory Leak (Heap Memory)](#memory-leak-heap-memory)
            - [Shallow Copy](#shallow-copy-problem)
        - [lvalue and rvalue](#lvalue-and-rvalue)
        - [Smart Pointers](#smart-pointers)
            - [unique_ptr](#unique_ptr)
            - [shared_ptr](#shared_ptr)
        - [this Pointer](#this-pointer)
   - [Classes and Objects](#classes-and-objects)
        - [Accessing class members](#accessing-class-members)
        - [Implementing Member Methods](#implementing-member-methods)
        - [Implementing Methods with Header File (.h)](#implementing-methods-with-header-file-h)
        - [Constructor & Destructor](#constructor--destructor)
        - [Copy Constructor](#copy-constructor)
            - [Shallow Copy](#shallow-copy)
            - [Deep Copy](#deep-copy)
        - [Struct](#struct)
        - [Inheritance](#inheritance)
        - [Polymorphism](#polymorphism)
            - [Virtual Functions (Dynamic Polymorphism)](#virtual-functions-dynamic-polymorphism)
   - [Enumeration](#enums)
   - [Threads](#threads)
   - [Lambda Expressions](#lambda-expressions)
   - [Interfaces](#interfaces)
   - [C++ Visibility / Access Specifiers](#c-visibility--access-specifiers)
   - [Templates](#templates)
   - [Operator Overloading](#operator-overloading)
   - [explicit Keyword](#explicit-keyword-in-c)
   - [Local static in C++](#local-static-variables-in-c)
   - [Multiple Return Value](#mutiple-return-value)







# Getting Started

## RAII
Resource Acquisition Is Initialization or RAII, is a C++ programming technique[1][2] which binds the life cycle of a resource that must be acquired before use (allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply) to the lifetime of an object.

RAII guarantees that the resource is available to any function that may access the object (resource availability is a class invariant, eliminating redundant runtime tests). It also guarantees that all resources are released when the lifetime of their controlling object ends, in reverse order of acquisition. Likewise, if resource acquisition fails (the constructor exits with an exception), all resources acquired by every fully-constructed member and base subobject are released in reverse order of initialization. This leverages the core language features (object lifetime, scope exit, order of initialization and stack unwinding) to eliminate resource leaks and guarantee exception safety. Another name for this technique is Scope-Bound Resource Management (SBRM), after the basic use case where the lifetime of an RAII object ends due to scope exit.

RAII can be summarized as follows:

encapsulate each resource into a class, where
the constructor acquires the resource and establishes all class invariants or throws an exception if that cannot be done,
the destructor releases the resource and never throws exceptions;
always use the resource via an instance of a RAII-class that either
has automatic storage duration or temporary lifetime itself, or
has lifetime that is bounded by the lifetime of an automatic or temporary object.
Move semantics enable the transfer of resources and ownership between objects, inside and outside containers, and across threads, while ensuring resource safety.

(since C++11)
Classes with open()/close(), lock()/unlock(), or init()/copyFrom()/destroy() member functions are typical examples of non-RAII classes:



## Compilation vs Linking
| Step            | Input                  | What happens                                                                                                                                                       | Output              | Happens where                 |
| --------------- | ---------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------- | ----------------------------- |
| **Compilation** | `.cpp` files           | Each `.cpp` file is compiled separately into **machine code**, but not yet complete (no connections between files).                                                | `.o` (object) files | Inside `build/CMakeFiles/...` |
| **Linking**     | `.o` files + libraries | All object files (and libraries) are **combined** into one final program. The linker **resolves all symbol references** (functions, variables, etc.) across files. | final executable    | `build/`                      |
## Linking 
Every function or global variable name (like `foo`, `bar`, `std::cout`) becomes a **symbol** inside object files.

There are two types:

- **Defined symbols**: functions/variables you define yourself  
  → e.g., `void greet() {}`

- **Undefined symbols**: references to something defined elsewhere  
  → e.g., `greet();` in another file

The linker’s job is to:

> Match every **undefined symbol** with its corresponding **defined symbol** across all object files and libraries.

## Preprocessor
The preprocessor runs before actual compilation. It handles all lines starting with #, like:
```
#include <iostream>  // includes the standard I/O library
#define PI 3.14159   // defines a constant
#ifdef DEBUG         // conditional compilation
```

## Header Files Preprocessor
| Method                       | Standard?                   | Works everywhere? | Simplicity       | Typical use           |
| ---------------------------- | --------------------------- | ----------------- | ---------------- | --------------------- |
| `#ifndef / #define / #endif` | ✅ Yes                       | ✅ 100%            | Slightly verbose | Old & modern projects |
| `#pragma once`               | ❌ No (but widely supported) | ✅ 99%             | Very simple      | Modern C++ projects   |


## Standard Template Library vs Standard Library 
| Term                     | Contains                      | Examples                                          |
| ------------------------ | ----------------------------- | ------------------------------------------------- |
| **STL**                  | Templates for data structures | `vector`, `map`, `sort`, `iterator`               |
| **C++ Standard Library** | STL + many other libraries    | `string`, `iostream`, `thread`, `regex`, `memory` |

## Standard Library Headers
```
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>
```

## Variable
A variable is just a name (or label) for a location in your computer's memory where a value is stored.
```
int age = 25;
size_t position; // unsigned int or unsigned long 
```
The computer reserves a spot in memory big enough to store an int (usually 4 bytes).
- It puts the value 25 into that memory.
- It gives that memory location a name — in this case, age.
- So when you use age, you're referring to that memory location.

## Namespace
All ROS 2 C++ functionality is grouped under the **rclcpp** namespace. This keeps the API structured and makes it clear where functions and classes come from.
```
rclcpp::shutdown();
```
rclcpp::shutdown() clearly tells the compiler "use ROS 2’s shutdown"

## Arguments
```cpp
int main(int num_args, char *args[]){
    std::cout << "Number of arguments: " << num_args << "\n";
    std::cout << "5th argument is: " << args[4] << "\n";
    return 1;
}
```

## User Input
```cpp
int num_rooms = 0;
std::cout << "How many rooms do you want to be cleaned? ";
std::cin >> num_rooms;
```

## Constant Variable & Methods
```cpp
const int age = 30;
// age = 31; // ❌ Error! Cannot modify
```

```cpp
class Person {
    std::string name;
public:
    Person(std::string n) : name(n) {}

    void printName() const {   // ✅ const member function
        // name += "!"; // ❌ Error
        std::cout << name << std::endl;
    }

    void changeName(std::string n) {  // Non-const
        name = n;
    }
};
```

## Mutable Keyword
```cpp
class Example {
    mutable int counter;  // can be changed even in const objects
public:
    Example() : counter(0) {}

    void increment() const {  // const member function
        counter++;  // allowed because counter is mutable
    }

    int getCounter() const {
        return counter;
    }
};
```

## Byte Size
```cpp
#include <iostream>
#include <string>

int main() {
    std::cout << sizeof(char) << "\n";
    std::cout << sizeof(int) << "\n";
    std::cout << sizeof(double) << "\n";
    std::cout << sizeof(std::string) << "\n";

    return 0;
}
```

```
1
4
8
32
```

## Long Variable
```cpp
long double large_amount = 2.7e120;
```

## Signed vs Unsigned
| Type                    | Bit width | Range                           |
| ----------------------- | --------- | ------------------------------- |
| `int` (signed 32-bit)   | 32        | −2,147,483,648 → +2,147,483,647 |
| `unsigned int` (32-bit) | 32        | 0 → 4,294,967,295               |


# Arrays and Vectors
## Arrays
```cpp
#include <iostream>
#include <array>

int main()
{    
    int example[5];
    std::cout << "Array address: " << example << std::endl; // pointer
    std::cout << "Length of array in bytes: " << sizeof(example) << std::endl; // bytes


    // Array For Loop
    size_t len = sizeof(example) / sizeof(example[0]);
    for(int i = 0; i < len; i++){
        example[i] = 9;
    }
    std::cout << "Forth element of example: " << example[3] << std::endl;


    // Array Pointer Aritmethic
    int *ptr = example;
    *(ptr+3) = 1;
    std::cout << "Forth element of example: " << example[3] << std::endl;
    std::cout << "Example address: " << ptr << std::endl;
    std::cout << "Address of second element in example: " << (ptr+1) << std::endl;


    // Heap Memory Array
    int *another = new int[5];
    for(int i = 0; i < 5; i++){
        another[i] = 66;
    }
    std::cout << "Forth element of another: " << another[3] << std::endl;
    delete[] another;


    // C++ 11 Array library
    std::array<int, 5> new_array;
    for(int i = 0; i < new_array.size(); i++){
        new_array[i] = 55;
    }
    std::cout << "Forth element of new_array: " << new_array[3] << std::endl;
    return 0;
}
```

## Vectors
std::vector<T> stores its elements in a contiguous dynamic array on the heap.

Internally, it uses raw pointers to manage this array.

```cpp
template<typename T>
class Vector {
    T* data_;      // raw pointer to heap memory
    size_t size_;
    size_t capacity_;
};
```
When you push_back(), it may allocate a new array, copy/move the elements, and delete the old array.

```cpp
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

# Statements and Operators
## Operator
- Operator = The symbol that performs an action
- Operand = The value or variable the operator acts on
```cpp
int a = 10;
int b = 5;
int c = a + b;
```
- "+" is the operator
- a and b are the operands
- The operator + adds the two operands

## static_cast
```cpp
std::cout << "Precise average is: " << static_cast<double>(total) / count << std::endl;
```

## Comparision
11.99999999999999999999999 and 12.0 could be equal for C++ code so be careful with the library usage

## Compound Assignment
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


```cpp
int x = 10;
x += 5;   // x = 15
x *= 2;   // x = 30
x -= 3;   // x = 27
```

## Operator Precedence
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


## Precision Set
```cpp
#include <iomanip>

if (temperatures.size() != 0){
    std::cout << std::fixed << std::setprecision(2) ;
    std::cout << "Average: " << sum/temperatures.size() << std::endl;
}
```

# Controlling Program Flow
## If-Else
```cpp
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

## Switch-Case
In C++, you cannot use switch with double or std::string directly. The switch statement only works with integral or enumeration types, such as:
- int
- char
- enum
```cpp
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

## Ternary Operator (Conditional Operator)
```cpp
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

```cpp
    for (int i = 1; i <=100; i++)
    {
        std::cout << i;
        std::cout << ((i%10 == 0) ? "\n" : " ");
    }
```

## For Loop
```cpp
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

## Range Based For Loop
The term range refers to a collection of elements you can iterate over — like arrays, vectors, lists, maps, and any container that provides begin() and end() functions (which define a range of iterators).

```cpp
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

## While Loop
```cpp
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

## Do While Loop
If you know that you must perform at least one iteration of the loop, then you should consider the do while loop over while loop.
```cpp
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

## Continue and Break
### Continue
When a continue statement is executed in the loop, no further statements in the body of the loop or executed and control immediately goes directly to the beginning of the loop for the next iteration. So you can think of this as skip processing in the rest of this iteration and go to the beginning of the loop.

### Break
When the brake statement is executed in the loop, no further statements in the body are executed and the loop is terminated. So controllers transfer to the statement immediately following the loop.

```cpp
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
```sh
1
2
3
```

## Infinite Loops
For Loop
```cpp
    for(;;){
        std::cout << "This will print forver" << std::endl;
    }
```

While Loop
```cpp
    while(true){
        std::cout << "This will print forver" << std::endl;
    }
```

Do-While Loop
```cpp
    do{
        std::cout << "This will print forver" << std::endl;
    } while(true);
```

## Nested Loops
```cpp
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

# Characters and Strings
## C++ Strings
```cpp
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

# Functions
## Random number generation
```cpp
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

## Nearest integer floating-point operations
```cpp
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

## Power functions
```cpp
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

## Trigonometric functions
```cpp
#include <iostream>
#inclue <cmath>

int main(){
    double num = 30;
    std::cout << "The sine of " << num << " is " << sin(num*(M_PI/180)) << std::endl;
    std::cout << "The cosine of " << num << " is " << cos(num*(M_PI/180)) << std::endl;

    return 0;
}
```

## Function Prototypes
```cpp
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

## Default arguments
Put the default arguments in prototypes
```cpp
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


## Pass by reference, value, pointer
```cpp
#include <iostream>

void pass_by_pointer(int *num){
    *num -= 5;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pass_by_reference(int &x){
    x -= 5;
}

void pass_by_value(int x){
    x -= 5;
}

int pass_by_value_return(int x){
    x -= 5;
    return x;
}


int main(){
    std::cout << "-------Pass by Pointer----" << std::endl;
    int my_num = 100;
    std::cout << "Before Decrement: " << my_num << std::endl;
    pass_by_pointer(&my_num);
    std::cout << "After Decrement: " << my_num << "\n" << std::endl;


    std::cout << "---------Swap with Pointer----" << std::endl;
    int a = 10;
    int b = 20;
    std::cout << "Before Swap A: " << a << " B: " << b << std::endl;
    swap(&a, &b);
    std::cout << "After Swap A: " << a << " B: " << b << "\n" << std::endl;


    std::cout << "--------Pass by Reference-----" << std::endl;
    int c = 100;
    std::cout << "Before Decrement: " << c << std::endl;
    pass_by_reference(c);
    std::cout << "After Decrement: " << c << "\n" << std::endl;


    std::cout << "------Pass by Value------" << std::endl;
    int d = 100;
    std::cout << "Before Decrement: " << d << std::endl;
    pass_by_value(d);
    std::cout << "After Decrement: " << d << "\n" << std::endl;


    std::cout << "-----Pass by Value with Return------" << std::endl;
    int e = 100;
    std::cout << "Before Decrement: " << e << std::endl;
    std::cout << "After Decrement: " << pass_by_value_return(e) << std::endl;
    
    
    return 0;
}
```
```sh
-------Pass by Pointer----
Before Decrement: 100
After Decrement: 95

---------Swap with Pointer----
Before Swap A: 10 B: 20
After Swap A: 20 B: 10

--------Pass by Reference-----
Before Decrement: 100
After Decrement: 95

------Pass by Value------
Before Decrement: 100
After Decrement: 100

-----Pass by Value with Return------
Before Decrement: 100
After Decrement: 95

```

                                                   |


## Const usage for printing with reference inputs
```cpp
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

## Local Global - Scope Rules
| Concept          | Explanation                                                                                                     |
| ---------------- | --------------------------------------------------------------------------------------------------------------- |
| **Scope**        | A variable is only accessible within the block it is declared in and its inner blocks.                          |
| **Shadowing**    | A variable in an inner scope can have the same name as one in an outer scope, temporarily hiding the outer one. |
| **Lifetime**     | Inner `num` (value 200) only exists within its block. Once the block ends, it's destroyed.                      |
| **Outer Access** | Inner blocks can access variables from outer blocks unless they’re shadowed.                                    |

```cpp
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

## Function Calls - Memory Stack - Recursive Function
```cpp
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

# Pointers

## Why Pointers Exist in C++
### The Problem: Copying is Expensive
When you pass an object to a function in C++, it makes a **full copy** by default.

For a small type like `int` (4 bytes), that's fine. But imagine a sensor struct:

```cpp
struct SensorData {
    double readings[1000];  // 8000 bytes of data
    std::string name;
    int id;
};
```

Now pass it to a function normally:

```cpp
void process(SensorData data) {
    // C++ copied all 8000+ bytes just to call this function
    data.readings[0] = 99.0;  // modifies the copy, NOT the original!
}

int main() {
    SensorData sensor;
    process(sensor);  // expensive copy, and the original is unchanged
}
```

Two problems:
1. **Slow** — copying 8000+ bytes on every function call adds up fast
2. **Wrong** — you modified a copy, not the real sensor data

### The Solution: Pass a Pointer
A pointer stores the **memory address** of the object — always just 8 bytes on a 64-bit system, regardless of how big the object is.

```cpp
void process(SensorData* data) {
    // No copy made — just passed an 8-byte address
    data->readings[0] = 99.0;  // modifies the ORIGINAL
}

int main() {
    SensorData sensor;
    process(&sensor);  // pass the address, not the whole object
}
```

| Method             | Bytes passed | Modifies original? |
|--------------------|-------------|-------------------|
| Pass by value      | 8000+       | ❌ No (copy)       |
| Pass by pointer    | 8           | ✅ Yes             |

### Why the Pointer is Always 8 Bytes
A pointer is just a memory address. On modern 64-bit hardware, all addresses are 64-bit numbers — so every pointer is 8 bytes, no matter what it points to:

```cpp
SensorData sensor;          // 8000+ bytes
SensorData* p = &sensor;    // 8 bytes — just the address

int x = 42;                 // 4 bytes
int* px = &x;               // still 8 bytes
```

> **Note:** Using a pointer to avoid copying an `int` makes no sense —
> the pointer (8 bytes) is already *bigger* than the `int` (4 bytes).
> Pointers pay off for large objects like structs, vectors, and ROS2 messages.

### Pass by Reference — The Cleaner Alternative
A **reference** is an alias for an existing variable. Under the hood it works like a pointer (just passes the address), but the syntax is cleaner — no `&` at the call site, no `->` inside the function:

```cpp
void process(SensorData& data) {   // & means "reference to"
    data.readings[0] = 99.0;       // dot syntax, modifies the ORIGINAL
}

int main() {
    SensorData sensor;
    process(sensor);               // looks like pass by value, but isn't
}
```

If you want to guarantee the function won't modify the original, add `const`:

```cpp
void printSensor(const SensorData& data) {
    // data.readings[0] = 99.0;  // compile error — const prevents this
    std::cout << data.id << std::endl;
}
```

This is the most common pattern in ROS2 callbacks:

```cpp
void callback(const sensor_msgs::msg::LaserScan& msg) {
    // msg is not copied, and cannot be modified
}
```

#### Pointer vs Reference — When to Use Which
| | Pointer `*` | Reference `&` |
|---|---|---|
| Can be null | ✅ Yes | ❌ No (always valid) |
| Can be reassigned | ✅ Yes | ❌ No (bound once) |
| Syntax | `data->field`, `&sensor` | `data.field`, no extras |
| Use when | Optional values, heap objects, smart pointers | Function params, ROS2 callbacks |

> **Rule of thumb:** prefer references for function parameters. Use pointers
> when the object might not exist (nullable) or you need to manage its lifetime.

### In Modern C++: Smart Pointers
Raw pointers work, but you have to manually free the memory — easy to forget and crash. Modern C++ uses **smart pointers** that clean up automatically:

```cpp
#include <memory>

// unique_ptr — one owner (e.g. a single ROS2 node owns the sensor driver)
auto driver = std::make_unique<SensorData>();

// shared_ptr — multiple owners (e.g. multiple nodes share sensor config)
auto config = std::make_shared<SensorData>();
```

Same efficiency as raw pointers, no manual memory management.

### Summary
| Concept | What it means |
|---|---|
| Pass by value | Full copy — safe but slow for large objects |
| Pass by pointer | Just the address (8 bytes) — fast, modifies original |
| Pass by reference | Alias for the original — clean syntax, same speed as pointer |
| `const` reference | Read-only alias — no copy, no modification (ROS2 callbacks) |
| Raw pointer (`*`) | Manual memory management — error prone |
| Smart pointer | Automatic cleanup — use these in modern C++ and ROS2 |


## Stack and Heap Pointers
```cpp
#include <iostream>
#include <string>

int main() {
    // --- Stack memory ---
    int stackVar = 42;           // stack variable
    int* stackPtr = &stackVar;   // pointer to stack variable

    std::cout << "Stack variable value: " << stackVar << std::endl;
    std::cout << "Stack variable address: " << &stackVar << std::endl;
    std::cout << "Stack pointer value (points to stackVar): " << stackPtr << std::endl;
    std::cout << "Stack pointer dereferenced: " << *stackPtr << std::endl;

    // --- Heap memory ---
    int* heapVar = new int(99);  // allocate int on heap
    std::cout << "\nHeap variable value: " << *heapVar << std::endl;
    std::cout << "Heap pointer address: " << &heapVar << std::endl;   // address of the pointer itself (on stack)
    std::cout << "Heap memory address it points to: " << heapVar << std::endl; // address of heap memory

    // Update heap value through pointer
    *heapVar = 123;
    std::cout << "Heap variable updated value: " << *heapVar << std::endl;

    // Free heap memory
    delete heapVar;
    heapVar = nullptr;           // avoid dangling pointer

    return 0;
}
```

```sh
Stack variable value: 42
Stack variable address: 0x7ffee3c8a6ac
Stack pointer value (points to stackVar): 0x7ffee3c8a6ac
Stack pointer dereferenced: 42

Heap variable value: 99
Heap pointer address: 0x7ffee3c8a6b0
Heap memory address it points to: 0x600003e000
Heap variable updated value: 123
```

## Stack vs Heap Memory
| Feature              | **Stack**                                                                 | **Heap**                                                                 |
|-----------------------|---------------------------------------------------------------------------|--------------------------------------------------------------------------|
| **Size limit**        | Small & fixed (e.g., ~8 MB per thread on Linux)                          | Large & flexible (limited by system RAM, often GBs)                      |
| **Lifetime**          | Automatic: variables destroyed when scope ends                           | Manual: memory stays until `delete` or smart pointer frees it             |
| **Speed**             | Very fast (simple push/pop operations)                                   | Slower (requires OS bookkeeping and possible fragmentation)               |
| **Allocation**        | Done automatically by compiler                                           | Done manually with `new`, `malloc`, or containers like `std::vector`      |
| **Deallocation**      | Automatic when scope ends                                                | Manual (`delete` / `delete[]`), or automatic with smart pointers/RAII     |
| **Typical usage**     | Local variables, function parameters, small temporary objects            | Large data, dynamic arrays, objects needing custom lifetime               |
| **Errors**            | Stack overflow (too much usage)                                          | Memory leak (forgetting to free), dangling pointers, fragmentation        |
| **Example**           | `int x = 10;`                                                           | `int* p = new int(10); delete p;`                                        |
| **Analogy**           | Lunch tray (items stacked & removed in order)                           | Warehouse (flexible storage, but must clean up yourself)                  |


## Stack and Heap Objects
```cpp
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
```

## Some Raw Pointer Problems

### Stack Overflow (Stack Memory)
**int** stores 4 bytes. BigStackArray has 4.000.000 elements -> 4.000.000 x 4 = 16.000.000 Byte = 16 MB. Which is higher than stack memory size (8 MB). Code will give error.
```cpp
#include <iostream>

int main(){

    // stack memory
    int bigStackArray[4000000]; 
    bigStackArray[0] = 0;
    std::cout << "First Element: " << bigStackArray[0] << std::endl; 
}
```

### Memory Leak (Heap Memory)
Creating 16MB array in each loop will exceed the 9GB available system RAM and system will crash
```cpp
#include <iostream>

int main(){

    while(true){
        new int[4000000];
    }

    return 0;
}
```

### Shallow Copy Problem
- Copying raw pointers copies only the address, not the actual object → two objects point to the same memory.

- Leads to double deletion when both destructors try to free the same heap memory.

- Deep copy is needed to safely duplicate objects that own dynamic memory.


## lvalue and rvalue

| Term       | Meaning                                                                                                    | Examples                               |
| ---------- | ---------------------------------------------------------------------------------------------------------- | -------------------------------------- |
| **lvalue** | An object that has an identifiable location in memory (can appear on the left-hand side of assignment).    | variables (`x`), dereferenced pointers (`*p`) |
| **rvalue** | A temporary value or literal without a persistent memory address (usually on the right-hand side of `=`).  | `5`, `x+1`, return value of a function |


## Smart Pointers
### Pointer Comparison: Normal vs Smart Pointers

| Feature | Raw Pointer (`T*`) | `unique_ptr<T>` | `shared_ptr<T>` | `weak_ptr<T>` |
|---|---|---|---|---|
| **Ownership** | Manual / unclear | Exclusive | Shared (ref-counted) | Non-owning observer |
| **Memory management** | Manual (`delete`) | Automatic (RAII) | Automatic (RAII) | None (doesn't own) |
| **Copyable** | Yes | No | Yes (increments ref count) | Yes |
| **Movable** | Yes | Yes | Yes | Yes |
| **Overhead** | None | None | Ref-count + control block | Same as `shared_ptr` |
| **Null-safe** | No | No | No | Via `.lock()` check |
| **Access syntax** | `->`, `*` | `->`, `*` | `->`, `*` | Must call `.lock()` first |
| **Risk of dangling pointer** | High | None | None | Yes (if owner is gone) |
| **Risk of double free** | High | None | None | N/A |
| **Cyclic reference safe** | N/A | N/A | No (causes memory leak) | Yes (breaks cycles) |
| **Use case** | Legacy C code, low-level APIs | Single owner, factory returns | Shared ownership across components | Cache, observer, breaking cycles |
| **Header** | Built-in | `<memory>` | `<memory>` | `<memory>` |
| **C++ standard** | All | C++11 | C++11 | C++11 |

### unique_ptr
```cpp
#include <iostream>
#include <memory>

class Car{
private:
    std::string model_;

public:
    // Constructor
    Car(const std::string &model) : model_(model){
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // Deconstructor
    ~Car(){
       std::cout << "Car " << model_ << " destroyed 💥\n"; 
    }

    // A method
    void drive() const{
        std::cout << "Car " << model_ << " is driving...\n";
    }
};

int main(){
    std::cout << "--- Unique Pointer Example ---\n";

    // Create a Car object on the heap, owned by unique_ptr
    std::unique_ptr<Car> car1_ptr = std::make_unique<Car>("Tesla");
    std::cout << "Debug 1 \n";

    // Use the object via unique_ptr
    car1_ptr->drive();

    // Transfer ownership to another unique_ptr
    std::unique_ptr<Car> car2_ptr = std::move(car1_ptr);

    if(!car1_ptr){
        std::cout << "car1_ptr no longer owns the object.\n";
        std::cout << "Car1 Pointer: " << car1_ptr.get() << std::endl;
        std::cout << "Car2 Pointer: " << car2_ptr.get() << std::endl;
    }

    car2_ptr->drive();

    // No need to delete manually → car2_ptr automatically destroys the object

    return 0;
} 
```

```sh
--- Unique Pointer Example ---
Car Tesla created 🚗
Debug 1 
Car Tesla is driving...
car1_ptr no longer owns the object.
Car1 Pointer: 0
Car2 Pointer: 0x5cfb68de12c0
Car Tesla is driving...
Car Tesla destroyed 💥
```

### shared_ptr
```cpp
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
```

```sh
Line: 43
Sensor created
Line: 45
Line: 47
Line: 49
Camera got 42
Line: 51
Logger got 42
Line: 53
Sensor destroyed
```

## this Pointer
**this** is always a pointer to the object itself, but it does not know whether the object is on the stack or heap.

```cpp
#include <iostream>
#include <string>

class Entity;
void printEntity(Entity &e);

class Entity{
public:
    int x, y;

    Entity(int x, int y) {  
        this->x = x;
        this->y = y;
    
        printEntity(*this);
    }

    int get_x() const{
        return this->x;
    }
};

void printEntity(Entity &e){
    std::cout << e.x << ", " << e.y << std::endl;
}

int main(){
    Entity e1(3,5);

    return 0;
}
```

```sh
3, 5
```


# Classes and Objects
## Accessing class members
```cpp
#include <iostream>
#include <string>
#include <vector>


class Player{
public:
    // attributes
    std::string name;
    int health;
    int experience;

    // methods
    void talk(std::string text_to_say){ std::cout << name << " says " << text_to_say << std::endl;}
    bool is_dead();
};


class Account{
public:
    // attributes
    std::string name;
    double balance;

    // methods
    bool deposit(double bal){ balance += bal;  std::cout << "In deposit" << std::endl; return true;}
    bool withdraw(double bal){ balance -= bal; std::cout << "In withdraw" << std::endl; return true;}
};


int main (){
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.experience = 12;
    frank.talk("Hi");

    Player *enemy = new Player;
    enemy->name = "Enemy";
    enemy->health = 100;
    enemy->talk("I will destroy you");

    Account n26;
    n26.balance = 1000;
    n26.deposit(500);
    std::cout << n26.balance << std::endl;


    return 0;
}
```

## Implementing Member Methods 
```cpp
#include <iostream>
#include <string>
#include <vector>



class Account{
private:
    // attributes
    std::string name;
    double balance;

public:
    // methods declared inline
    void set_balance(double bal){
        balance = bal;
    }

    double get_balance(){
        return balance;
    }

    // methods will be declared outside the class declaration
    void set_name(std::string name);
    std::string get_name();
    bool deposit(double amount);
    bool withdraw(double amount);
};


void Account::set_name(std::string n){
    name = n;
}

std::string Account::get_name(){
    return name;
}

bool Account::deposit(double amount){
    balance += amount;
    return true;
}

bool Account::withdraw(double amount){
    if (balance-amount >= 0){
        balance -= amount;
        return true;
    }
    else {
        return false;
    }

}



int main (){

    Account n26;
    n26.set_name("Oben Main Account");
    n26.set_balance(1000.0);

    if (n26.deposit(200.0)){
        std::cout << "Deposit OK" << std::endl;
    }
    else{
        std::cout << "Deposit not allowed" << std::endl;
    }

    if (n26.withdraw(500.0)){
        std::cout << "Withdraw OK" << std::endl;
    }
    else{
        std::cout << "Not sufficient funds" << std::endl;
    }

    if (n26.withdraw(1500.0)){
        std::cout << "Withdraw OK" << std::endl;
    }
    else{
        std::cout << "Not sufficient funds" << std::endl;
    }


    return 0;
}
```

```sh
Deposit OK
Withdraw OK
Not sufficient funds
```

## Implementing Methods with Header File (.h)
**account.h**
```cpp
#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <string>

class Account{
private:
    std::string name;
    double balance;

public:
    std::string get_name();
    double get_balance();
    void set_name(std::string);
    void set_balance(double);
    bool deposit(double);
    bool withdraw(double);
    
    
};


#endif // _ACCOUNT_H_
```

**04_account.cpp**
```cpp
#include "account.h"

void Account::set_name(std::string n){
    name = n;
}

std::string Account::get_name(){
    return name;
}

bool Account::deposit(double dep){
    balance += dep;
    return true;
}

bool Account::withdraw(double with){
    if(balance-with >= 0){
        balance -= with;
        return 1;
    }
    else{
        return 0;
    }
}

void Account::set_balance(double bal){
    balance = bal;
}

double Account::get_balance(){
    return balance;
}
```

**04_main.cpp**
```cpp
#include "account.h"

int main(){
    Account n26;
    n26.set_name("Oben Sustam");
    n26.set_balance(1000);
    std::cout << "Username: " << n26.get_name() << std::endl;
    std::cout << "Balance: " << n26.get_balance() << std::endl;
    n26.deposit(500);
    std::cout << "Balance after deposit: " << n26.get_balance() << std::endl;

    if(n26.withdraw(200)){
        std::cout << "Balance after withdraw: " << n26.get_balance() << std::endl;
    }
    else{
        std::cout << "Not enough money" << std::endl;
    }

    if(n26.withdraw(2200)){
        std::cout << "Balance after withdraw: " << n26.get_balance() << std::endl;
    }
    else{
        std::cout << "Not enough money" << std::endl;
    }

    return 0;
}
```

## Constructor & Destructor
```cpp
#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    int health;
    int xp;

public:
    // Overloaded Constructors (with different parameters (type, number, or order).)
    Player() : 
        name("Oben"), health(99), xp(29){
    }
    
    Player(std::string &name_val) :   
        name(name_val), health(80), xp(22){
    }

    Player(std::string &name_val, int &health_val, int &xp_val) : 
        name(name_val), health(health_val), xp(xp_val){
    }

    // Destructor
    ~Player(){
        std::cout << "Destructor called for " << name << std::endl;
    }

    std::string get_name(){
        return name;
    }

    int get_health(){
        return health;
    }


};


int main() {
    std::cout << "--- Creating first player ---" << std::endl;
    Player first_player;
    std::cout << first_player.get_name() << std::endl;
    std::cout << first_player.get_health() << std::endl;

    std::cout << "\n--- Creating second player ---" << std::endl;
    Player second_player("Orbay");
    std::cout << second_player.get_name() << std::endl;
    std::cout << second_player.get_health() << std::endl;

    std::cout << "\n--- Creating third player ---" << std::endl;
    Player third_player("Orcun", 100, 20);
    std::cout << third_player.get_name() << std::endl;
    std::cout << third_player.get_health() << std::endl;

    std::cout << "\n--- End of main ---" << std::endl;
    return 0;
}
```

```sh
--- Creating first player ---
Default constructor called for Oben
Oben
99

--- Creating second player ---
Single-parameter constructor called for Orbay
Orbay
80

--- Creating third player ---
Three-parameter constructor called for Orcun
Orcun
100

--- End of main ---
Destructor called for Orcun
Destructor called for Orbay
Destructor called for Oben
```

## Copy Constructor
```cpp
#include <iostream>
#include <memory>
#include <string>

class Car{
private:
    std::string model_;

public:
    // Constructor
    Car(const std::string &model) : model_(model){
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // Copy constructor
    Car(const Car& other) : model_(other.model_){
        std::cout << "Car " << model_ << " copied 🧬\n";
    }

    // Destructor
    ~Car(){
       std::cout << "Car " << model_ << " destroyed 💥\n"; 
    }

    void drive() const{
        std::cout << "Car " << model_ << " is driving...\n";
    }
};

int main(){
    std::cout << "--- Copy Constructor Example ---\n";

    // Normal stack object
    Car car1("BMW");

    // Copy construction
    Car car2 = car1;   // <-- calls copy constructor

    car2.drive();

    std::cout << "End of main()\n";
    
    return 0;
}
```

```sh
--- Copy Constructor Example ---
Car BMW created 🚗
Car BMW copied 🧬
Car BMW is driving...
End of main()
Car BMW destroyed 💥
Car BMW destroyed 💥
```

### Shallow Copy
```cpp
#include <iostream>
#include <cstring>

class Car {
private:
    char* model_;   // heap-allocated string

public:
    Car(const char* model) {
        model_ = new char[strlen(model) + 1];
        std::strcpy(model_, model);
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // ❌ Shallow copy constructor
    Car(const Car& other) {
        model_ = other.model_;   // pointer copied only
        std::cout << "Car shallow-copied ⚠️\n";
    }

    ~Car() {
        std::cout << "Destroying car " << model_ << "\n";
        delete[] model_;   // double delete risk!
    }
};

int main() {
    Car c1("BMW");
    Car c2 = c1;   // shallow copy

    return 0; // 💥 undefined behavior when both destructors run
}
```

- c1 and c2 share same memory
- both call delete[]
- → crash / undefined behavior

### Deep Copy
```cpp
#include <iostream>
#include <cstring>

class Car {
private:
    char* model_;

public:
    Car(const char* model) {
        model_ = new char[strlen(model) + 1];
        std::strcpy(model_, model);
        std::cout << "Car " << model_ << " created 🚗\n";
    }

    // ✅ Deep copy constructor
    Car(const Car& other) {
        model_ = new char[strlen(other.model_) + 1];
        std::strcpy(model_, other.model_);
        std::cout << "Car deep-copied ✅\n";
    }

    ~Car() {
        std::cout << "Destroying car " << model_ << "\n";
        delete[] model_;
    }
};

int main() {
    Car c1("Audi");
    Car c2 = c1;   // deep copy

    return 0; // safe
}
```


## Struct
| Feature                 | `class`   | `struct` |
| ----------------------- | --------- | -------- |
| **Default access**      | `private` | `public` |
| **Default inheritance** | `private` | `public` |

```cpp
#include <iostream>
#include <string>

struct Log {
    int severity;
    std::string text;

    void print() {
        std::cout << "Logging Severity: " << severity << ", Text: " << text << "\n";
    }
};


int main(){
    Log my_log;
    my_log.severity = 2;
    my_log.text = "Hello World";
    my_log.print();

    return 0;
}
```

```sh
Logging Severity: 2, Text: Hello World
```


## Inheritance

**Inheritance** means that one class (called the *child* or *derived* class) can **reuse and extend** the properties and behaviors of another class (called the *parent* or *base* class).

> A derived class inherits everything from its base class — and can add or change features.

---

```cpp
#include <iostream>

class Entity{
public:
    float X, Y;

    void move(float xa, float ya){
        X += xa;
        Y += ya;  
    }
};

class Player : public Entity{
public: 
    const char *name;

    void printName(){
        std::cout << name << std::endl;
    }

};

int main(){

    std::cout << sizeof(Entity) << std::endl;
    std::cout << sizeof(Player) << std::endl;

    Player p1;
    p1.name = "Oben";
    p1.move(5,5);
    std::cout << p1.X << std::endl;
    p1.printName();
    return 0;
}
```

```sh
8
16
5
Oben
```

## Polymorphism
Polymorphism literally means “many forms.”
In programming, it means the same function, operator, or method name can behave differently depending on the type of object or data it’s working with.

**Why It Exists?**

It allows you to write flexible and reusable code — you don’t have to know the exact type of object in advance, yet the correct behavior will still happen automatically.

**Two Main Types**
| Type                          | Also called            | Achieved by                                           | When it happens        |
| ----------------------------- | ---------------------- | ----------------------------------------------------- | ---------------------- |
| **Compile-time polymorphism** | *Static polymorphism*  | Function overloading, operator overloading, templates | During compilation     |
| **Runtime polymorphism**      | *Dynamic polymorphism* | Virtual functions and inheritance                     | While the program runs |

### Compile-time Polymorphism
The function that will be called is known at compile time.
```cpp
#include <iostream>
void print(int x) { std::cout << "Integer: " << x << "\n"; }
void print(double x) { std::cout << "Double: " << x << "\n"; }

int main() {
    print(5);     // Calls print(int)
    print(5.5);   // Calls print(double)
}
```
Same function name (print), different behavior depending on parameter type.


### Virtual Functions (Dynamic Polymorphism)
The function that will be called is determined at runtime — usually using virtual functions in a base class and overriding them in derived classes.

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() { std::cout << "Some sound\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof!\n"; }
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow!\n"; }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak();  // Outputs "Woof!"
    a2->speak();  // Outputs "Meow!"
}
```

Even though both a1 and a2 are pointers to Animal, the correct function (Dog::speak or Cat::speak) is chosen at runtime.



# Inheritance + Dynamic Polymorphism (Virtual Functions) + Pointer Example
```cpp
#include <iostream>
#include <string>
#include <memory>

class Animal{
protected:
    std::string name_;

public:
    Animal(std::string name) : name_(name){
    }

    void eat(){
        std::cout << name_ << " is eating." << std::endl;
    }

    // virtual enables polymorphism
    virtual void sleep(){
        std::cout << name_ << " is sleeping." << std::endl;
    }
};

class Dog : public Animal{
public:
    Dog(std::string dog_name) : Animal(dog_name){
    }

    void bark(){
        std::cout << name_ << " is barking." << std::endl;
    }

    // override the base version
    void sleep() override{
        std::cout << name_ << " is snoring while sleeping." << std::endl;
    }
};


int main(){

    // stack object
    Dog d1("Boncuk");
    d1.eat();
    d1.bark();
    d1.sleep();

    // stack object
    Animal a1("Kertenkele");
    a1.sleep(); 

    // stack pointer
    Dog d2("Cesur");
    Dog *d2_ptr = &d2;
    d2_ptr->sleep();

    // raw heap pointer
    Animal *a2 = new Animal("Sincap");
    a2->sleep();
    delete a2;

    // smart pointer (heap)
    std::unique_ptr<Animal> a3 = std::make_unique<Animal>("Fare");
    a3->sleep();

    return 0;
}
```

Memory Layout
```sh
STACK (automatic variables)
+-------------------------------+
| d1 : Dog("Boncuk")            | <-- Dog object (includes Animal::name_="Boncuk")
+-------------------------------+
| a1 : Animal("Kertenkele")     | <-- Animal object
+-------------------------------+
| d2 : Dog("Cesur")             | <-- Dog object (Animal::name_="Cesur")
+-------------------------------+
| d2_ptr : pointer -> &d2       | <-- stack pointer pointing to d2
+-------------------------------+
| a2 : pointer -> Heap("Sincap")| <-- raw pointer on stack
+-------------------------------+
| a3 : unique_ptr -> Heap("Fare")| <-- smart pointer on stack
+-------------------------------+
```

```sh
HEAP (dynamic memory)
+-------------------------------+
| Animal("Sincap")              | <-- pointed by a2 (raw heap pointer)
+-------------------------------+
| Animal("Fare")                | <-- pointed by a3 (smart pointer)
+-------------------------------+
```


# Enums
An **enum** (short for *enumeration*) is a user-defined type that assigns names to a set of integer constants.  
It makes code more readable and easier to maintain.

```cpp
#include <iostream>
using namespace std;

enum Direction {
    North,   // 0
    East,    // 1
    South,   // 2
    West     // 3
};

int main() {
    Direction dir = South;

    if (dir == South)
        cout << "Going South!" << endl;

    cout << "Direction value: " << dir << endl; 
}
```

```sh
Going South
Direction Value: 2
```

# Threads
## join vs detach

| Feature                     | `join()`                          | `detach()`                      |
|-----------------------------|----------------------------------|--------------------------------|
| Wait for thread             | ✅ Yes (blocks until thread ends) | ❌ No (runs independently)     |
| Safe to access results      | ✅ Yes                            | ❌ No                          |
| Thread cleanup              | Automatic after thread finishes   | Automatic after thread finishes|
| Use case                    | Coordinated work / dependencies   | Background / fire-and-forget  |
| Thread ownership            | Thread remains joinable           | Thread is detached (no ownership) |
| Consequence if thread object is destroyed without join/detach | ❌ `std::terminate()` | ❌ Undefined behavior if accessing out-of-scope data |

## atomic vs mutex
| Feature             | `std::atomic`                                                                                | `std::mutex`                                                                        |
| ------------------- | -------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------- |
| **Purpose**         | Provides lock-free atomic operations on a single variable                                    | Provides mutual exclusion for critical sections (any block of code)                 |
| **Scope**           | Works only for the variable it wraps                                                         | Can protect **multiple variables** or a whole code section                          |
| **Locking**         | No explicit locking; atomic operations happen in hardware                                    | Explicit locking (`lock()`) and unlocking (`unlock()`), or `std::lock_guard`        |
| **Performance**     | Usually faster because lock-free (depends on hardware)                                       | Can be slower due to OS-level locking and context switching                         |
| **Use cases**       | Counters, flags, shared state of a single variable                                           | Complex operations, multiple variables, critical sections, or non-atomic operations |
| **Complexity**      | Simple API (`load`, `store`, `fetch_add`, etc.)                                              | More general, requires careful lock management to avoid deadlocks                   |
| **Deadlocks**       | Impossible                                                                                   | Possible if multiple mutexes are locked in the wrong order                          |
| **Memory ordering** | Supports fine-grained memory ordering (`memory_order_relaxed`, `memory_order_seq_cst`, etc.) | Mutex automatically provides sequential consistency                                 |


## Join
Do I need the thread’s work to finish before continuing?
- If yes → join soon after creation.
- If no, it’s background work → join when shutting down.

```cpp
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


std::mutex mtx1, mtx2;
int counter = 0;


void increment1(int id){
    for(int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock(mtx1); // locks the mutex
        counter++; // safe access
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
} // lock goes out of scope here → mutex is automatically unlocked

void increment2(int id){
    for(int i=0; i<5; i++){
        std::lock_guard<std::mutex> lock(mtx2);
        counter += 5;
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
    }
}


int main(){
    std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
    
    std::thread t1(increment1, 1);
    std::thread t2(increment2, 2);

    t1.join();
    t2.join();

    std::cout << "Final counter: " << counter << "\n";

    return 0;
}
```

```sh
oben@oben-ABRA-A5-V13-2:~/cpp_exercises/xx_interview_preparation/build$ ./13_thread_mutex 
Main ID: 129642844219200
Thread Thread 2 incremented counter to 6
Thread 2 incremented counter to 11
Thread 2 incremented counter to 16
Thread 2 incremented counter to 21
Thread 2 incremented counter to 26
1 incremented counter to 26
Thread 1 incremented counter to 27
Thread 1 incremented counter to 28
Thread 1 incremented counter to 29
Thread 1 incremented counter to 30
Final counter: 30
oben@oben-ABRA-A5-V13-2:~/cpp_exercises/xx_interview_preparation/build$ ./13_thread_mutex 
Main ID: 136471178823488
Thread 1 incremented counter to 1
Thread 1 incremented counter to 2
Thread 1 incremented counter to 3
Thread 1 incremented counter to 4
Thread 1 incremented counter to 5
Thread 2 incremented counter to 10
Thread 2 incremented counter to 15
Thread 2 incremented counter to 20
Thread 2 incremented counter to 25
Thread 2 incremented counter to 30
Final counter: 30
```

Unlock Version
```cpp
std::mutex mtx;
int counter = 0;

void increment_manual(int id) {
    for(int i = 0; i < 5; i++) {
        mtx.lock();  // manually lock the mutex
        counter++;   // critical section
        std::cout << "Thread " << id << " incremented counter to " << counter << "\n";
        mtx.unlock(); // manually unlock the mutex
    }
}
```

Atomic Version
```cpp
std::atomic<int> counter(0); // atomic counter

void increment1(int id){
    for(int i=0; i<5; i++){
        counter++; // atomic increment
        std::cout << "Thread " << id << " incremented counter to " << counter.load() << "\n";
    }
}
```

## Detach
```cpp
#include <iostream>
#include <thread>
#include <chrono>


void backgroundTask(){
    std::cout << "backgroundTask ID: " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "backgroundTask finished" << std::endl;
}

int main(){
    std::cout << "Main ID: " << std::this_thread::get_id() << std::endl;
    
    std::thread baby_thread(backgroundTask);
    baby_thread.detach();

    for(int i=0;i<5;i++){
        std::cout << "I don't wait the backgroundTask completion to run" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Exiting the program." << std::endl;

    return 0;
}
```



# Lambda Expressions
a lambda expression is essentially an anonymous function you can define inline without giving it a name. It's often used for short, local operations, such as sorting, filtering, or passing functions to algorithms.

```sh
auto FUNCTION_NAME = [capture](parameters){
    // function body
};
```

- auto tells the compiler: “Deduce the type of this lambda for me.”. Its type is unique and known only to the compiler (you cannot write it explicitly).

- [capture]: captures variables from the surrounding scope.

- (parameters): the function arguments, like in a normal function.

- function body: what the lambda does.

```cpp
#include <iostream>
#include <string>


int main(){

    // Simple Lambda
    auto greet = [](){
        std::cout << "Hello Lambda!" << std::endl;
    };
    greet();
    greet();


    // Lambda with parameters
    auto add = [](int a, int b){
        return a+b;
    };
    std::cout << "Add: " << add(3,4) << std::endl; 


    // Lambda with capturing variables
    int x = 10;
    int y = 5;
    auto sum = [x,y](){
        return x+y;
    };
    std::cout << "Sum: " << sum() << std::endl; 


    // Lambda with auto parameter
    auto print = [](auto val){
        std::cout << val << std::endl;
    };
    print("Oben");
    print(29);


    return 0;
}
```

# Interfaces
What is an Interface in C++?

- C++ does not have a dedicated interface keyword like Java or C#. Instead, interfaces are implemented using abstract classes, specifically classes that contain only pure virtual functions.

- Definition of an Interface (Abstract Class)
    - A class is considered an interface when:
    - All its methods are pure virtual (declared with = 0).
    - It contains no data members (ideally).
    - It defines a contract that derived classes must implement.

```cpp
// Interface for any robot gripper
class IGripper {
public:
    virtual void open() = 0;          // pure virtual
    virtual void close() = 0;         // pure virtual
    virtual bool isHolding() const = 0;

    virtual ~IGripper() {}            // always add virtual destructor
};
```

```cpp
class FanucGripper : public IGripper {
public:
    void open() override {
        std::cout << "Fanuc gripper opening...\n";
    }

    void close() override {
        std::cout << "Fanuc gripper closing...\n";
    }

    bool isHolding() const override {
        return true; // example
    }
};
```

```cpp
IGripper* gripper = new FanucGripper();
gripper->open();
gripper->close();
delete gripper;
```

# C++ Visibility / Access Specifiers

| Specifier   | Accessible From Class Itself | Accessible from Derived Classes | Accessible from Outside | Typical Use |
|-------------|------------------------------|----------------------------------|--------------------------|-------------|
| `public`    | Yes                          | Yes                              | Yes                      | Public API, interface to the class |
| `protected` | Yes                          | Yes                              | No                       | Allow derived classes to reuse/extend functionality |
| `private`   | Yes                          | No                               | No                       | Strict encapsulation; internal details |

## Notes
- **Default access**:  
  - `class` → `private`  
  - `struct` → `public`
- Inheritance can also change visibility (public / protected / private inheritance).


# Templates
Templates avoid code duplication.

They are resolved at compile time, which means the compiler generates a specific function/class for each type used.

```cpp
#include <iostream>
#include <string>

template<typename T>
void print(T value){
    std::cout << value << std::endl;
}

template<typename T1, typename T2>
void sum(T1 num1, T2 num2){
    std::cout << "Sum: " << num1 + num2 << std::endl;
}


template<typename type, int size>
class Array{
private:
    type arr[size];
public:
    int getSize(){
        return size;
    }
};



int main(){

    // Testing of template function      
    print("Hello");
    print(23);
    print(55.57);

    sum(10, 3);
    sum(10.4, 5.44);


    // Testing of template class
    Array<float, 7> array;
    std::cout << array.getSize() << std::endl;

    return 0;
}
```

Output
```sh
Hello
23
55.57
Sum: 13
Sum: 15.84
7
```

## Operator Overloading
```cpp
#include <iostream>
#include <string>

struct Vector2
{
    float x, y;

    Vector2(float _x, float _y) : 
        x(_x), y(_y){
    }

    Vector2 add(const Vector2 &new_vector) const {
        return Vector2(x + new_vector.x, y + new_vector.y);
    }

    Vector2 operator+(const Vector2 &new_vector) {
        return add(new_vector);
    }

    Vector2 multiply(const Vector2 &new_vector) const {
        return Vector2(x * new_vector.x, y * new_vector.y);
    }

    Vector2 operator*(const Vector2 &new_vector) {
        return multiply(new_vector);
    }

};

std::ostream &operator<<(std::ostream &stream, const Vector2 &other){
    stream << other.x << ", " << other.y;
    return stream;
} 

int main(){
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    Vector2 result = position.add(speed.multiply(powerup));
    Vector2 result2 = position + speed * powerup ;

    std::cout << result2 << std::endl;

    return 0;
}
```
```sh
4.55, 5.65
```

# `explicit` keyword in C++
Prevents the compiler from silently converting one type into your class.

## Without `explicit` — silent conversion (dangerous)
```cpp
class Box {
public:
    Box(int value) : value_(value) {}
};

void ship(Box b) {}

ship(42);  // compiles! compiler secretly does Box(42) behind your back
```

## With `explicit` — conversion must be intentional
```cpp
class Box {
public:
    explicit Box(int value) : value_(value) {}
};

ship(42);       // ERROR — caught by compiler
ship(Box(42));  // OK — intent is clear
```

## Rule of thumb
> Mark every single-argument constructor `explicit` unless you specifically want implicit conversions.

Implicit conversions are almost never what you want — they hide intent and create hard-to-spot bugs. Most modern C++ guidelines recommend `explicit` by default.


# Local Static Variables in C++
A `static` variable inside a function is **initialized once** and keeps its value between calls.

```cpp
#include <iostream>

void function(){
    static int i = 0;  // initialized once, persists across calls
    i++;
    std::cout << i << std::endl;
}

int main(){
    for(int j = 0; j < 5; j++){
        function();
    }
    return 0;
}
```

Output:
```
1
2
3
4
5
```

Without `static`, `i` resets to `0` every call and always prints `1`.
| Property | Normal local | Local static |
|---|---|---|
| Initialized | Every call | Once |
| Lifetime | Dies on return | Entire program |
| Scope | Inside function | Inside function |


# Mutiple Return Value
| Feature | std::tuple | struct |
|---|---|---|
| Naming | Anonymous (accessed by index) | Descriptive names (.name, .age).
| Readability | Low. std::get<0>(data) is cryptic | High. data.name is clear.
| Definition | None required. Use "on the fly." | Requires a struct { ... }; definition.
| Maintenance | Fragile. Changing order breaks code. | Robust. Member order doesn't matter.
| Best Use Case | Quick, internal helper functions. | Public APIs and shared data models.
```cpp
#include <iostream>
#include <string>
#include <tuple>

////////// TUPLE ////////////////
// Function returning tuple
std::tuple<std::string, int, float> tupleStudentData(){
    return {"Oben", 29, 1.4};
}

int tuple_solution(){
    // Modern C++17 way to unpack (Structured Bindings)
    auto [name, age, gpa] = tupleStudentData();
    
    // Older way (if you can't use C++17)
    // std::string n = std::get<0>(getStudentData());

    std::cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << std::endl;

    return 0;
}


////////// STRUCT ////////////////
struct StudentData
{
    std::string name;
    int age;
    float gpa;
};


StudentData structStudentData(){
    return {"Verena", 28, 1};
}

int struct_solution(){
    StudentData s = structStudentData();

    std::cout << "Name: " << s.name << ", Age: " << s.age << ", GPA: " << s.gpa << std::endl;

    return 0;
}



int main(){

    tuple_solution();

    struct_solution();

    return 0;
}
```