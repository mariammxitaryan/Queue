#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <iterator>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T&);
    };
    Node* head;
    Node* tail;
    size_t size;
public:
    using value_type = T;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    class iterator {
    public:
        using iterator_cathegory  = std::bidirectional_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;
        using pointer = T*;
        using reference = T&;

        iterator(Node*);
        reference operator*() const;
        pointer operator->() const;
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;

    private:
        Node* node_ptr;
    };

    class const_iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type = const T;
        using difference_type = std::ptrdiff_t;
        using pointer = const T*;
        using reference = const T&;

        const_iterator(Node*);

        reference operator*() const;
        pointer operator->() const;
        const_iterator& operator++();
        const_iterator& operator--();
        const_iterator operator++(int);
        const_iterator operator--(int);
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
    private:
        Node* node_ptr;
    };

    Queue();
    ~Queue();
    void push(const T&);
    void pop();
    reference front();
    reference back();
    bool empty() const;
    size_type size_() const;

    template <typename InputIt>
    void push_range(InputIt, InputIt);
    
    void swap(Queue&);
    void clear();
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
};

#include "queueImplementation.tpp"

#endif