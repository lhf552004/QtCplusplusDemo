#ifndef BASE_H
#define BASE_H

#include <iostream>

// Base class template using CRTP
template <typename Derived>
class Base {
public:
    void interface() {
        // Common interface code
        static_cast<Derived*>(this)->implementation();  // Call derived class implementation
    }

    // Default implementation in the base class
    void implementation() {
        std::cout << "Base implementation\n";
    }
};

// Derived class inheriting from CRTP base class
class Derived : public Base<Derived> {
public:
    // Override implementation
    void implementation() {
        std::cout << "Derived implementation\n";
    }
};

#endif // BASE_H
