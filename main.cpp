
#include "mystring.h"
#include "doublelinkedlist.h"
#include "singlelinkedlist.h"
#include "parsestring.h"


int main() {
    DoubleLinkedList dll;
    ParseString parse;
    parse.ParseWholeString(&dll);
    return 0;


}