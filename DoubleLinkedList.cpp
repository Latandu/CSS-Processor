//
// Created by Latandu on 31/03/2023.
//

#include "MyString.h"
#include "DoubleLinkedList.h"
#include <iostream>
#define T 8
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(nullptr){};

void DoubleLinkedList::InsertNodeAtFront(MyString* newValue) {
    auto* newNode = new Node[T];
    newNode->data = newValue;
    newNode->next = head;
    head = newNode;
}
void DoubleLinkedList::InsertNodeAtTail(MyString* newValue){
    auto* newNode = new Node[T];
    newNode->data = newValue;
    newNode->next = nullptr;
    if(!head){
        newNode->prev = nullptr;
        head = newNode;
        return;
    }
    struct Node* last = head;
    while(last->next!=nullptr){
        last = last->next;
    }
    last->next = newNode;
    newNode->prev = last;
}
void DoubleLinkedList::PrintList() {
    struct Node *curr = head;
    while(curr){
        std::cout << curr->data->printarr() << std::endl;
        curr = curr->next;
    }
}
DoubleLinkedList::~DoubleLinkedList(){
    while (head){
        struct Node* curr = head;
        head = head->next;
        curr->data;
        delete curr;
    }
}