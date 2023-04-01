//
// Created by Latandu on 29/03/2023.
//

#include "MyString.h"
#include <iostream>
#define BUFFER 1000
MyString::MyString(const char* s) {
    if(s){
    size = strlen(s);
    str = new char[size + 1];
    strcpy(str, s);
    }
}

MyString::MyString(const MyString& other) {
    size = other.size;
    str = new char[size + 1];
    strcpy(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}

char *MyString::addchar(char *str, int* reservedSize, char newChar) {
    int len = strlen(str);
    char *newStr = nullptr;
    if(len > *reservedSize){
        *reservedSize += BUFFER;
        newStr = new char[*reservedSize];
        strcpy(newStr, str);
    }
    newStr[len] = newChar;
    newStr[len + 1] = '\0';
    delete str;
    return newStr;
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
}
char* MyString::printarr(){
    return str;
}


