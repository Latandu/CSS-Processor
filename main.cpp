
#include "MyString.h"
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "ParseString.h"
int main() {
    MyString str1 = "h1";
    MyString str2 = "h22";
    DoubleLinkedList dll;
    ParseString parse;
    parse.Parsing(&dll);
    dll.PrintList();
    return 0;


}