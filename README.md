# Queue Implementation in C++

## Overview

This project presents a **custom doubly linked list-based queue** in C++. It includes a complete implementation of a queue data structure with support for both **mutable and constant iterators**, and provides essential queue operations such as **push**, **pop**, **front**, **back**, and more.

The queue is designed to be flexible, efficient, and easy to use, with iterator support for seamless traversal of the queue elements.

---

## Features

- **Doubly Linked List**: The queue is implemented using a doubly linked list, ensuring efficient insertion and deletion operations at both ends.
- **Iterators**: Custom iterators allow traversal of the queue, supporting both mutable and constant access to elements.
- **Push/Pop Operations**: Easily add elements to the back of the queue (`push`), and remove elements from the front (`pop`).
- **Front/Back Access**: Quickly access the front and back elements of the queue.
- **Range Insertion**: Insert a range of elements into the queue using `push_range`.
- **Queue Size**: Easily check the size of the queue with the `size` method.
- **Clear Method**: Efficiently clears the queue and frees allocated memory.
- **Swap**: Swap the contents of two queues with the `swap` method.

---

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
3. [Example](#example)
4. [Functionality](#functionality)

---

## Installation

To use this Queue implementation, you need to have a C++ compiler that supports **C++11** or higher. Clone this repository and include the necessary files in your project.

```bash
git clone https://github.com/mariammxitaryan/Queue.git Queue
```

---

## Usage

To use the custom `Queue` class, simply include the header file `queueHeader.hpp` and instantiate a queue with your desired type. 

### Example

```cpp
#include "queueHeader.hpp"
#include <iostream>

int main() {
    // Create a queue of integers
    Queue<int> q;

    // Push some values
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front and back of the queue
    std::cout << "Front: " << q.front() << std::endl;
    std::cout << "Back: " << q.back() << std::endl;

    // Pop an element from the queue
    q.pop();

    // Display the new front and back
    std::cout << "New Front: " << q.front() << std::endl;
    std::cout << "New Back: " << q.back() << std::endl;

    return 0;
}
```

---

## Functionality

### 1. **Push Operation**
```cpp
void push(const T& value);
```
- Adds a new element to the back of the queue.

### 2. **Pop Operation**
```cpp
void pop();
```
- Removes the element at the front of the queue.

### 3. **Front/Back Access**
```cpp
typename Queue<T>::reference front();
typename Queue<T>::reference back();
```
- Returns the front or back element of the queue.

### 4. **Size**
```cpp
typename Queue<T>::size_type size() const;
```
- Returns the current number of elements in the queue.

### 5. **Empty Check**
```cpp
bool empty() const;
```
- Returns `true` if the queue is empty, `false` otherwise.

### 6. **Clear Operation**
```cpp
void clear();
```
- Removes all elements from the queue and frees the allocated memory.

### 7. **Swap Operation**
```cpp
void swap(Queue& other);
```
- Swaps the contents of the current queue with another queue.

### 8. **Range Insertion**
```cpp
template <typename InputIt>
void push_range(InputIt first, InputIt last);
```
- Inserts a range of elements into the queue.

### 9. **Iterator Support**
```cpp
iterator begin();
iterator end();
const_iterator cbegin() const;
const_iterator cend() const;
```
- Provides iterators for traversing the queue, both mutable and constant.

---

## Acknowledgments

- **C++ Standard Library**: The Queue implementation is based on the C++ standard library’s data structures and iterators, with enhancements for a custom doubly linked list-based implementation.

---
