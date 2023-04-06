#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstring>
#include <iostream>

class MyString {
private:
    char* str{};
    int size{};
public:
    MyString(const char* s);
    MyString(const MyString& other);
    MyString();
    ~MyString();
    void print();
    char* addchar(char *str, int& reservedSize, char newChar);
    static char* strcpy(char* str, const char* s);
    char *printarr();
    bool compare(const MyString &other) const;

    void trim(char *str);
};

#endif // MY_STRING_H
