#include "producer_consumer.h"
#include <chrono> // For std::chrono::milliseconds

// Constructor to initialize buffer size and control flag
ProducerConsumer::ProducerConsumer(unsigned int size) : bufferSize(size), stop(false) {}

// Producer thread function
void ProducerConsumer::producer(int id) {
    while (!stop) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some delay

        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex for synchronization

        cv.wait(lock, [this]() { return buffer.size() < bufferSize || stop; }); // Wait until there is space in the buffer

        if (stop) break; // Exit if stop flag is set

        int data = rand() % 100; // Generate random data
        buffer.push(data);        // Add data to the buffer
        std::cout << "Producer " << id << " produced: " << data << std::endl;

        cv.notify_all(); // Notify consumer threads
    }
}

// Consumer thread function
void ProducerConsumer::consumer(int id) {
    while (!stop) {
        std::unique_lock<std::mutex> lock(mtx); // Lock the mutex for synchronization

        cv.wait(lock, [this]() { return !buffer.empty() || stop; }); // Wait until there is data in the buffer

        if (stop && buffer.empty()) break; // Exit if stop flag is set and buffer is empty

        int data = buffer.front(); // Get data from the buffer
        buffer.pop();              // Remove data from the buffer
        std::cout << "Consumer " << id << " consumed: " << data << std::endl;

        cv.notify_all(); // Notify producer threads

        lock.unlock(); // Unlock the mutex before processing the data
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // Simulate processing delay
    }
}

// Function to start producers and consumers
void ProducerConsumer::start(unsigned int numProducers, unsigned int numConsumers) {
    std::vector<std::thread> producers, consumers;

    // Create producer threads
    for (unsigned int i = 0; i < numProducers; ++i) {
        producers.push_back(std::thread(&ProducerConsumer::producer, this, i + 1));
    }

    // Create consumer threads
    for (unsigned int i = 0; i < numConsumers; ++i) {
        consumers.push_back(std::thread(&ProducerConsumer::consumer, this, i + 1));
    }

    // Let the threads run for some time
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Set the stop flag and notify all threads
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
        cv.notify_all();
    }

    // Wait for all threads to finish
    for (auto& p : producers) p.join();
    for (auto& c : consumers) c.join();
}
