//
// Created by Latandu on 01/04/2023.
//

#ifndef PROJECT1_PARSESTRING_H
#define PROJECT1_PARSESTRING_H


#include "MyString.h"
#include "DoubleLinkedList.h"
class ParseString {
private:
    int buff = 1000;
    char* arr;
    int iteration = 0;
    int reservedSize = 0;
    int secondReservedSize = 0;
    int thirdReservedSize = 0;
public:
    MyString selectors;
    MyString attributes;
    MyString attributesValues;
    ParseString();
    int Parsing(DoubleLinkedList* dll);
    void PrintArr();
    ~ParseString();

    static bool checkForWhiteSpaces(char c);

    int ParseCommands(DoubleLinkedList *dll);

    void ParseWholeString(DoubleLinkedList *dll);
};


#endif //PROJECT1_PARSESTRING_H
