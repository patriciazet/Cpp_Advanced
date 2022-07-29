#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DoublyLinkedList list;
    
    list.insertFront(5);
    list.insertFront(4);
    list.insertFront(3);
    list.insertFront(2);
    list.insertFront(1);
    list.insertFront(0);

    list.print();
    //list.clear();
    list.insertAfter(33, 3);
    std::cout << std::endl;
    list.print();
    std::cout << std::endl << std::endl;
    std::cout << list[3];

    list.remove(6);

    std::cout << std::endl;
    list.print();


    list.clear();
    std::cout << std::endl;
    list.print();
    list.insertFront(11);
    std::cout << std::endl;
    list.print();
    list.remove(0);
    std::cout << std::endl;
    list.print();
}
