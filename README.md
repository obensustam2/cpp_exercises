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


### Variable
A variable is just a name (or label) for a location in your computer's memory where a value is stored.
```
int age = 25;
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
