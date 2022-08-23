#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <vector>

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

template <typename T>
class BinarySearchTree {

    TreeNode<T>* root{nullptr};

    auto insert(const T val, TreeNode<T>* node) -> TreeNode<T>*;
    auto inorderTraversal(TreeNode<T>* node, const std::vector<T>& vec = {})
        -> std::vector<T>;

  public:
    auto insert(const T val) -> void;
    auto empty() -> bool;

    friend auto operator<<(std::ostream& s, BinarySearchTree<T>& tree)
        -> std::ostream&;

    ~BinarySearchTree();
};

template <typename T>
auto BinarySearchTree<T>::insert(const T val) -> void {
    root = insert(val, root);
}

template <typename T>
auto BinarySearchTree<T>::insert(const T val, TreeNode<T>* node)
    -> TreeNode<T>* {

    if (!node) {
        return new TreeNode<T>(val);
    }

    if (val < node->val) {

        node->left = insert(val, node->left);
    } else if (val > node->val) {
        node->right = insert(val, node->right);
    }
    return node;
}

template <typename T>
auto BinarySearchTree<T>::empty() -> bool {
    return (!root);
}

template <typename T>
auto operator<<(std::ostream& s, const BinarySearchTree<T>& tree)
    -> std::ostream& {

    if (tree.root) {
        auto vals = inorderTraversal(tree.root);
        for (const auto& v : vals) {
            s << v << ", ";
        }
    }
    return s;
}

template <typename T>
auto BinarySearchTree<T>::inorderTraversal(TreeNode<T>*          node,
                                           const std::vector<T>& vec)
    -> std::vector<T> {

    std::vector<T> values;

    if (!node)
        return values;

    const auto left_vals = inorderTraversal(node->left);
    values.insert(values.end(), left_vals.begin(), left_vals.end());
    values.push_back(node->val);
    const auto right_vals = inorderTraversal(node->right);
    values.insert(values.end(), right_vals.begin(), right_vals.end());

    return values;
}

} // namespace binary_tree

#endif
