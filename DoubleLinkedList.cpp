//
// Created by Latandu on 31/03/2023.
//

#include "MyString.h"
#include "DoubleLinkedList.h"
#include "ParseString.h"
#include <iostream>
#define T 8
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(){
}
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
void DoubleLinkedList::InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute,MyString *newAttributeVal,
                                                        struct Node* position, int attlistCounter, int selListCounter) {
    if(!position) position = head;
    struct Node *selectorNode = position;
    while(selectorNode){
        for(int i = 0; i < T; i++){
            if(!selectorNode->arrayBlock[i].isWritten){
                int j = 0;
                selectorNode->arrayBlock[i].selectors = new SingleLinkedList();
                selectorNode->arrayBlock[i].attributes = new SSLAtt();
                while(j < selListCounter){
                    selectorNode->arrayBlock[i].selectors->InsertNodeAtTail(&newSelector[j]);
                    j++;
                }
                j = 0;
                while(j < attlistCounter){
                    selectorNode->arrayBlock[i].attributes->InsertNodeAtTail(&newAttribute[j], &newAttributeVal[j]);
                    j++;
                }
                selectorNode->arrayBlock[i].arraySectionCounter = sectionCounter;
                sectionCounter++;
                selectorNode->arrayBlock[i].isWritten = true;
                return;
            }
        }
        selectorNode = selectorNode->next;
    }
    tail = selectorNode;
    InsertNodeAtTail();

    InsertSelectorAttributesIntoNode(newSelector, newAttribute, newAttributeVal, tail, attlistCounter, selListCounter);
    delete selectorNode;
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
void DoubleLinkedList::PrintNumberOfSelectors(int sectionNo) {
    struct Node *curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                std::cout << curr->arrayBlock[i].selectors->head->selectorCounter << std::endl;
                return;
        }
     //   curr->arrayBlock[0].selectors->PrintList();
     //   curr->arrayBlock[0].attributes->PrintList();
     }
        curr = curr->next;
    }
}
void DoubleLinkedList::PrintJthSelector(int sectionNo, int selectorNo){
    struct Node *curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
                while(curr2){
                    if(curr2->selectorCounter == selectorNo){
                        curr2->data->print();
                        return;
                    }
                    curr2 = curr2->next;
                }
                return;
            }
        }
        curr = curr->next;
    }
}
void DoubleLinkedList::PrintNumberOfSections(){
    std::cout << sectionCounter - 1 << std::endl;
}
DoubleLinkedList::~DoubleLinkedList(){
    while (head){
        struct Node* curr = head;
        for(int i = 0; i < T; i++){
           delete curr->arrayBlock[i].selectors->head;
        }
        head = head->next;
        // delete[] curr->arrayBlock;
        delete curr;

    }
}