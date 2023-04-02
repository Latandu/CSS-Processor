//
// Created by Latandu on 01/04/2023.
//

#include <cstdio>
#include "ParseString.h"
#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

ParseString::ParseString() {};
bool ParseString::checkForWhiteSpaces(char c){
    if(c == ' ' || c == '\t' || c == '\n' || c == '\r'){
        return true;
    }
    return false;
}
void ParseString::Parsing(DoubleLinkedList* dll) {
    while (true) {
        char c;
        char *attributesArr = nullptr;
        char *selectorsArr = nullptr;
        char *attributesValueArr = nullptr;
        int selcounter = 0;
        int attCounter = 0;
        MyString *select = new MyString[50];
        MyString *attri = new MyString[50];
        MyString *attriVal = new MyString[50];
        while ((c = (char) getchar()) != '{' && c != EOF) {
            if(checkForWhiteSpaces(c) || c == ' ') continue;
            if (c == '~') break;
            if (c == ',') {
                MyString selector(selectorsArr);
                select[selcounter] = selector;
                selcounter++;
                selectorsArr = nullptr;
                reservedSize = 0;
                continue;
            }
            selectorsArr = selectors.addchar(selectorsArr, reservedSize, c);
        }

        MyString selector(selectorsArr);
        select[selcounter] = selector;
        selcounter++;
        selectorsArr = nullptr;
        reservedSize = 0;
        if (c == '~') break;
        while (true) {
            while ((c = (char)getchar()) != ':' && c != EOF) {
                if(checkForWhiteSpaces(c) || c == ' ') continue;
                if (c == '}' || c == '~') break;
                attributesArr = attributes.addchar(attributesArr, reservedSize, c);
            }
            MyString *attribute = new MyString(attributesArr);
            attri[attCounter] = *attribute;
            reservedSize = 0;
            if (c == '~' || c == '}') break;
            while ((c = (char) getchar())!= '}' && c != ';' && c != EOF) {

                if(checkForWhiteSpaces(c) || c == ' ') continue;
                if (c == '}' || c == '~') break;
                attributesValueArr = attributesValues.addchar(attributesValueArr, reservedSize, c);
            }
            MyString *attributeValue = new MyString(attributesValueArr);
            attriVal[attCounter] = *attributeValue;
            attCounter++;
            attributesArr = nullptr;
            attributesValueArr = nullptr;
            reservedSize = 0;
            if (c == '~') break;
            if (c == '}') break;
        }

        dll->InsertSelectorAttributesIntoNode(select, attri, attriVal, nullptr, attCounter, selcounter);
        reservedSize = 0;
        if (c == '~'){
            delete[] selectorsArr;
            delete[] attributesValueArr;
            delete[] attributesArr;
            delete[] select;
            delete[] attri;
            delete[] attriVal;
            break;
        }
    }
}
void ParseString::PrintArr() {
    MyString string = arr;
    string.print();
}
ParseString::~ParseString() {
}
