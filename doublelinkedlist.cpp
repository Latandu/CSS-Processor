//
// Created by Latandu on 31/03/2023.
//

#include "MyString.h"
#include "DoubleLinkedList.h"
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#define T 8
DoubleLinkedList::DoubleLinkedList() : head(nullptr), tail(){
}
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
        tail = newNode;
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
    tail = newNode;
    newNode->nodeIndex = counter;
    delete[] newArrayBlock;
}
void DoubleLinkedList::InsertSelectorAttributesIntoNode(MyString newSelector[], MyString newAttribute[],MyString newAttributeVal[], int attlistCounter, int selListCounter) {
    struct Node *selectorNode;
    if(tail == nullptr) selectorNode = head;
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
    InsertNodeAtTail();
    InsertSelectorAttributesIntoNode(newSelector, newAttribute, newAttributeVal, attlistCounter, selListCounter);
    delete selectorNode;
}

MyString DoubleLinkedList::PrintNumberOfSelectors(int sectionNo) {
    struct Node *curr = head;
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
                sprintf(s, "%d", curr2->selectorCounter);
                MyString number = s;
                return number;
        }
     //   curr->arrayBlock[0].selectors->PrintList();
     //   curr->arrayBlock[0].attributes->PrintList();
     }
        curr = curr->next;
    }
    return {"-1"};
}
MyString DoubleLinkedList::PrintJthSelector(int sectionNo, int selectorNo){
    struct Node *curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
                while(curr2){
                    if(curr2->selectorCounter == selectorNo){
                        if(curr2->data[0].printarr() == nullptr) return {"0"};
                        if(*curr2->data[0].printarr() == '~'){
                            return {"0"};
                        }
                        return *curr2->data;
                    }
                    curr2 = curr2->next;
                }
                return {"-1"};
            }
        }
        curr = curr->next;
    }
    return {"-1"};
}
MyString DoubleLinkedList::PrintNumberOfSections(){
    char s[11];
    sprintf(s, "%d", sectionCounter - 1);
    MyString number = s;
    return number;
}
MyString DoubleLinkedList::SearchForSelectorsByName(const MyString& selectorName){
    int x = 0;
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            struct SingleLinkedList::SingleNode *curr2 = curr->arrayBlock[i].selectors->head;
            while(curr2){
                if(curr2->data->compare(selectorName)){
                    x++;
                }
                curr2 = curr2->next;
            }
        }
        curr = curr->next;
    }
    char s[11];
    sprintf(s, "%d", x);
    MyString number = s;
    return number;
}

MyString DoubleLinkedList::NumberOfAttributes(int sectionNo){
    int x = 0;
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
                sprintf(s, "%d", x);
                MyString number = s;
                return number;
            }
        }
        curr = curr->next;
    }
    return {"-1"};
}
MyString DoubleLinkedList::AttributeValueByName(const MyString& attributeName, int sectionNo){
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo){
                struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
                while(curr2){
                    if(curr2->attributes->compare(attributeName)){
                        return *curr2->attValues;
                    }
                    curr2 = curr2->next;
                }
            }
        }
        curr = curr->next;
    }
    return {"-1"};
}
MyString DoubleLinkedList::NumberOfAttributesSelectedByName(MyString attributeName){
    int x = 0;
    struct Node* curr = head;

    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
            while(curr2){
                if(curr2->attributes->compare(attributeName)){
                    x++;
                }
                curr2 =curr2->next;
            }
        }
        curr = curr->next;
    }
    char s[11];
    sprintf(s, "%d", x);
    MyString number = s;
    return number;
}
MyString DoubleLinkedList::LastAttributeValueForSelector(const MyString& attributeName, const MyString& selector){
    struct Node* curr = tail;
    if(tail == nullptr) curr = head;
        while(curr){
        for(int i = T-1; i >= 0; i--){
            if(!curr->arrayBlock[i].isWritten) continue;
            struct SingleLinkedList::SingleNode *curr3 = curr->arrayBlock[i].selectors->head;
            if(curr3 == nullptr) return nullptr;
            if(curr3->data->compare(selector)){
                struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
                while(curr2){
                    if(curr2->attributes->compare(attributeName)){
                        MyString returnValue = *curr2->attValues;
                        return returnValue;
                    }
                        curr2 = curr2->next;
                }
            }
        }
        curr=curr->prev;
    }
    return {"-1"};
}
MyString DoubleLinkedList::RemoveWholeSection(int sectionNo){
    struct Node* curr = head;
    while(curr){
        int counter = 0;
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            else counter++;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo) {
                curr->arrayBlock[i].selectors = nullptr;
                curr->arrayBlock[i].attributes = nullptr;
                curr->arrayBlock[i].arraySectionCounter = 0;
                curr->arrayBlock[i].isWritten = false;
                sectionCounter = sectionCounter - 1;
                if (counter == 1) {
                    while (curr) {
                        for (int j = 0; j < T; j++) {
                            if(curr->arrayBlock[j].isWritten && curr->arrayBlock[j].arraySectionCounter > sectionNo){
                                curr->arrayBlock[j].arraySectionCounter = curr->arrayBlock[j].arraySectionCounter - 1;
                            }
                        }
                        curr = curr->next;
                    }
                    return {"deleted"};
                }
                while (curr) {
                    for(int j = 0; j < T; j++){
                        if(curr->arrayBlock[j].isWritten && curr->arrayBlock[j].arraySectionCounter > sectionNo)
                            curr->arrayBlock[j].arraySectionCounter = curr->arrayBlock[j].arraySectionCounter - 1;
                    }
                    curr = curr->next;
                }
                return {"deleted"};
            }
        }
        curr = curr->next;
    }
    return {"-1"};
}
MyString DoubleLinkedList::RemoveAttributeFromSectionByName(int sectionNo, MyString attributeName){
    struct Node* curr = head;
    while(curr){
        for(int i = 0; i < T; i++){
            if(!curr->arrayBlock[i].isWritten) continue;
            if(curr->arrayBlock[i].arraySectionCounter == sectionNo) {
                struct SSLAtt::SingleNode *curr2 = curr->arrayBlock[i].attributes->head;
                struct SSLAtt::SingleNode *prev = nullptr;
                while(curr2){
                    if(curr2->attributes->compare(attributeName)){
                        if(curr2->next == nullptr && prev == nullptr){
                            RemoveWholeSection(sectionNo);
                            return {"deleted"};

                        }
                        else if(prev == nullptr){
                            curr->arrayBlock[i].attributes->head = curr2->next;
                            curr2->next = nullptr;
                            while(curr2){
                                curr2->attCounter = curr2->attCounter - 1;
                                curr2 = curr2->next;
                            }
                            return {"deleted"};

                        }
                        else {
                            prev->next = curr2->next;
                            if (prev->next == nullptr) {
                                curr2 = prev;
                            }
                            while(curr2){
                                curr2->attCounter = curr2->attCounter - 1;
                                curr2 = curr2->next;
                            }
                            return {"deleted"};

                        }
                    }
                    prev = curr2;
                    curr2 = curr2->next;
                }
                return {"-1"};
            }
        }
        curr = curr->next;
    }
    return {"-1"};
}
DoubleLinkedList::~DoubleLinkedList(){
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}