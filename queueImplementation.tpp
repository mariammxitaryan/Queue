#include "queueHeader.hpp"

// Node constructor that initializes data, next, and prev pointers
template <typename T>
Queue<T>::Node::Node(const T& value) : data(value), next(nullptr), prev(nullptr) { }

/* ============================== ITERATOR CLASS ============================== */

// Iterator constructor to initialize the iterator with a pointer to a Node
template <typename T>
Queue<T>::iterator::iterator(typename Queue<T>::Node* ptr) : node_ptr(ptr) { }

// Dereference operator to return the data of the current Node the iterator points to
template <typename T>
typename Queue<T>::iterator::reference Queue<T>::iterator::operator*() const {
    return node_ptr->data;
}

// Arrow operator to return the pointer to the data of the current Node
template <typename T>
typename Queue<T>::iterator::pointer Queue<T>::iterator::operator->() const {
    return &node_ptr->data;
}

// Pre-increment operator to move the iterator to the next Node
template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

// Pre-decrement operator to move the iterator to the previous Node
template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

// Post-increment operator to return the current iterator before moving to the next Node
template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator++(int) {
    typename Queue<T>::iterator it = *this;
    node_ptr = node_ptr->next;
    return it;
}

// Post-decrement operator to return the current iterator before moving to the previous Node
template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator--(int) {
    typename Queue<T>::iterator it = *this;
    node_ptr = node_ptr->prev;
    return it;
}

// Equality comparison operator to compare two iterators
template <typename T>
bool Queue<T>::iterator::operator==(const typename Queue<T>::iterator& other) const {
    return node_ptr == other.node_ptr;
}

// Inequality comparison operator to compare two iterators
template <typename T>
bool Queue<T>::iterator::operator!=(const typename Queue<T>::iterator& other) const {
    return node_ptr != other.node_ptr;
}

/* ============================== CONST_ITERATOR CLASS ============================== */

// Const iterator constructor to initialize the iterator with a pointer to a Node
template <typename T>
Queue<T>::const_iterator::const_iterator(typename Queue<T>::Node* ptr) : node_ptr(ptr) { }

// Dereference operator to return the data of the current Node the iterator points to (const)
template <typename T>
typename Queue<T>::const_iterator::reference Queue<T>::const_iterator::operator*() const {
    return node_ptr->data;
}

// Arrow operator to return the pointer to the data of the current Node (const)
template <typename T>
typename Queue<T>::const_iterator::pointer Queue<T>::const_iterator::operator->() const {
    return &node_ptr->data;
}

// Pre-increment operator to move the const iterator to the next Node
template <typename T>
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

// Pre-decrement operator to move the const iterator to the previous Node
template <typename T>
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

// Post-increment operator to return the current const iterator before moving to the next Node
template <typename T>
typename Queue<T>::const_iterator Queue<T>::const_iterator::operator++(int) {
    typename Queue<T>::const_iterator it = *this;
    node_ptr = node_ptr->next;
    return it;
}

// Post-decrement operator to return the current const iterator before moving to the previous Node
template <typename T>
typename Queue<T>::const_iterator Queue<T>::const_iterator::operator--(int) {
    typename Queue<T>::const_iterator it = *this;
    node_ptr = node_ptr->prev;
    return it;
}

// Equality comparison operator to compare two const iterators
template <typename T>
bool Queue<T>::const_iterator::operator==(const typename Queue<T>::const_iterator& other) const {
    return node_ptr == other.node_ptr;
}

// Inequality comparison operator to compare two const iterators
template <typename T>
bool Queue<T>::const_iterator::operator!=(const typename Queue<T>::const_iterator& other) const {
    return node_ptr != other.node_ptr;
}

/* ============================== QUEUE CLASS ============================== */

// Default constructor that initializes an empty queue with head, tail, and size
template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) { }

// Destructor that clears all the nodes in the queue
template <typename T>
Queue<T>::~Queue() {
    clear();
}

// Push function to add a new value to the back of the queue
template <typename T>
void Queue<T>::push(const T& value) {
    typename Queue<T>::Node* new_node = new typename Queue<T>::Node(value);
    if (!tail) {
        head = tail = new_node;
    }
    else {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }
    ++size;
}

// Pop function to remove the value from the front of the queue
template <typename T>
void Queue<T>::pop() {
    if (!head) {
        throw std::runtime_error("Queue is empty. Cannot pop.");
    }
    typename Queue<T>::Node* tmp = head;
    head =  head->next;
    if (head) {
        head->prev = nullptr;
    }
    else {
        tail = nullptr;
    }
    delete tmp;
    --size;
}

// Front function to access the value at the front of the queue
template <typename T>
typename Queue<T>::reference Queue<T>::front() {
    if (!head) {
        throw std::runtime_error("Queue is empty. Cannot access front.\n");
    }
    return head->data;
}

// Back function to access the value at the back of the queue
template <typename T>
typename Queue<T>::reference Queue<T>::back() {
    if (!tail) {
        throw std::runtime_error("Queue is empty. Cannot access back.\n");
    }
    return tail->data;
}

// Empty function to check if the queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return head == nullptr;
}

// Size function to get the current size of the queue
template <typename T>
typename Queue<T>::size_type Queue<T>::size_() const {
    return size;
}

// Push range function to add a range of elements from a given input iterator to the queue
template <typename T>
template <typename InputIt>
void Queue<T>::push_range(InputIt first, InputIt last) {
    for (; first != last; ++first) {
        push(*first);
    }
}

// Swap function to exchange the contents of the queue with another queue
template <typename T>
void Queue<T>::swap(Queue& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}

// Clear function to remove all nodes from the queue and reset size to 0
template <typename T>
void Queue<T>::clear() {
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    head = tail = nullptr;
    size = 0;
}

// Returns an iterator to the first element in the queue
template <typename T>
typename Queue<T>::iterator Queue<T>::begin() {
    return typename Queue<T>::iterator(head);
}

// Returns an iterator to the position just past the last element in the queue
template <typename T>
typename Queue<T>::iterator Queue<T>::end() {
    return typename Queue<T>::iterator(nullptr);
}

// Returns a constant iterator to the first element in the queue (read-only)
template <typename T>
typename Queue<T>::const_iterator Queue<T>::cbegin() const {
    return typename Queue<T>::const_iterator(head);
}

// Returns a constant iterator to the position just past the last element in the queue (read-only)
template <typename T>
typename Queue<T>::const_iterator Queue<T>::cend() const {
    return typename Queue<T>::const_iterator(nullptr);
}
