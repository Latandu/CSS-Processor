//
// Created by Latandu on 01/04/2023.
//

#include <cstdio>
#include "ParseString.h"
#include <iostream>

ParseString::ParseString() {};

void ParseString::Parsing() {
char c;
char* attributesArr = nullptr;
char* selectorsArr = nullptr;
char* attributesValueArr = nullptr;
    while((c = getchar()) != '{'  && c != EOF){
        selectorsArr = selectors.addchar(selectorsArr, reservedSize, c);
    }
    while(c != '}'){
        while ((c = getchar()) != ':' && c != EOF) {
            attributesArr = attributes.addchar(attributesArr, reservedSize, c);
        }
        while ((c = getchar()) != ';' && c != EOF ) {
            attributesValueArr = attributesValues.addchar(attributesValueArr, reservedSize, c);
        }
    }
}
void ParseString::PrintArr() {
    MyString string = arr;
    string.print();
}
ParseString::~ParseString() {
    delete[] arr;
}
