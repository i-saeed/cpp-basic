#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

namespace binary_tree {

template <typename T>
struct TreeNode {
    T            val{0};
    TreeNode<T>* left{nullptr};
    TreeNode<T>* right{nullptr};

    TreeNode() = default;
    TreeNode(T _val) : val(_val) {}
    TreeNode(T _val, TreeNode<T>* _left, TreeNode<T>* _right)
        : val(_val), left(left), right(right) {}
};

class BinarySearchTree{

}

} // namespace binary_tree

#endif
