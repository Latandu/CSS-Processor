
#include "mystring.h"
#include "doublelinkedlist.h"
#include "singlelinkedlist.h"
#include "parsestring.h"
#define _CRT_SECURE_NO_WARNINGS

int main() {
    DoubleLinkedList dll;
    ParseString parse;
    parse.ParseWholeString(&dll);
    return 0;


}