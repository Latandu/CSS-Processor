//
// Created by Latandu on 31/03/2023.
//

#include "MyString.h"
#include "DoubleLinkedList.h"
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
        delete[] newArrayBlock;
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
    delete[] newArrayBlock;
}
void DoubleLinkedList::InsertSelectorAttributesIntoNode(MyString *newSelector, MyString *newAttribute,MyString *newAttributeVal, int attlistCounter, int selListCounter) {
    struct Node *selectorNode;
    if(!tail) selectorNode = head;
    else selectorNode = tail;
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
    InsertSelectorAttributesIntoNode(newSelector, newAttribute, newAttributeVal, attlistCounter, selListCounter);
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
MyString DoubleLinkedList::PrintNumberOfSelectors(int sectionNo) {
    int i = 0;
    struct Node *curr = head;
    MyString numbersExit = "-1";
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
                while(curr2){
                    if(curr2->next == nullptr) break;
                    curr2 = curr2->next;
                }
                char s[11];
                sprintf_s(s, "%d", curr2->selectorCounter);
                MyString number = s;
                return number;
        }
     //   curr->arrayBlock[0].selectors->PrintList();
     //   curr->arrayBlock[0].attributes->PrintList();
     }
        curr = curr->next;
    }
    return numbersExit;
}
MyString* DoubleLinkedList::PrintJthSelector(int sectionNo, int selectorNo){
    struct Node *curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
                while(curr2){
                    if(curr2->selectorCounter == selectorNo){
                        return curr2->data;
                    }
                    curr2 = curr2->next;
                }
                return nullptr;
            }
        }
        curr = curr->next;
    }
    return nullptr;
}
MyString DoubleLinkedList::PrintNumberOfSections(){
    char s[11];
    sprintf_s(s, "%d", sectionCounter - 1);
    MyString number = s;
    return number;
}
MyString DoubleLinkedList::SearchForSelectorsByName(MyString *selectorName){
    int x = 0;
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
            while(curr2){
                if(curr2->data->compare(*selectorName)){
                    x++;
                }
                curr2 = curr2->next;
            }
        }
        curr = curr->next;
    }
    char s[11];
    sprintf_s(s, "%d", x);
    MyString number = s;
    return number;
}

MyString DoubleLinkedList::NumberOfAttributes(int sectionNo){
    int x = 0;
    MyString number;
    MyString numbersExit = "-1";
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
                while(curr2){
                        x = curr2->attCounter;
                    curr2 = curr2->next;
                }
                char s[11];
                sprintf_s(s, "%d", x);
                number = s;
                return number;
            }
        }
        curr = curr->next;
    }
    return numbersExit;
}
/*void DoubleLinkedList::NumberOfAttributesName(MyString *selectorName){

}*/
MyString* DoubleLinkedList::AttributeValueByName(MyString attributeName, int sectionNo){
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
                while(curr2){
                    if(curr2->attributes->compare(attributeName)){
                        return curr2->attValues;
                    }
                    curr2 = curr2->next;
                }
            }
        }
        curr = curr->next;
    }
    return nullptr;
}
DoubleLinkedList::~DoubleLinkedList(){
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}