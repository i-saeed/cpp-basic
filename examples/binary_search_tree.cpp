#include "binarytree.h"

#include <cassert>
#include <iostream>
#include <vector>

auto main(int argc, char** argv) -> int {

    using namespace binary_tree;

    BinarySearchTree<int> bst;

    bst.insert(8);
    bst.insert(10);
    bst.insert(14);
    bst.insert(13);
    bst.insert(3);
    bst.insert(1);
    bst.insert(6);
    bst.insert(4);
    bst.insert(7);

    std::cout << " BST:  " << bst << std::endl;

    const auto expected = std::vector<int>{1, 3, 4, 6, 7, 8, 10, 13, 14};
    const auto obtained = bst.inorderTraversal();

    assert(expected == obtained);

    std::cout << std::endl;

    return 0;
}
