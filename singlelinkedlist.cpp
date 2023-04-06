//
// Created by Latandu on 31/03/2023.
//

#include "singlelinkedlist.h"

SingleLinkedList::SingleLinkedList(): head(nullptr), tail() {}

void SingleLinkedList::InsertNodeAtTail(MyString* newSelector) {
    auto* newNode = new struct SingleNode();
    MyString tylda = "~";
    newNode->data = newSelector;
    newNode->next = nullptr;
    if(!head){
        newNode->next = nullptr;
        head = newNode;

        if(!newNode->data->compare(tylda)){
            newNode->selectorCounter = 1;
        }
        return;
    }
    tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    tail->next = newNode;
    if(!newNode->data->compare(tylda)){
        newNode->selectorCounter = tail->selectorCounter + 1;
    }


};
void SingleLinkedList::PrintList() {
    struct SingleNode *curr = head;
    while(curr){
        std::cout << curr->data->printarr() << std::endl;
        curr = curr->next;
    }
}


SingleLinkedList::~SingleLinkedList() {
}

