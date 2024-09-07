#ifndef PRODUCER_CONSUMER_H
#define PRODUCER_CONSUMER_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>

class ProducerConsumer {
private:
    std::queue<int> buffer;                    // Shared buffer (queue)
    const unsigned int bufferSize;             // Maximum size of the buffer
    std::mutex mtx;                            // Mutex for synchronization
    std::condition_variable cv;                // Condition variable for synchronization
    bool stop;                                 // Flag to stop the producer/consumer

public:
    ProducerConsumer(unsigned int size);       // Constructor to initialize buffer size and control flag
    void producer(int id);                     // Producer thread function
    void consumer(int id);                     // Consumer thread function
    void start(unsigned int numProducers, unsigned int numConsumers); // Function to start producers and consumers
};

#endif // PRODUCER_CONSUMER_H
