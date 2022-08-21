#include "linkedlist.h"

#include <iostream>

auto main(int argc, char** argv) -> int {

    using namespace linked_list;

    LinkedList<int> l;

    l.push(3);
    l.push(5);
    l.push(-60);
    l.push(90);
    l.push(-650);
    l.push(50);
    l.push(-36);
    l.push(77);
    l.push(78);

    std::cout << "Size of list:  " << l.size() << std::endl;
    l.reverse();
    std::cout << "Size of reversed after reverse:  " << l.size() << std::endl;
    do {
        std::cout << l.pop() << ", ";
    } while (!l.empty());

    std::cout << std::endl;

    return 0;
}
