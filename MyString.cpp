//
// Created by Latandu on 29/03/2023.
//
#define _CRT_SECURE_NO_WARNINGS
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
}

char *MyString::addchar(char *str, int& reservedSize, char newChar) {
    char* newStr = nullptr;
    int len = strlen(str);
    if (len + 2 > reservedSize) {
        reservedSize += BUFFER;
        newStr = new char[reservedSize];
        if (str != nullptr) {
            strcpy(newStr, str);
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
int MyString::strlen(const char* s){
    if(s == nullptr) return 0;
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;

}
int MyString::concatenate(MyString *str1, MyString* str2){
    if(str2->compare("-1")) return 1;
    strcat(str1->printarr(), str2->printarr());
    return 0;
}
bool MyString::compare(const MyString& other) const {
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
void MyString::trim(char* str){
    int i = 0, j = 0;
    while(str[i] == ' '){
        i++;
    }
    while(str[i] != '\0'){
        str[j] = str[i];
        i++; j++;
    }
    j--;
    while(str[j] == ' '){
        j--;
    }
    str[j + 1] = '\0';
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

MyString::MyString() {

}


