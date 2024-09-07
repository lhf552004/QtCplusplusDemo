#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream> // For std::ostream
#include <cstring>  // For strlen, strcpy, etc.

class MyString {
private:
    char* str;           // Pointer to the dynamically allocated character array
    size_t len;          // Length of the string (not including null terminator)

public:
    // Constructors
    MyString(); // Default constructor
    MyString(const char* s); // Constructor from C-string
    MyString(const MyString& other); // Copy constructor

    // Destructor
    ~MyString();

    // Assignment operator
    MyString& operator=(const MyString& other);

    // Concatenation operator
    MyString operator+(const MyString& other) const;

    // Comparison operator
    bool operator==(const MyString& other) const;

    // Output stream operator
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);

    // Member functions
    size_t length() const;          // Get the length of the string
    MyString substring(size_t start, size_t length) const; // Extract substring
};

#endif // MYSTRING_H
