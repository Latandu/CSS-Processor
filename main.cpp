
#include "MyString.h"
#include "DoubleLinkedList.h"
int main() {
    MyString str1 = "h1";
    MyString str2 = "h22";
    DoubleLinkedList ddl;
    ddl.InsertNodeAtTail(&str1);
    ddl.InsertNodeAtTail(&str2);
    ddl.PrintList();
    return 0;


}