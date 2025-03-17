#include "queueHeader.hpp"
#include <vector>

int main() {
    Queue<int> q;

    // 1. Pushing elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    // 2. Display front and back elements
    std::cout << "Front: " << q.front() << "\n";
    std::cout << "Back: " << q.back() << "\n";

    // 3. Popping an element
    q.pop();
    std::cout << "After pop, front: " << q.front() << "\n";

    // 4. Checking if queue is empty
    std::cout << "Queue is empty? " << (q.empty() ? "Yes" : "No") << "\n";

    // 5. Checking size
    std::cout << "Queue size: " << q.size_() << "\n";

    // 6. Pushing a range of elements
    std::vector<int> values = {50, 60, 70, 80};
    q.push_range(values.begin(), values.end());

    // 7. Iterating over queue using iterator
    std::cout << "Queue elements: ";
    for (auto it = q.begin(); it != q.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 8. Using const_iterator
    std::cout << "Queue elements (const_iterator): ";
    for (auto it = q.cbegin(); it != q.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 9. Swapping queues
    Queue<int> q2;
    q2.push(100);
    q2.push(200);

    std::cout << "Swapping queues...\n";
    q.swap(q2);

    std::cout << "Queue 1 after swap: ";
    for (auto it = q.begin(); it != q.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    std::cout << "Queue 2 after swap: ";
    for (auto it = q2.begin(); it != q2.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    // 10. Clearing queue
    q.clear();
    std::cout << "After clear, queue size: " << q.size_() << "\n";
    
    return 0;
}
