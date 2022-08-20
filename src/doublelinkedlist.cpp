#include <exception>
#include <stdexcept>

template <typename T>
class Node {
  public:
    T value;
    Node* prev{nullptr};
    Node* next{nullptr};
};

template <typename T>
class DoubleLinkedList {
  private:
    Node<T>* head{nullptr};
    Node<T>* root{nullptr};
    size_t len{0};

  public:
    auto push_front(T value) -> void;
    auto push_back(T value) -> void;
    auto pop_front() -> T;
    auto pop_back() -> T;
    auto empty() -> bool;
    auto clear() -> void;
    auto size() -> size_t;
    auto front() -> T;
    auto back() -> T;
    ~DoubleLinkedList();
};

template <typename T>
auto DoubleLinkedList<T>::back() -> T {
    if (!root) {
        throw std::runtime_error("Empty DoubleLinkedList, cannot pop more");
    }
    return head->value;
}

template <typename T>
auto DoubleLinkedList<T>::front() -> T {
    if (!root) {
        throw std::runtime_error("Empty DoubleLinkedList, cannot pop more");
    }
    return root->value;
}

template <typename T>
auto DoubleLinkedList<T>::push_back(T value) -> void {

    if (!root) {
        root = new Node<T>;
        root->value = value;
        head = root;
    } else {
        auto temp = new Node<T>;
        temp->value = value;
        temp->prev = head;
        head->next = temp;
        head = temp;
    }
    len++;
}

template <typename T>
auto DoubleLinkedList<T>::push_front(T value) -> void {

    if (!root) {
        root = new Node<T>;
        root->value = value;
        head = root;
    } else {
        auto temp = new Node<T>;
        temp->value = value;
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
    len++;
}

template <typename T>
auto DoubleLinkedList<T>::pop_back() -> T {
    T value;
    if (!root) {
        throw std::runtime_error("Empty DoubleLinkedList, cannot pop more");
    } else if (root == head) {
        value = head->value;
        delete root;
        head = nullptr;
    } else {
        value = head->value;
        auto temp = head;
        head = head->prev;
        head->next = nullptr;
        delete temp;
    }
    len--;
    return value;
}

template <typename T>
auto DoubleLinkedList<T>::pop_front() -> T {
    T value;
    if (!root) {
        throw std::runtime_error("Empty DoubleLinkedList, cannot pop more");
    } else if (root == head) {
        value = head->value;
        delete root;
        head = nullptr;
    } else {
        value = root->value;
        auto temp = root;
        root = root->next;
        root->prev = nullptr;
        delete temp;
    }
    len--;
    return value;
}

template <typename T>
auto DoubleLinkedList<T>::empty() -> bool {
    return (len != 0) ? false : true;
}

template <typename T>
auto DoubleLinkedList<T>::size() -> size_t {
    return len;
}

template <typename T>
auto DoubleLinkedList<T>::clear() -> void {
    while (!empty()) {
        pop_back();
    }
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    clear();
}

auto main(int argc, char** argv) -> int {

    DoubleLinkedList<int> l;

    l.push_back(3);
    l.push_back(5);
    l.push_back(-60);
    l.push_back(90);
    l.push_back(-650);
    l.push_back(50);
    l.push_back(-36);
    l.push_back(77);
    l.push_back(78);

    do {
        std::cout << l.pop_front() << ", ";
    } while (!l.empty());

    std::cout << std::endl;

    return 0;
}
