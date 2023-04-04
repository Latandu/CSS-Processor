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
    int concatenate(MyString *str1, MyString* str2);
    bool compare(const MyString &other) const;

    void trim(char *str);
};

#endif // MY_STRING_H
