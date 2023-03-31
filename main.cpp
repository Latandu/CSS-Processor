
#include "MyString.h"

int main() {
    MyString str1 = "h1";
    MyString str2(str1);
    str1.print();
    str2.print();
    str2.change("World");
    str1.print();
    str2.print();
    return 0;
}