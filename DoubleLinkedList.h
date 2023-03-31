//
// Created by Latandu on 31/03/2023.
//

#ifndef PROJECT1_DOUBLELINKEDLIST_H
#define PROJECT1_DOUBLELINKEDLIST_H


#include "MyString.h"

class DoubleLinkedList : public MyString {
private:
    struct Node{
        MyString data;
        Node* next;
        Node* prev;
    };
    struct Node *head = NULL;
    struct Node *tail = NULL;
public:
    DoubleLinkedList();
    void InsertNodeAtTail(int data);
    ~DoubleLinkedList();

};


#endif //PROJECT1_DOUBLELINKEDLIST_H
