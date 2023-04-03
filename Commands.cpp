//
// Created by Latandu on 02/04/2023.
//

#include "Commands.h"
#include "DoubleLinkedList.h"
Commands::Commands() {};
void Commands::commandQM(DoubleLinkedList* dll){
    dll->PrintNumberOfSections();
};
void Commands::commandSelectorForSection(DoubleLinkedList* dll, int sectionNo){
    dll->PrintNumberOfSelectors(sectionNo);
}
void Commands::commandPrintJthSelector(DoubleLinkedList* dll, int sectionNo, int selectorNo){
    dll->PrintJthSelector(sectionNo, selectorNo);
}
Commands::~Commands() {};