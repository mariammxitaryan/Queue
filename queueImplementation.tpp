#include "queueHeader.hpp"

template <typename T>
Queue<T>::Node::Node(const T& value) : data(value), next(nullptr), prev(nullptr) { }

template <typename T>
Queue<T>::iterator::iterator(typename Queue<T>::Node* ptr) : node_ptr(ptr) { }

template <typename T>
typename Queue<T>::iterator::reference Queue<T>::iterator::operator*() const {
    return node_ptr->data;
}

template <typename T>
typename Queue<T>::iterator::pointer Queue<T>::iterator::operator->() const {
    return &node_ptr->data;
}

template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

template <typename T>
typename Queue<T>::iterator& Queue<T>::iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator++(int) {
    typename Queue<T>::iterator it = *this;
    node_ptr = node_ptr->next;
    return it;
}

template <typename T>
typename Queue<T>::iterator Queue<T>::iterator::operator--(int) {
    typename Queue<T>::iterator it = *this;
    node_ptr = node_ptr->prev;
    return it;
}

template <typename T>
bool Queue<T>::iterator::operator==(const typename Queue<T>::iterator& other) const {
    return node_ptr == other.node_ptr;
}

template <typename T>
bool Queue<T>::iterator::operator!=(const typename Queue<T>::iterator& other) const {
    return node_ptr != other.node_ptr;
}

template <typename T>
Queue<T>::const_iterator::const_iterator(typename Queue<T>::Node* ptr) : node_ptr(ptr) { }

template <typename T>
typename Queue<T>::const_iterator::reference Queue<T>::const_iterator::operator*() const {
    return node_ptr->data;
}

template <typename T>
typename Queue<T>::const_iterator::pointer Queue<T>::const_iterator::operator->() const {
    return &node_ptr->data;
}

template <typename T>
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator++() {
    node_ptr = node_ptr->next;
    return *this;
}

template <typename T>
typename Queue<T>::const_iterator& Queue<T>::const_iterator::operator--() {
    node_ptr = node_ptr->prev;
    return *this;
}

template <typename T>
typename Queue<T>::const_iterator Queue<T>::const_iterator::operator++(int) {
    typename Queue<T>::const_iterator it = *this;
    node_ptr = node_ptr->next;
    return it;
}

template <typename T>
typename Queue<T>::const_iterator Queue<T>::const_iterator::operator--(int) {
    typename Queue<T>::const_iterator it = *this;
    node_ptr = node_ptr->prev;
    return it;
}

template <typename T>
bool Queue<T>::const_iterator::operator==(typename Queue<T>::const_iterator& other) const {
    return node_ptr == other.node_ptr;
}

template <typename T>
bool Queue<T>::const_iterator::operator!=(const typename Queue<T>::const_iteratorconst_iterator& other) const {
    return node_ptr != other.node_ptr;
}

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() {
    clear();
}

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

template <typename T>
typename Queue<T>::reference Queue<T>::front() {
    if (!head) {
        throw std::runtime_error("Queue is empty. Cannot access front.\n");
    }
    return head->data;
}

template <typename T>
typename Queue<T>::reference Queue<T>::back() {
    if (!tail) {
        throw std::runtime_error("Queue is empty. Cannot access back.\n");
    }
    return tail->data;
}

template <typename T>
bool Queue<T>::empty() const {
    return head == nullptr;
}

template <typename T>
typename Queue<T>::size_type Queue<T>::size_() const {
    return size;
}

template <typename T>
template <typename InputIt>
void Queue<T>::push_range(InputIt first, InputIt last) {
    for (; first != last; ++first) {
        push(*first);
    }
}

template <typename T>
void Queue<T>::swap(Queue& other) {
    std::swap(head, other.head);
    std::swap(tail, other.tail);
    std::swap(size, other.size);
}

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

template <typename T>
typename Queue<T>::iterator Queue<T>::begin() const {
    return typename Queue<T>::iterator(head);
}

template <typename T>
typename Queue<T>::iterator Queue<T>::end() const {
    return typename Queue<T>::iterator(nullptr);
}

template <typename T>
typename Queue<T>::const_iterator Queue<T>::cbegin() const {
    return typename Queue<T>::const_iterator(head);
}

template <typename T>
typename Queue<T>::const_iterator Queue<T>::cend() const {
    return typename Queue<T>::const_iterator(nullptr);
}

