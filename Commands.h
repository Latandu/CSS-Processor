//
// Created by Latandu on 02/04/2023.
//

#ifndef PROJECT1_COMMANDS_H
#define PROJECT1_COMMANDS_H


#include "DoubleLinkedList.h"

class Commands {
private:

public:
    void commandQM(DoubleLinkedList* dll);
    Commands();
    ~Commands();

    void commandSelectorForSection(DoubleLinkedList *dll, int sectionNo);

    void commandPrintJthSelector(DoubleLinkedList *dll, int sectionNo, int selectorNo);
};


#endif //PROJECT1_COMMANDS_H
