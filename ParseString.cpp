//
// Created by Latandu on 01/04/2023.
//

#include <cstdio>
#include "ParseString.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include "Commands.h"
using namespace std;

ParseString::ParseString() {};
bool ParseString::checkForWhiteSpaces(char c){
    if(c == '\t' || c == '\n' || c == '\r'){
        return true;
    }
    return false;
}
int ParseString::ParseCommands(DoubleLinkedList* dll){
    while(true){
        Commands commands;
        reservedSize = 0;
        secondReservedSize = 0;
        char c;
        char* commandsArr = nullptr;
        char* lastSectionArr = nullptr;
        MyString stringCommands;
        MyString commandZ;
        MyString lastCommand;
        int lastValue = 0;
        int commandNR = 0;
        char *pEnd;
        int tol = 0;
        bool commandS = false;
        int returnValue = 0;
        while((c = (char)getchar()) != '\n') {
            if(c == '~') break;
            if(c == '*'){
                for(int i = 0; i < 3; i++){
                    c = (char)getchar();
                    if(c == '*') continue;
                    else {
                        returnValue = 1;
                    }
                }
                if(returnValue == 1) continue;
                return 2;
            }
            if(c == '?'){
                c = (char)getchar();
                if(c == '\n' && arr == nullptr) commands.commandQM(dll);
                else continue;
            }
            if(c == ','){
                c = (char)getchar();
                if(c == 'S'){
                    tol = strtol(commandsArr, &pEnd, 10);
                    if(tol == 0){
                        commandZ = commandsArr;
                        commandNR = 1;
                    }
                    commandsArr = nullptr;
                    commandS = true;
                    continue;
                }
                if(commandS && c == '?'){
                    commands.commandSelectorForSection(dll, tol);
                    continue;
                }
                if(commandS){
                    while(c != '\n'){
                        reservedSize = 0;
                        lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                        c = (char)getchar();
                    }
                    lastValue = strtol(lastSectionArr, &pEnd, 10);
                    commands.commandPrintJthSelector(dll, tol, lastValue);
                    break;
                }
            }
            commandsArr = stringCommands.addchar(commandsArr, reservedSize, c);
        }

        if(c == '~'){
            delete[] commandsArr;
            delete pEnd;
            delete[] lastSectionArr;
            return 0;
        }
    }
}
int ParseString::Parsing(DoubleLinkedList* dll) {
    while (true) {
        reservedSize = 0;
        char c;
        char *attributesArr = nullptr;
        char *selectorsArr = nullptr;
        char *attributesValueArr = nullptr;
        int selcounter = 0;
        int attCounter = 0;
        auto *select = new MyString[50];
        auto *attri = new MyString[50];
        auto *attriVal = new MyString[50];
        int returnValue = 0;
        MyString myString;
        while ((c = (char) getchar()) != '{' && c != EOF) {
            if(checkForWhiteSpaces(c) || c == ' ') continue;
            if(c == '?'){
                for(int i = 0; i < 3; i++){
                    c = (char)getchar();
                    if(c == '?') continue;
                    else {
                        returnValue = 1;
                        break;
                    }
                }
                if(returnValue == 1) continue;
                return 2;
            }

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
            while ((c = (char)getchar()) != ':' && c != EOF && c != '}' && c !='~') {
                if(checkForWhiteSpaces(c) || c == ' ') continue;
                attributesArr = attributes.addchar(attributesArr, reservedSize, c);
            }
            auto *attribute = new MyString(attributesArr);
            attri[attCounter] = *attribute;
            reservedSize = 0;
            if (c == '~' || c == '}') break;
            int i = 0;
            while ((c = (char) getchar())!= '}' && c != ';' && c != EOF) {
                if(checkForWhiteSpaces(c)) continue;
                attributesValueArr = attributesValues.addchar(attributesValueArr, reservedSize, c);
                i++;
            }
            myString.trim(attributesValueArr);
            auto *attributeValue = new MyString(attributesValueArr);
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
            return 0;
        }
    }
    return 0;
}
void ParseString::ParseWholeString(DoubleLinkedList* dll){
    int commandsSections;
    int commandInput;
    commandsSections = Parsing(dll);
    if(commandsSections == 2){
        commandInput = ParseCommands(dll);
        if(commandInput == 2) ParseWholeString(dll);

    }
}
void ParseString::PrintArr() {
    MyString string = arr;
    string.print();
}
ParseString::~ParseString() = default;
