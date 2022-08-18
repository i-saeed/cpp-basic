#include <exception>
#include <iostream>
#include <stdexcept>

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
LinkedList<T>::~LinkedList() {
    clear();
}

auto main(int argc, char** argv) -> int {

    LinkedList<int> l;

    l.push(3);
    l.push(5);
    l.push(-60);
    l.push(90);
    l.push(-650);
    l.push(50);
    l.push(-36);
    l.push(77);
    l.push(78);

    do {
        std::cout << l.pop() << ", ";
    } while (!l.empty());

    std::cout << std::endl;

    return 0;
}
