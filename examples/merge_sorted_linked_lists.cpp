#include "linkedlist.h"

#include <iostream>

auto main(int argc, char** argv) -> int {

    using namespace linked_list;

    LinkedList<int> l1, l2;

    l1.push(-650);
    l1.push(-60);
    l1.push(-36);
    l1.push(3);
    l1.push(5);
    l1.push(77);
    l1.push(90);
    l1.push(92);
    l1.push(100);

    l2.push(-650);
    l2.push(-640);
    l2.push(-360);
    l2.push(-37);
    l2.push(-36);
    l2.push(-35);
    l2.push(79);
    l2.push(88);

    auto merged_list = mergeTwoLists(l1, l2);

    std::cout << "Size of list:  " << merged_list.size() << std::endl;
    merged_list.reverse();
    std::cout << "Size of reversed after reverse:  " << merged_list.size()
              << std::endl;

    std::cout << "Printing linked list1:  " << l1 << std::endl;
    std::cout << "Printing linked list2:  " << l2 << std::endl;
    std::cout << "Printing merged_list:  " << merged_list << std::endl;

    return 0;
}
