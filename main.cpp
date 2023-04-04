
#include "MyString.h"
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "ParseString.h"


int main() {
    DoubleLinkedList dll;
    ParseString parse;
    parse.ParseWholeString(&dll);
    return 0;


}