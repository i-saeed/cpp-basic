#include "queue.h"

#include <iostream>

auto main(int argc, char** argv) -> int {

    using namespace queue;
    QueueViaStacks<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();

    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();

    q.enqueue(7);
    q.enqueue(8);

    while (!q.empty()) {
        std::cout << q.dequeue().value() << ", ";
    }

    std::cout << std::endl;

    return 0;
}
