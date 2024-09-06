#include "singletondemo.h"
#include <iostream>

// Initialize the static members
SingletonDemo* SingletonDemo::instance = nullptr;
std::mutex SingletonDemo::mutex;

SingletonDemo::SingletonDemo()
{
    std::cout << "Singleton instance created." << std::endl;
}

SingletonDemo* SingletonDemo::getInstance()
{
    if (instance == nullptr) // First check without locking for performance
    {
        std::lock_guard<std::mutex> lock(mutex); // Lock to ensure thread safety
        if (instance == nullptr) // Double-check locking
        {
            instance = new SingletonDemo();
        }
    }
    return instance;
}
