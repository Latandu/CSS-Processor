//
// Created by Latandu on 31/03/2023.
//

#include <cstdlib>
#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList() {

}
void DoubleLinkedList::InsertNodeAtTail(int data){
    auto *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data;
    newNode -> next = NULL;
    if(!head){
        head = tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
    free(newNode);
};