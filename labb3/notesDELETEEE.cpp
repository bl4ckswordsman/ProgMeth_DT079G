//
// Created by amari on 2022-12-08.
//

#include <iostream>
#include <functional>
#include <vector>

using namespace std;

// Define a custom Less comparator that compares two elements of type T
// and returns true if the first element is less than the second element,
// false otherwise.
template <typename T>
struct Less {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

// Define a template for a priority queue that stores elements of type T
// and uses a comparator to order the elements.
template <typename T, typename Compare = Less<T>>
class PriorityQueue {
public:
    // Constructor
    PriorityQueue() {}

    // Add a new element to the priority queue.
    void push(const T& elem) {
        data_.push_back(elem);
        push_heap(data_.begin(), data_.end(), compare_);
    }

    // Remove the highest-priority element from the priority queue.
    void pop() {
        pop_heap(data_.begin(), data_.end(), compare_);
        data_.pop_back();
    }

    // Return a reference to the highest-priority element in the priority queue.
    const T& top() const {
        return data_.front();
    }

    // Return the number of elements in the priority queue.
    size_t size() const {
        return data_.size();
    }

    // Return true if the priority queue is empty, false otherwise.
    bool empty() const {
        return data_.empty();
    }

private:
    // Vector that stores the elements in the priority queue.
    vector<T> data_;

    // Comparator used to order the elements in the priority queue.
    Compare compare_;
};

int main() {
    // Create a priority queue that stores integers and orders them in ascending order.
    PriorityQueue<int> pq;

    // Add some elements to the priority queue.
    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(4);
    pq.push(2);

    // Print the elements in the priority queue.
    cout << "Priority queue: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}