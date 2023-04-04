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
    if(c == '\t' || c == '\n' || c == '\r'){
        return true;
    }
    return false;
}
int ParseString::ParseCommands(DoubleLinkedList* dll){
    while(true) {
        reservedSize = 0;
        secondReservedSize = 0;
        thirdReservedSize = 0;
        char c = ' ';
        char *commandsArr = nullptr;
        char *lastSectionArr = nullptr;
        char *fullCommandArr = nullptr;
        MyString stringCommands;
        MyString commandZ;
        MyString lastCommand;
        MyString equals = " == ";
        int lastValue;
        int returnCode;
        int commandNR = 0;
        char *pEnd;
        int tolS = 0;
        int tolA = 0;
        int tolE = 0;
        bool commandS = false;
        bool commandA = false;
        bool commandE = false;
        int returnValue = 0;
        while ((c = (char) getchar()) != '\n') {
            if ((int) (int) c == EOF) break;
            if (c == '*') {
                for (int i = 0; i < 3; i++) {
                    c = (char) getchar();
                    if (c == '*') continue;
                    else {
                        returnValue = 1;
                    }
                }
                if (returnValue == 1) continue;
                return 2;
            }
            fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
            if (c == '?') {
                c = (char) getchar();
                if (c == '\n') {
                    MyString fullCommand = fullCommandArr;
                    stringCommands.concatenate(&fullCommand, &equals);
                    MyString fullValue = dll->PrintNumberOfSections();
                    returnCode = stringCommands.concatenate(&fullCommand, &fullValue);
                    if (returnCode == 0) fullCommand.print();
                    break;
                } else continue;
            }
            if (c == ',') {
                c = (char) getchar();
                fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                if (c == 'S') {
                    tolS = strtol(commandsArr, &pEnd, 10);
                    if (tolS == 0) {
                        commandZ = commandsArr;
                        commandNR = 2;
                    } else commandNR = 1;
                    commandsArr = nullptr;
                    commandS = true;
                    secondReservedSize = 0;
                    continue;
                }
                if (c == 'A') {
                    tolA = strtol(commandsArr, &pEnd, 10);
                    if (tolA == 0) {
                        commandZ = commandsArr;
                        commandNR = 4;
                    } else commandNR = 3;
                    commandsArr = nullptr;
                    commandA = true;
                    secondReservedSize = 0;
                    continue;
                }
                if (c == 'E') {
                    commandZ = commandsArr;
                    commandE = true;
                    secondReservedSize = 0;
                    continue;
                }

                if (commandS) {
                    if (c == '?') {
                        if (commandNR == 2) {
                            MyString fullCommand = fullCommandArr;
                            stringCommands.concatenate(&fullCommand, &equals);
                            MyString fullValue = dll->SearchForSelectorsByName(commandZ);
                            returnCode = stringCommands.concatenate(&fullCommand, &fullValue);
                            if (returnCode == 0) fullCommand.print();
                            break;
                        }
                        if (commandNR == 1) {
                            MyString fullCommand = fullCommandArr;
                            stringCommands.concatenate(&fullCommand, &equals);
                            MyString fullValue = dll->PrintNumberOfSelectors(tolS);
                            returnCode = stringCommands.concatenate(&fullCommand, &fullValue);
                            if (returnCode == 0) fullCommand.print();
                            break;
                        }
                        reservedSize = 0;
                        break;
                    }
                    if (commandNR == 1) {
                        while (c != '\n') {
                            lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                            c = (char) getchar();
                            if (c != '\n') {
                                fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                            }
                        }
                        reservedSize = 0;
                        lastValue = strtol(lastSectionArr, &pEnd, 10);
                        MyString fullCommand = fullCommandArr;
                        stringCommands.concatenate(&fullCommand, &equals);
                        MyString *fullValue = dll->PrintJthSelector(tolS, lastValue);
                        if (fullValue == nullptr) break;
                        returnCode = stringCommands.concatenate(&fullCommand, fullValue);
                        if (returnCode == 0) fullCommand.print();
                        break;
                    }
                }
                if (commandA) {
                    if (c == '?') {
                        if (commandNR == 3) {
                            MyString fullCommand = fullCommandArr;
                            stringCommands.concatenate(&fullCommand, &equals);
                            MyString fullValue = dll->NumberOfAttributes(tolA);
                            returnCode = stringCommands.concatenate(&fullCommand, &fullValue);
                            if (returnCode == 0) fullCommand.print();
                            break;
                        }
                        if (commandNR == 4) {
                            //TODO IMPLEMENT DUPLICATES SEARCH
                            MyString fullCommand = fullCommandArr;
                            stringCommands.concatenate(&fullCommand, &equals);
                            MyString fullValue = dll->NumberOfAttributesSelectedByName(commandZ);
                            returnCode = stringCommands.concatenate(&fullCommand, &fullValue);
                            if (returnCode == 0) fullCommand.print();
                            break;
                        }
                        reservedSize = 0;
                        break;
                    }
                    if (commandNR == 3) {
                        while (c != '\n') {
                            lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                            c = (char) getchar();
                            if (c != '\n')
                                fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                        }
                        MyString attributeName = lastSectionArr;
                        MyString fullCommand = fullCommandArr;
                        stringCommands.concatenate(&fullCommand, &equals);
                        MyString *fullValue = dll->AttributeValueByName(attributeName, tolA);
                        if (fullValue == nullptr) break;
                        returnCode = stringCommands.concatenate(&fullCommand, fullValue);
                        if (returnCode == 0) fullCommand.print();
                        break;
                    }
                }
                if (commandE) {
                    while (c != '\n') {
                        lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                        c = (char) getchar();
                        if (c != '\n') {
                            fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                        }
                    }
                    reservedSize = 0;
                    MyString attributeName = lastSectionArr;
                    MyString fullCommand = fullCommandArr;
                    stringCommands.concatenate(&fullCommand, &equals);
                    MyString *fullValue = dll->LastAttributeValueForSelector(attributeName, commandZ);
                     if (fullValue == nullptr) break;
                    returnCode = stringCommands.concatenate(&fullCommand, fullValue);
                    if (returnCode == 0) fullCommand.print();
                    break;
                }
                }
                commandsArr = stringCommands.addchar(commandsArr, secondReservedSize, c);
            }
            secondReservedSize = 0;
            reservedSize = 0;
            if ((int) c == EOF) {
                delete[] commandsArr;
                delete[] lastSectionArr;
                delete[] fullCommandArr;
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
        while ((c = (char) getchar()) != '{') {
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

            if ((int)c == EOF) break;
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
        if ((int)c == EOF) break;
        while (true) {
            while ((c = (char)getchar()) != ':' && c != '}'){
                if ((int)c == EOF) break;
                if(checkForWhiteSpaces(c) || c == ' ') continue;
                attributesArr = attributes.addchar(attributesArr, reservedSize, c);
            }
            auto *attribute = new MyString(attributesArr);
            attri[attCounter] = *attribute;
            reservedSize = 0;
            if ((int)c == EOF || c == '}') break;
            int i = 0;
            while ((c = (char) getchar())!= '}' && c != ';') {
                if ((int)c == EOF) break;
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
            if ((int)c == EOF) break;
            if (c == '}') break;
        }


        dll->InsertSelectorAttributesIntoNode(select, attri, attriVal, attCounter, selcounter);
        reservedSize = 0;
        if ((int)c == EOF){
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
ParseString::~ParseString() {
};
