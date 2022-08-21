#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <exception>
#include <iostream>
#include <stdexcept>
#include <unordered_set>

namespace linked_list {

template <typename T>
class Node {
  public:
    T     value;
    Node* prev{nullptr};
};

template <typename T>
class LinkedList {
  private:
    Node<T>* head{nullptr};
    size_t   len{0};

  public:
    LinkedList() = default;

    LinkedList(const LinkedList<T>& other);
    auto operator=(const LinkedList<T>& other) -> LinkedList<T>&;
    ~LinkedList();

    auto push(T value) -> void;
    auto pop() -> T;
    auto empty() const -> bool;
    auto clear() -> void;
    auto size() const -> size_t;
    auto peek() -> T;
    auto reverse() -> void;
    auto hasCycle() -> bool;

    template <typename t>
    friend std::ostream& operator<<(std::ostream&        os,
                                    const LinkedList<t>& list);

    template <typename t>
    friend auto mergeTwoLists(const linked_list::LinkedList<t>& list_a,
                              const linked_list::LinkedList<t>& list_b)
        -> linked_list::LinkedList<t>;
};

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
    auto other_head = other.head;
    while (other_head) {
        push(other_head->value);
        other_head = other_head->prev;
    }
}

template <typename T>
auto LinkedList<T>::operator=(const LinkedList<T>& other) -> LinkedList<T>& {
    if (this == &other)
        return *this;

    clear();

    auto other_head = other.head;
    while (other_head) {
        push(other_head->value);
        other_head = other_head->prev;
    }
    return *this;
}

template <typename T>
auto LinkedList<T>::peek() -> T {
    if (!head) {
        throw std::runtime_error("Empty LinkedList, cannot pop more");
    }
    return head->value;
}

template <typename T>
auto LinkedList<T>::push(T value) -> void {

    if (!head) {
        head        = new Node<T>;
        head->value = value;
    } else {
        auto temp   = new Node<T>;
        temp->value = value;
        temp->prev  = head;
        head        = temp;
    }
    len++;
}

template <typename T>
auto LinkedList<T>::pop() -> T {
    T value;
    if (!head) {
        throw std::runtime_error("Empty LinkedList, cannot pop more");
    } else if ((!head->prev)) {
        value = head->value;
        delete head;
    } else {
        value     = head->value;
        auto temp = head;
        head      = head->prev;
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
    head = nullptr;
}

template <typename T>
auto LinkedList<T>::reverse() -> void {

    if (head && (head->prev)) {

        auto prev_iter = static_cast<Node<T>*>(nullptr);
        auto iter      = head;
        auto tmp       = iter->prev;

        while (iter) {
            tmp        = iter->prev;
            iter->prev = prev_iter;
            prev_iter  = iter;
            iter       = tmp;
        }

        head = prev_iter;
    }
}

template <typename T>
auto LinkedList<T>::hasCycle() -> bool {

    if (!head || !(head->prev))
        return false;

    std::unordered_set<T> history;

    auto exists = bool{false};

    auto iter = head;
    while (iter) {
        const auto current_val = iter->value;
        if (history.count(current_val)) {
            exists = true;
            break;
        } else {
            history.insert(current_val);
        }
        iter = iter->prev;
    }

    return exists;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
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

    auto iter_a = list_a.head;
    auto iter_b = list_b.head;

    LinkedList<T> merge_list;

    if (!iter_a && !iter_b) {
        return LinkedList<T>();
    } else if (!iter_a) {
        return list_b;
    } else if (!iter_b) {
        return list_a;
    }

    auto iter_m      = merge_list.head;
    auto iter_copy   = static_cast<Node<T>*>(nullptr);
    auto iter_m_prev = static_cast<Node<T>*>(nullptr);

    auto comparator = bool{false};

    while (iter_a || iter_b) {
        auto tmp = new Node<T>;

        if (!iter_a || !iter_b) {
            comparator = (iter_a);
        } else {
            comparator = (iter_a->value <= iter_b->value);
        }

        iter_copy = comparator ? iter_a : iter_b;

        iter_a = comparator ? iter_a->prev : iter_a;
        iter_b = (!comparator) ? iter_b->prev : iter_b;

        tmp->value   = iter_copy->value;
        iter_m       = tmp;
        iter_m->prev = iter_m_prev;
        iter_m_prev  = iter_m;
    }
    merge_list.head = iter_m;

    return merge_list;
}

} // namespace linked_list

#endif
