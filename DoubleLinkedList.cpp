//
// Created by Latandu on 31/03/2023.
//

#include "MyString.h"
#include "DoubleLinkedList.h"
#include "ParseString.h"
#include <iostream>
#define T 8
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(){}
/*void DoubleLinkedList::InsertNodeAtFront(MyString* newValue) {
    auto* newNode = new Node();
    newNode->data = newValue;
    newNode->next = head;
    head = newNode;
}*/
void DoubleLinkedList::InsertNodeAtTail() {
    auto* newArrayBlock = new ArrayBlock[T];
    auto* newNode = new Node();
    short counter = 2;
    newNode->next = nullptr;
    for (int i = 0; i< T; i++){
        newNode->arrayBlock[i] = newArrayBlock[i];
    }
    if(!head){
        newNode->nodeIndex = 1;
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    tail = head;
    while(tail->next!=nullptr){
        tail = tail->next;
        counter++;
    }
    tail->next = newNode;
    newNode->prev = tail;
    newNode->nodeIndex = counter;
}
void DoubleLinkedList::InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute, struct Node* position) {
    if(!position) position = head;
    struct Node *selectorNode = position;
    ParseString parse;
    while(selectorNode){
        for(int i = 0; i < T; i++){
            if(!selectorNode->arrayBlock[i].isWritten){
                selectorNode->arrayBlock[i].selectors = new SingleLinkedList();
                selectorNode->arrayBlock[i].attributes = new SingleLinkedList();
                selectorNode->arrayBlock[i].selectors->InsertNodeAtTail(newSelector);
                selectorNode->arrayBlock[i].attributes->InsertNodeAtTail(newAttribute);
                selectorNode->arrayBlock[i].isWritten = true;
                return;
            }
        }
        selectorNode = selectorNode->next;
    }
    tail = selectorNode;
    InsertNodeAtTail();
    InsertSelectorAttributesIntoNode(newSelector, newAttribute, tail);

}
void DoubleLinkedList::RemoveNode(short index) {
    struct Node *nodeDeletion = head;
    int counter = 1;
    while(nodeDeletion) {
        if(counter == index){
            break;
        }
        counter++;
        nodeDeletion = nodeDeletion->next;
    }
    if(head == nodeDeletion) head = nodeDeletion->next;
    if(nodeDeletion->next != nullptr) nodeDeletion->next->prev = nodeDeletion->prev;
    if(nodeDeletion->prev != nullptr) nodeDeletion->prev->next = nodeDeletion->next;


}
void DoubleLinkedList::PrintList() {
    struct Node *curr = head;
    while(curr){
        curr->arrayBlock[0].selectors->PrintList();
        curr->arrayBlock[0].attributes->PrintList();
        curr = curr->next;
    }
}
DoubleLinkedList::~DoubleLinkedList(){
    while (head){
        struct Node* curr = head;
        head = head->next;
        delete curr;
    }
}