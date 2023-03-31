//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_DOUBLELINKEDLIST_H
#define PROJECT1_DOUBLELINKEDLIST_H


#include "MyString.h"

class DoubleLinkedList {
private:
    struct Node{
        MyString* data = nullptr;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
public:
    DoubleLinkedList();
    void InsertNodeAtFront(MyString* newValue);
    void InsertNodeAtTail(MyString *newValue);
    void PrintList();
    ~DoubleLinkedList();

};


#endif //PROJECT1_DOUBLELINKEDLIST_H
