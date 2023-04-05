
#include "MyString.h"
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "ParseString.h"

#define STATUS_HEAP_CORRUPTION           ((NTSTATUS)0xC0000374L)
int main() {
    DoubleLinkedList dll;
    ParseString parse;
    parse.ParseWholeString(&dll);
    return 0;


}