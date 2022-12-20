// Laboration3, DT079G
// Amarildo Rajta
// p_queue.h, created 2022-12-03, edited 2022-12-09
#ifndef L3V0_01_P_QUEUE_H
#define L3V0_01_P_QUEUE_H

#include <vector>
//#include <list>
#include <functional>

template <typename T>
struct less {
    bool operator()(const T& a1, const T& a2) const {
        return a1 < a2;
    }
};

template <typename T, typename Compare=less<T>>
class p_queue {
public:
    // Constructor
    p_queue() = default;

    // Remove the highest-priority element from the priority queue.
    T pop() {
        T tempval = data.front();
        data.erase(data.begin());
        return tempval;
    }

    // Add a new element to the priority queue.
    void push(const T& e) {
        data.push_back(e);
        std::sort(data.begin(), data.end(), compare);
        /*auto it = std::find_if(data.begin(), data.end(), [&](const T& input){
            return compare(input, e);
        });
        data.insert(it, e);*/
    }

    // Return the first element in the priority queue.
    T begin() const {
        return data.begin();
    }

    // Return the last element in the priority queue.
    T end() const {
        return data.end();
    }

    // Return the number of elements in the priority queue.
    size_t size() const {
        return data.size();
    }

    // Return true if the priority queue is empty, false otherwise.
    bool empty() const {
        return data.empty();
    }
    // Return a reference to the highest-priority element in the priority queue.
    const T& top() const {
        return data.front();
    }


private:
    // Vector that stores the elements in the priority queue.
    std::vector<T> data;

    // Comparator used to order the elements in the priority queue.
    Compare compare;
};


#endif //L3V0_01_P_QUEUE_H
