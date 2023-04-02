//
// Created by Latandu on 02/04/2023.
//

#ifndef PROJECT1_SSLATT_H
#define PROJECT1_SSLATT_H

#include "MyString.h"
class SSLAtt {
private:
private:
    struct SingleNode{
        MyString* attributes;
        MyString* attValues;
        SingleNode* next;
        short attCounter = 0;
    };
    struct SingleNode* tail;
    struct SingleNode* head;
public:
    SSLAtt();

    void InsertNodeAtTail(MyString* newAttributes, MyString* newAttributesVal);

    virtual void PrintList();
    ~SSLAtt();
};


#endif //PROJECT1_SSLATT_H
