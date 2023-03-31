#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstring>
#include <iostream>

class MyString {
private:
    char* str;
    int size;
public:
    MyString(const char* s);
    MyString(const MyString& other);
    ~MyString();
    void print();
    static int strlen(const char* s);
    char* strcpy(char* str, const char* s);
    void change(const char* s);
    void parseString(const char* s);
};

#endif // MY_STRING_H
