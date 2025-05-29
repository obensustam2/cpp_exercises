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

