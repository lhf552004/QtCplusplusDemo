#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <optional> // For std::optional (C++17)

template <typename T>
class ThreadSafeQueue {
private:
    std::queue<T> queue_;                // Standard queue to store the elements
    mutable std::mutex mtx_;             // Mutex for synchronizing access
    std::condition_variable cond_var_;   // Condition variable for coordination

public:
    // Constructor
    ThreadSafeQueue() = default;

    // Disable copying and assignment to ensure safety
    ThreadSafeQueue(const ThreadSafeQueue&) = delete;
    ThreadSafeQueue& operator=(const ThreadSafeQueue&) = delete;

    // Adds an element to the back of the queue
    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx_); // Lock the mutex
        queue_.push(std::move(value));          // Add the element
        cond_var_.notify_one();                 // Notify one waiting thread, if any
    }

    // Tries to remove an element from the front of the queue
    bool try_pop(T& value) {
        std::lock_guard<std::mutex> lock(mtx_); // Lock the mutex
        if (queue_.empty()) {
            return false; // Queue is empty, nothing to pop
        }
        value = std::move(queue_.front()); // Move the front element to value
        queue_.pop(); // Remove the front element
        return true;
    }

    // Waits until an element is available and removes it from the front
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lock(mtx_); // Lock the mutex
        cond_var_.wait(lock, [this] { return !queue_.empty(); }); // Wait until the queue is not empty
        value = std::move(queue_.front()); // Move the front element to value
        queue_.pop(); // Remove the front element
    }

    // Checks if the queue is empty
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx_); // Lock the mutex
        return queue_.empty();
    }
};
