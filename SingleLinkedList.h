//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_SINGLELINKEDLIST_H
#define PROJECT1_SINGLELINKEDLIST_H


#include "MyString.h"

class SingleLinkedList {
private:
public:
    struct SingleNode{
        MyString* data;
        SingleNode* next;
        int selectorCounter = 1;
    } SingleNode;
    int globalCoutner = 0;
    struct SingleNode* tail;
    struct SingleNode* head;
    SingleLinkedList();

    void InsertNodeAtTail(MyString* selector);

    virtual void PrintList();
    ~SingleLinkedList();

};


#endif //PROJECT1_SINGLELINKEDLIST_H
