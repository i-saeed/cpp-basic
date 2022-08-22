#ifndef _QUEUE_H
#define _QUEUE_H

#include <stack>

namespace queue {

template <typename T>
class QueueViaStacks {

    std::stack<T> top_stack;
    std::stack<T> bottom_stack;

  public:
    auto enqueue(const T& x) -> void;
    auto dequeue() -> T;
    auto peek() -> T;
    auto isEmpty() -> bool;
};

template <typename T>
auto QueueViaStacks<T>::enqueue(const T& x) -> void {
    top_stack.push(x);
}

template <typename T>
auto QueueViaStacks<T>::dequeue() -> T {}

template <typename T>
auto QueueViaStacks<T>::peek() -> T {}

template <typename T>
auto QueueViaStacks<T>::isEmpty() -> bool {}

} // namespace queue
#endif
