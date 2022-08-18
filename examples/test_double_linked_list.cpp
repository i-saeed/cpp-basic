#include "doublelinkedlist.h"

#include <iostream>

auto main(int argc, char** argv) -> int {

    using namespace double_linked_list;

    DoubleLinkedList<int> l;

    l.push_back(3);
    l.push_back(5);
    l.push_back(-60);
    l.push_back(90);
    l.push_back(-650);
    l.push_back(50);
    l.push_back(-36);
    l.push_back(77);
    l.push_back(78);

    do {
        std::cout << l.pop_front() << ", ";
    } while (!l.empty());

    std::cout << std::endl;

    return 0;
}
