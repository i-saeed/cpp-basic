#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>
#include <iostream>
#include <stdexcept>

namespace linked_list {

template <typename T>
class Node {
  public:
    T value;
    Node* prev{nullptr};
};

template <typename T>
class LinkedList {
  private:
    Node<T>* head{nullptr};
    Node<T>* root{nullptr};
    size_t len{0};

  public:
    auto push(T value) -> void;
    auto pop() -> T;
    auto empty() const -> bool;
    auto clear() -> void;
    auto size() const -> size_t;
    auto peek() -> T;
    ~LinkedList();
    auto reverse() -> void;
    auto getHead() -> Node<T>*;

    template <typename t>
    friend std::ostream& operator<<(std::ostream& os,
                                    const LinkedList<t>& list);

    template <typename t>
    friend auto mergeTwoLists(const linked_list::LinkedList<t>& list_a,
                              const linked_list::LinkedList<t>& list_b)
        -> linked_list::LinkedList<t>;
};

template <typename T>
auto LinkedList<T>::peek() -> T {
    if (!root) {
        throw std::runtime_error("Empty LinkedList, cannot pop more");
    }
    return head->value;
}

template <typename T>
auto LinkedList<T>::push(T value) -> void {

    if (!root) {
        root = new Node<T>;
        root->value = value;
        head = root;
    } else {
        auto temp = new Node<T>;
        temp->value = value;
        temp->prev = head;
        head = temp;
    }
    len++;
}

template <typename T>
auto LinkedList<T>::pop() -> T {
    T value;
    if (!root) {
        throw std::runtime_error("Empty LinkedList, cannot pop more");
    } else if (root == head) {
        value = head->value;
        delete root;
        head = nullptr;
    } else {
        value = head->value;
        auto temp = head;
        head = head->prev;
        delete temp;
    }
    len--;
    return value;
}

template <typename T>
auto LinkedList<T>::empty() const -> bool {
    return (len != 0) ? false : true;
}

template <typename T>
auto LinkedList<T>::size() const -> size_t {
    return len;
}

template <typename T>
auto LinkedList<T>::clear() -> void {
    while (!empty()) {
        pop();
    }
}

template <typename T>
auto LinkedList<T>::reverse() -> void {

    if (root && (head->prev)) {

        auto prev_iter = static_cast<Node<T>*>(nullptr);
        auto iter = head;
        auto tmp = iter->prev;

        while (iter) {
            tmp = iter->prev;
            iter->prev = prev_iter;
            prev_iter = iter;
            iter = tmp;
        }

        root = head;
        root->prev = nullptr;
        head = prev_iter;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
auto LinkedList<T>::getHead() -> Node<T>* {
    return head;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    auto iter = list.head;
    while (iter) {
        os << iter->value << ", ";
        iter = iter->prev;
    }
    return os;
}

template <typename T>
auto mergeTwoLists(const linked_list::LinkedList<T>& list_a,
                   const linked_list::LinkedList<T>& list_b)
    -> linked_list::LinkedList<T> {

    LinkedList<T> merge_list;
    auto head_a = list_a.head;
    auto head_b = list_b.head;
    // merge_list.push(50);
    return merge_list;
}

} // namespace linked_list

#endif
