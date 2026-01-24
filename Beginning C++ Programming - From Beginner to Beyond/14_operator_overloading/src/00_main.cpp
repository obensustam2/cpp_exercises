#include "myString.h"

int main(){
    MyString empty;
    MyString larry("LarRy");
    MyString stooge{larry};

    empty.display();
    larry.display();
    stooge.display();
}