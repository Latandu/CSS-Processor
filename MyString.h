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
    char* addchar(char *str, int& reservedSize, char newChar);
    static int strlen(const char* s);
    static char* strcpy(char* str, const char* s);
    void change(const char* s);
    char *printarr();

    MyString();
};

#endif // MY_STRING_H
