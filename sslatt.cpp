//
// Created by Latandu on 02/04/2023.
//

#include "sslatt.h"

SSLAtt::SSLAtt(): head(nullptr), tail() {}

void SSLAtt::InsertNodeAtTail(MyString* newAttributes, MyString* newAttributesVal) {
    auto* newNode = new SingleNode();
    newNode->attributes= newAttributes;
    newNode->attValues = newAttributesVal;
    newNode->next = nullptr;
    if(!head){
        newNode->next = nullptr;
        head = newNode;
        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->attCounter = tail->attCounter + 1;

};
void SSLAtt::PrintList() {
    struct SingleNode *curr = head;
    while(curr){
        curr->attValues->printarr();
        curr->attributes->printarr();
        curr = curr->next;
    }
}


SSLAtt::~SSLAtt() {
    /*while (head){
        struct SingleNode* curr = head;
        head = head->next;
        delete curr->attValues;
        delete curr->attributes;
        delete curr;
    }*/
}