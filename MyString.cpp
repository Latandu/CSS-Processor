//
// Created by Latandu on 29/03/2023.
//

#include "MyString.h"
#include <iostream>

MyString::MyString(const char* s) {

    size = strlen(s);
    str = new char[size + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString& other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}
int MyString::strlen(const char* s){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;

}
char* MyString::strcpy(char* str, const char* s){
    char* ptr = str;
    while(*s != '\0'){
        *ptr++ = *s++;
    }
    *ptr = '\0';
    return str;
}
void MyString::print() {
    std::cout << str << std::endl;
    std::cout << size << std::endl;
}

void MyString::change(const char* s) {
    delete[] str;
    size = strlen(s);
    str = new char[size + 1];
    strcpy(str,s);
}
void MyString::parseString(const char *s) {
    size = strlen(s);
}

