#include "mystring.h"

// Default constructor
MyString::MyString() : str(new char[1]), len(0) {
    str[0] = '\0'; // Initialize with an empty string
}

// Constructor from C-string
MyString::MyString(const char* s) {
    if (s) {
        len = std::strlen(s);          // Get length of the C-string
        str = new char[len + 1];       // Allocate memory for the string
        std::strcpy(str, s);           // Copy the C-string into the dynamically allocated memory
    } else {
        str = new char[1];
        str[0] = '\0';
        len = 0;
    }
}

// Copy constructor (deep copy)
MyString::MyString(const MyString& other) : len(other.len) {
    str = new char[len + 1];          // Allocate memory for the string
    std::strcpy(str, other.str);      // Copy the string from the source object
}

// Destructor
MyString::~MyString() {
    delete[] str; // Free the dynamically allocated memory
}

// Assignment operator (deep copy)
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) { // Avoid self-assignment
        delete[] str; // Free the existing memory
        len = other.len;
        str = new char[len + 1]; // Allocate new memory
        std::strcpy(str, other.str); // Copy the string from the source object
    }
    return *this;
}

// Concatenation operator
MyString MyString::operator+(const MyString& other) const {
    size_t newLen = len + other.len;
    char* newStr = new char[newLen + 1];

    std::strcpy(newStr, str);          // Copy the first string
    std::strcat(newStr, other.str);    // Concatenate the second string

    MyString result(newStr);
    delete[] newStr; // Free the temporary memory
    return result;
}

// Comparison operator
bool MyString::operator==(const MyString& other) const {
    return std::strcmp(str, other.str) == 0;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const MyString& s) {
    os << s.str;
    return os;
}

// Get the length of the string
size_t MyString::length() const {
    return len;
}

// Extract substring
MyString MyString::substring(size_t start, size_t length) const {
    if (start >= len) {
        return MyString(); // Return empty string if start is out of range
    }

    size_t end = std::min(start + length, len);
    size_t newLen = end - start;

    char* subStr = new char[newLen + 1];
    std::strncpy(subStr, str + start, newLen);
    subStr[newLen] = '\0';

    MyString result(subStr);
    delete[] subStr; // Free the temporary memory
    return result;
}
