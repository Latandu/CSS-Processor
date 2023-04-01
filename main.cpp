
#include "MyString.h"
#include "DoubleLinkedList.h"
#include "SingleLinkedList.h"
#include "ParseString.h"
int main() {
    MyString str1 = "h1";
    MyString str2 = "h22";
    DoubleLinkedList dll;
    dll.InsertSelectorAttributesIntoNode(&str1, &str2, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.InsertSelectorAttributesIntoNode(&str2, &str1, nullptr);
    dll.RemoveNode(1);
    dll.PrintList();
    return 0;


}