//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_DOUBLELINKEDLIST_H
#define PROJECT1_DOUBLELINKEDLIST_H


#include "MyString.h"
#include "SingleLinkedList.h"
#include "SSLAtt.h"
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
    void RemoveNode(short index);
    void InsertNodeAtTail();
    void InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute,MyString *newAttributeVal,
                                          struct Node* position, int attlistCounter, int selListCounter);
    void PrintList();
    ~DoubleLinkedList();
    void PrintNumberOfSections();

    void PrintNumberOfSelectors(int sectionNo);

    void PrintJthSelector(int sectionNo, int selectorNo);
};


#endif //PROJECT1_DOUBLELINKEDLIST_H
