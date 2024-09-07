#ifndef INVALID_ARGUMENT_EXCEPTION_H
#define INVALID_ARGUMENT_EXCEPTION_H

#include <exception>  // Include the base exception class
#include <string>     // Include the string class for error messages

// Custom exception class inheriting from std::exception
class InvalidArgumentException : public std::exception {
private:
    std::string message; // Store the error message

public:
    // Constructor that takes an error message
    explicit InvalidArgumentException(const std::string& msg) : message(msg) {}

    // Override the what() method from std::exception
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif // INVALID_ARGUMENT_EXCEPTION_H
