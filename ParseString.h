//
// Created by Latandu on 01/04/2023.
//

#ifndef PROJECT1_PARSESTRING_H
#define PROJECT1_PARSESTRING_H


#include "MyString.h"

class ParseString {
private:
    int buff = 1000;
    char* arr;
    int iteration = 0;
    int* reservedSize;
public:
    MyString selectors = " ";
    MyString attributes = " ";
    MyString attributesValues = " ";
    ParseString();
    void Parsing();
    void PrintArr();
    ~ParseString();

};


#endif //PROJECT1_PARSESTRING_H
