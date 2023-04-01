//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_DOUBLELINKEDLIST_H
#define PROJECT1_DOUBLELINKEDLIST_H


#include "MyString.h"
#include "SingleLinkedList.h"
#define T 8
class DoubleLinkedList : public SingleLinkedList{
private:
    struct ArrayBlock{
        SingleLinkedList* attributes = nullptr;
        SingleLinkedList* selectors = nullptr;
        short counterAtt = 0, counterSel = 0;
        bool isWritten = false;
    };
    struct Node{
        struct ArrayBlock arrayBlock[T];
        MyString* data = nullptr;
        short nodeIndex = 0;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
public:
    DoubleLinkedList();
    void RemoveNode(short index );
    void InsertNodeAtTail();
    void InsertSelectorAttributesIntoNode(MyString* newValue, MyString *newAttribute, struct Node* position);
    void PrintList() override;
    ~DoubleLinkedList();

};


#endif //PROJECT1_DOUBLELINKEDLIST_H
