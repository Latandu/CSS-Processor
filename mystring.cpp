//
// Created by Latandu on 29/03/2023.
//
#define _CRT_SECURE_NO_WARNINGS
#include "mystring.h"
#include <iostream>
#define BUFFER 75
MyString::MyString(const char* s) {
    if(s){
    size = strlen(s);
    str = new char[size + 1];
    strcpy(str, s);
    }
    else{
        size = 0;
        str = nullptr;
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

char* MyString::addchar(char* str, int& reservedSize, char newChar) {
    char* newStr;
    int len = 0;
    if (str != nullptr) {
        len = strlen(str);
    }
    if (len + 2 > reservedSize) {
        reservedSize += BUFFER;
        newStr = new char[reservedSize];
        if (str != nullptr) {
            for (int i = 0; i < len; i++) {
                newStr[i] = str[i];
            }
            delete[] str;
        }
        else {
            newStr[0] = '\0';
        }
    }
    else {
        newStr = str;
    }
    newStr[len] = newChar;
    newStr[len + 1] = '\0';
    return newStr;
}
bool MyString::compare(const MyString& other) const {
    if(other.str == nullptr) return false;
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (str[i] != other.str[i]) {
            return false;
        }
    }
    return true;
}
void MyString::trim(char* str1){
    int i = 0, j = 0;
    while(str1[i] == ' '){
        i++;
    }
    while(str1[i] != '\0'){
        str1[j] = str1[i];
        i++; j++;
    }
    j--;
    while(str1[j] == ' '){
        j--;
    }
    str1[j + 1] = '\0';
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

MyString::MyString() = default;


