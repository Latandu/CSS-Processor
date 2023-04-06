//
// Created by Latandu on 01/04/2023.
//

#include <cstdio>
#include "parsestring.h"
#include "doublelinkedlist.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

ParseString::ParseString() {};
bool ParseString::checkForWhiteSpaces(char c){
    if(c == '\t' || c == '\n' || c == '\r'){
        return true;
    }
    return false;
}
int ParseString::Search(MyString* arr, MyString* data, int counter, MyString* attValue, MyString* valData){
    while(counter >= 0){
        if(arr[counter].compare(*data)){
            arr[counter] = *data;
            attValue[counter] = *valData;
            return 1;
        }
        counter--;
    }
    return 0;
}
int ParseString::SearchSelector(MyString* arr, MyString* data, int counter){
    while(counter >= 0){
        if(arr[counter].compare(*data)){
            arr[counter] = *data;
            return 1;
        }
        counter--;
    }
    return 0;
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
        MyString stringCommands = " ";
        MyString* commandZ = nullptr;
        MyString* commandX = nullptr;
        MyString* commandY = nullptr;
        MyString* lastCommand = nullptr;
        char equals2[] ={" == "};
        MyString equals = "==";
        int lastValue;
        int returnCode = 0;
        int commandNR = 0;
        char *pEnd;
        int tolS = 0;
        int numberOfComma = 0;
        int tolA = 0;
        int tolE = 0;
        int tolD = 0;
        int errorCode = 0;
        bool commandS = false;
        bool commandA = false;
        bool commandE = false;
        bool commandD = false;
        int returnValue = 0;
        while ((c = (char) getchar()) != '\n' ) {
            if ((int)c == (int)'|') break;
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
                if ((c = (char)getchar()) == '\n' || (int)c == (int)'|') {
                   if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                    MyString fullValue = dll->PrintNumberOfSections();
                    if(fullValue.compare({"-1"})) break;
                    if(fullCommandArr != nullptr) strcat(fullCommandArr, fullValue.printarr());
                    MyString fullCommand = fullCommandArr;
                    fullCommand.print();
                    break;
                } else continue;
            }
            if (c == ',') {
                numberOfComma++;
                c = (char) getchar();
                fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                if (c == 'S') {
                    if(commandsArr == nullptr) continue;
                    tolS = strtol(commandsArr, &pEnd, 10);
                    if (tolS == 0) {
                        commandX = new MyString(commandsArr);
                        commandNR = 2;
                    } else commandNR = 1;
                    commandsArr = nullptr;
                    commandS = true;
                    secondReservedSize = 0;
                    continue;
                }
                if (c == 'A') {
                    if(commandsArr == nullptr) continue;
                    tolA = strtol(commandsArr, &pEnd, 10);
                    if (tolA == 0) {
                         commandY = new MyString(commandsArr);
                        commandNR = 4;
                    } else commandNR = 3;
                    commandsArr = nullptr;
                    commandA = true;
                    secondReservedSize = 0;
                    continue;
                }
                if (c == 'E') {
                    commandZ = new MyString(commandsArr);
                    commandE = true;
                    secondReservedSize = 0;
                    continue;
                }
                if(c == 'D'){
                    if(commandsArr == nullptr) continue;
                    tolD = strtol(commandsArr, &pEnd, 10);
                    if(tolD == 0){
                        break;
                    }
                    commandsArr = nullptr;
                    commandD = true;
                    secondReservedSize = 0;
                    continue;
                }
                if(c != '?' && numberOfComma != 2) {
                    while(c != '\n'){
                        c = (char)getchar();
                    }
                    break;
                }

                if (commandS) {
                    if (c == '?') {
                        if (commandNR == 2) {
                            if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                            MyString fullValue = dll->SearchForSelectorsByName(*commandX);
                            if(fullValue.compare({"-1"})) break;
                            if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                            MyString fullCommand = fullCommandArr;
                            fullCommand.print();
                            break;
                        }
                        if (commandNR == 1) {
                            if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                            MyString fullValue = dll->PrintNumberOfSelectors(tolS);
                            if(fullValue.compare({"-1"})) break;
                            if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                            MyString fullCommand = fullCommandArr;
                            fullCommand.print();
                            break;
                        }
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
                        lastValue = (int)strtol(lastSectionArr, &pEnd, 10);
                        if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                        MyString fullValue = dll->PrintJthSelector(tolS, lastValue);
                        if(fullValue.compare({"-1"})) break;
                        if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                        MyString fullCommand = fullCommandArr;
                        fullCommand.print();
                        break;
                    }
                }
                if (commandA) {
                    if (c == '?') {
                        if (commandNR == 3) {
                            if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                            MyString fullValue = dll->NumberOfAttributes(tolA);
                            if(fullValue.compare({"-1"})) break;
                            if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                            MyString fullCommand = fullCommandArr;
                            fullCommand.print();
                            break;
                        }
                        if (commandNR == 4) {
                            if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                            MyString fullValue = dll->NumberOfAttributesSelectedByName(*commandY);
                            if(fullValue.compare({"-1"})) break;
                            if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                            MyString fullCommand = fullCommandArr;
                            fullCommand.print();

                            break;
                        }
                        break;
                    }
                    if (commandNR == 3) {
                        while (c != '\n' && c != ',') {
                            lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                            c = (char) getchar();
                            if (c != '\n')
                                fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                        }
                        MyString attributeName = lastSectionArr;
                        if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                        MyString fullValue = dll->AttributeValueByName(attributeName, tolA);
                        if(fullValue.compare({"-1"})) break;
                        if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                        MyString fullCommand = fullCommandArr;
                        fullCommand.print();
                        break;
                    }
                }
                if (commandE) {
                    while (c != '\n' && c != ',') {
                        lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                        c = (char) getchar();
                        if (c != '\n') {
                            fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                        }
                    }
                    MyString attributeName = lastSectionArr;
                    if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                    MyString fullValue = dll->LastAttributeValueForSelector(attributeName, *commandZ);
                    if(fullValue.compare({"-1"})) break;
                    if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                    MyString fullCommand = fullCommandArr;
                    fullCommand.print();
                    break;
                }
                if(commandD){
                    if(c == '*'){
                        if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                        MyString fullValue = dll->RemoveWholeSection(tolD);
                        if(fullValue.compare({"-1"})) break;
                        if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                        MyString fullCommand = fullCommandArr;
                        fullCommand.print();
                        break;
                    }
                    while (c != '\n' && c != ',') {
                        lastSectionArr = stringCommands.addchar(lastSectionArr, reservedSize, c);
                        c = (char) getchar();
                        if (c != '\n')
                            fullCommandArr = stringCommands.addchar(fullCommandArr, thirdReservedSize, c);
                    }
                    MyString attributeName = lastSectionArr;
                    if(fullCommandArr != nullptr) strcat(fullCommandArr, equals2);
                    MyString fullValue = dll->RemoveAttributeFromSectionByName(tolD,lastSectionArr);
                    if(fullValue.compare({"-1"})) break;
                    if(fullCommandArr != nullptr)  strcat(fullCommandArr, fullValue.printarr());
                    MyString fullCommand = fullCommandArr;
                    fullCommand.print();
                }
                }
                commandsArr = stringCommands.addchar(commandsArr, secondReservedSize, c);
            }
        
            secondReservedSize = 0;
            reservedSize = 0;
            thirdReservedSize = 0;
            if ((int) c == (int)'|') {
                return 0;
            }
        }
}
int ParseString::Parsing(DoubleLinkedList* dll) {
    int iterationLoop = 0;
    while (true) {
        int nException = 1;
        reservedSize = 0;
        char c;
        char *attributesArr = nullptr;
        char *selectorsArr = nullptr;
        char *attributesValueArr = nullptr;
        int selcounter = 0;
        int searchReturnCode = 0;
        int attCounter = 0;
        auto *select = new MyString[40];
        auto *attri = new MyString[40];
        auto *attriVal = new MyString[40];
        MyString* attributeValue = nullptr;
        MyString* attribute = nullptr;
        int returnValue = 0;
        MyString myString;
        while ((c = (char) getchar()) != '{') {
            if(c == '\t' || c == '\r') continue;
            if( c =='\n' && nException == 1) continue;
            if( c =='\n' && nException == 0) continue;
            nException =0;
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

            if ((int)c == (int)'|') break;
            if (c == ',') {
                MyString selector(selectorsArr);
                if(selcounter != 0) searchReturnCode = SearchSelector(select, &selector, selcounter);
                if(searchReturnCode == 0){
                    select[selcounter] = selector;
                    selcounter++;
                }
                selectorsArr = nullptr;
                reservedSize = 0;
                continue;
            }
            selectorsArr = selectors.addchar(selectorsArr, reservedSize, c);
        }
        if(nException == 1){
            selectorsArr = selectors.addchar(selectorsArr, reservedSize, '~');
            MyString selector(selectorsArr);
            if(selcounter != 0) searchReturnCode = SearchSelector(select, &selector, selcounter);
            if(searchReturnCode == 0){
                select[selcounter] = selector;
                selcounter++;
            }
        }
        else{
            if(selectorsArr != nullptr) myString.trim(selectorsArr);
            MyString* selector = new MyString(selectorsArr);
            if(selcounter != 0) searchReturnCode = SearchSelector(select, selector, selcounter);
            if(searchReturnCode == 0){
                select[selcounter] = *selector;
                selcounter++;
            }
        }
        selectorsArr = nullptr;
        if ((int)c == (int)'|') break;
        while (true) {
            attributesValueArr = nullptr;
            attributesArr = nullptr;
            reservedSize = 0;
            while ((c = (char)getchar()) != ':' && c != '}'){
                if ((int)c == (int)'|') break;
                if(checkForWhiteSpaces(c)) continue;
                attributesArr = attributes.addchar(attributesArr, reservedSize, c);
            }
            reservedSize = 0;
            if ((int)c == (int)'|' || c == '}') break;
            int i = 0;
            while ((c = (char) getchar())!= '}' && c != ';') {
                if ((int)c == (int)'|') break;
                if(checkForWhiteSpaces(c)) continue;
                attributesValueArr = attributesValues.addchar(attributesValueArr, reservedSize, c);
                i++;
            }
            searchReturnCode = 0;
            if(attributesValueArr != nullptr) myString.trim(attributesValueArr);
            if(attributesArr != nullptr) myString.trim(attributesArr);
            attributeValue = new MyString(attributesValueArr);
            attribute = new MyString(attributesArr);
            if(attCounter != 0) searchReturnCode = Search(attri, attribute, attCounter, attriVal, attributeValue);
            if(searchReturnCode == 0) {
                attriVal[attCounter] = *attributeValue;
                attri[attCounter] = *attribute;
                attCounter++;
            }
            if ((int)c == (int)'|') break;
            if (c == '}') break;
        }
        dll->InsertSelectorAttributesIntoNode(select, attri, attriVal, attCounter, selcounter);
        reservedSize = 0;
        if ((int)c == (int)'|'){
            delete attributeValue;
            delete attribute;
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
