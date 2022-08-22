#ifndef _QUEUE_H
#define _QUEUE_H

#include <optional>
#include <stack>

namespace queue {

template <typename T>
class QueueViaStacks {

    std::stack<T> top_stack;
    std::stack<T> bottom_stack;

    auto shuffleStacks() -> void;

  public:
    auto enqueue(const T& x) -> void;
    auto dequeue() -> std::optional<T>;
    auto peek() -> std::optional<T>;
    auto empty() -> bool;
};

template <typename T>
auto QueueViaStacks<T>::enqueue(const T& x) -> void {
    top_stack.push(x);
}

template <typename T>
auto QueueViaStacks<T>::dequeue() -> std::optional<T> {

    shuffleStacks();
    if (bottom_stack.empty())
        return {};

    auto res = bottom_stack.top();
    bottom_stack.pop();
    return res;
}

template <typename T>
auto QueueViaStacks<T>::peek() -> std::optional<T> {
    shuffleStacks();

    if (bottom_stack.empty())
        return {};

    return bottom_stack.top();
}

template <typename T>
auto QueueViaStacks<T>::empty() -> bool {
    return (top_stack.empty() && bottom_stack.empty());
}

template <typename T>
auto QueueViaStacks<T>::shuffleStacks() -> void {

    if (bottom_stack.empty()) {
        while (!top_stack.empty()) {
            bottom_stack.push(top_stack.top());
            top_stack.pop();
        }
    }
}

} // namespace queue
#endif
