//
// Created by Latandu on 01/04/2023.
//

#ifndef PROJECT1_PARSESTRING_H
#define PROJECT1_PARSESTRING_H


#include "mystring.h"
#include "doublelinkedlist.h"
class ParseString {
private:
    int reservedSize = 0;
    int secondReservedSize = 0;
    int thirdReservedSize = 0;
public:
    MyString selectors;
    MyString attributes;
    MyString attributesValues;
    ParseString();
    int Parsing(DoubleLinkedList* dll);
    ~ParseString();

    static bool checkForWhiteSpaces(char c);

    int ParseCommands(DoubleLinkedList *dll);

    void ParseWholeString(DoubleLinkedList *dll);

    int Search(MyString* arr, MyString* data, int counter, MyString* attValue, MyString* valData);

    int SearchSelector(MyString *arr, MyString *data, int counter);
};


#endif //PROJECT1_PARSESTRING_H
