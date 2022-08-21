#include "linkedlist.h"

#include <cassert>
#include <iostream>

auto main(int argc, char** argv) -> int {

    using namespace linked_list;

    LinkedList<int> l;
    l.push(-21);
    l.push(10);
    l.push(17);
    l.push(8);
    l.push(4);
    l.push(26);
    l.push(5);
    l.push(35);
    l.push(33);
    l.push(-7);
    l.push(-16);
    l.push(27);
    l.push(-12);
    l.push(6);
    l.push(29);
    l.push(-12);
    l.push(5);
    l.push(9);
    l.push(20);
    l.push(14);
    l.push(14);
    l.push(2);
    l.push(13);
    l.push(-24);
    l.push(21);
    l.push(23);
    l.push(-21);
    l.push(5);
    std::cout << "Printing linked list:  " << l << std::endl;

    std::cout << "linked list has a cycle:  " << std::boolalpha << l.hasCycle()
              << std::endl;

    assert(!l.hasCycle());

    l.clear();
    l.push(3);
    l.push(2);
    l.push(0);
    l.push(-4);
    l.push(2);
    l.push(0);

    std::cout << "Printing linked list:  " << l << std::endl;
    std::cout << "linked list has a cycle:  " << std::boolalpha << l.hasCycle()
              << std::endl;

    assert(l.hasCycle());

    return 0;
}
