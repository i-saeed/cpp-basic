#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>
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
    auto empty() -> bool;
    auto clear() -> void;
    auto size() -> size_t;
    auto peek() -> T;
    ~LinkedList();
    auto reverse() -> void;
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
auto LinkedList<T>::empty() -> bool {
    return (len != 0) ? false : true;
}

template <typename T>
auto LinkedList<T>::size() -> size_t {
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

    if (head) {
        auto iter = head;
        Node<T>* prev_iter{nullptr};

        while (true) {
            if (iter->prev) {

                auto temp = iter->prev;
                iter->prev = prev_iter;
                if (temp->prev) {
                    auto temp2 = temp->prev;
                    temp->prev = iter;
                    prev_iter = temp;
                    iter = temp2;
                } else {
                    temp->prev = iter;
                    iter = temp;
                    break;
                }
            } else {
                iter->prev = prev_iter;
                break;
            }
        }
        root = head;
        root->prev = nullptr;
        head = iter;
    }
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

} // namespace linked_list

#endif
