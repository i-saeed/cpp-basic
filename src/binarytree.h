#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <limits>
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
    auto inorderTraversal(TreeNode<T>* node) const -> std::vector<T>;
    auto deleteNode(TreeNode<T>* node) -> void;

  public:
    auto insert(const T val) -> void;
    auto empty() -> bool;
    auto inorderTraversal() const -> std::vector<T>;

    template <typename t>
    friend std::ostream& operator<<(std::ostream&              s,
                                    const BinarySearchTree<t>& tree);

    ~BinarySearchTree();
};

template <typename T>
auto verifyBST(const BinarySearchTree<T>& tree) -> bool;

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
std::ostream& operator<<(std::ostream& s, const BinarySearchTree<T>& tree) {

    if (tree.root) {
        auto vals = tree.inorderTraversal();
        for (const auto& v : vals) {
            s << v << ", ";
        }
    }
    return s;
}

template <typename T>
auto BinarySearchTree<T>::inorderTraversal(TreeNode<T>* node) const
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

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    deleteNode(root);
}

template <typename T>
auto BinarySearchTree<T>::inorderTraversal() const -> std::vector<T> {
    return inorderTraversal(root);
}

template <typename T>
auto BinarySearchTree<T>::deleteNode(TreeNode<T>* node) -> void {
    if (node) {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}

namespace _inner {
template <typename T>
auto verifyBSTNode(TreeNode<T>* node, T min, T max) -> bool {
    if (!node)
        return true;

    if (((node->val) > max) || ((node->val) < min))
        return false;

    auto verify_left  = verifyBSTNode(node->left, min, node->val);
    auto verify_right = verifyBSTNode(node->right, node->val, max);
    return verify_left && verify_right;
}
} // namespace _inner

template <typename T>
auto verifyBST(const BinarySearchTree<T>& tree) -> bool {

    auto root = tree.root;

    return _inner::verifyBSTNode(tree.root, std::numeric_limits<T>::min(),
                                 std::numeric_limits<T>::max());
}

} // namespace binary_tree

#endif //_BINARY_TREE_H
