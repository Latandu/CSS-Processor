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
        short counterAtt = 0, counterSel = 0;
        bool isWritten = false;
    };
    struct Node{
        struct ArrayBlock arrayBlock[T];
        short nodeIndex = 0;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    DoubleLinkedList();
    void RemoveNode(short index);
    void InsertNodeAtTail();
    void InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute,MyString *newAttributeVal,
                                          struct Node* position, int attlistCounter, int selListCounter);
    void PrintList();
    ~DoubleLinkedList();
    void InsertSelectorIntoNode(MyString *newSelector, Node *position);
};


#endif //PROJECT1_DOUBLELINKEDLIST_H
