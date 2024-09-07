#include "basic_file_system.h"

// Creates a new file with the given filename
void BasicFileSystem::createFile(const std::string& filename) {
    if (files.find(filename) != files.end()) {
        throw std::runtime_error("File already exists: " + filename);
    }
    files[filename] = ""; // Initialize the file with empty content
}

// Deletes a file with the given filename
void BasicFileSystem::deleteFile(const std::string& filename) {
    if (files.find(filename) == files.end()) {
        throw std::runtime_error("File not found: " + filename);
    }
    files.erase(filename);
}

// Reads the content of a file with the given filename
std::string BasicFileSystem::readFile(const std::string& filename) const {
    auto it = files.find(filename);
    if (it == files.end()) {
        throw std::runtime_error("File not found: " + filename);
    }
    return it->second; // Return the content of the file
}

// Writes content to a file with the given filename
void BasicFileSystem::writeFile(const std::string& filename, const std::string& content) {
    if (files.find(filename) == files.end()) {
        throw std::runtime_error("File not found: " + filename);
    }
    files[filename] = content; // Write content to the file
}
