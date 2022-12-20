//
// Created by amari on 2022-12-08.
//
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class PriorityQueue {
public:
    // Inserts an element into the priority queue
    void push(const T& elem) {
        data.push_back(elem);
        std::push_heap(data.begin(), data.end());
    }

    // Removes the top element from the priority queue
    void pop() {
        std::pop_heap(data.begin(), data.end());
        data.pop_back();
    }

    // Returns the top element in the priority queue
    const T& top() const {
        return data.front();
    }

    // Returns true if the priority queue is empty, false otherwise
    bool empty() const {
        return data.empty();
    }

    // Returns the number of elements in the priority queue
    size_t size() const {
        return data.size();
    }

private:
    std::vector<T> data;
};