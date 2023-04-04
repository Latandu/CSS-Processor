//
// Created by Latandu on 31/03/2023.
//

#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList(): head(nullptr), tail() {}

void SingleLinkedList::InsertNodeAtTail(MyString* newSelector) {
    auto* newNode = new struct SingleNode();
    newNode->data = newSelector;
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
    newNode->selectorCounter = tail->selectorCounter + 1;


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

