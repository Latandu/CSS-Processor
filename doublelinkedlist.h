//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_DOUBLELINKEDLIST_H
#define PROJECT1_DOUBLELINKEDLIST_H


#include "mystring.h"
#include "singlelinkedlist.h"
#include "sslatt.h"
#define T 8
class DoubleLinkedList {
private:

public:
    struct ArrayBlock{
        SSLAtt* attributes = nullptr;
        SingleLinkedList* selectors = nullptr;
        short arraySectionCounter = 0;
        bool isWritten = false;
    };
    struct Node{
        struct ArrayBlock arrayBlock[T];
        short nodeIndex = 1;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    short sectionCounter = 1;
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    DoubleLinkedList();
    void InsertNodeAtTail();
    void InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute,MyString *newAttributeVal,
                                          int attlistCounter, int selListCounter);
    ~DoubleLinkedList();
    MyString PrintNumberOfSections();

    MyString PrintNumberOfSelectors(int sectionNo);

    MyString PrintJthSelector(int sectionNo, int selectorNo);

    MyString NumberOfAttributes(int sectionNo);

    MyString* AttributeValueByName(const MyString& attributeName, int sectionNo);

    MyString NumberOfAttributesSelectedByName(MyString attributeName);

    MyString SearchForSelectorsByName(const MyString& selectorName);

    MyString* LastAttributeValueForSelector(const MyString &attributeName, const MyString &selector);

    MyString RemoveWholeSection(int sectionNo);

    MyString RemoveAttributeFromSectionByName(int sectionNo, MyString attributeName);

};


#endif //PROJECT1_DOUBLELINKEDLIST_H
