#ifndef BASIC_FILE_SYSTEM_H
#define BASIC_FILE_SYSTEM_H

#include <unordered_map>
#include <string>
#include <stdexcept> // For exception handling

class BasicFileSystem {
private:
    // Internal storage to represent the file system
    std::unordered_map<std::string, std::string> files;

public:
    // Creates a new file
    void createFile(const std::string& filename);

    // Deletes a file
    void deleteFile(const std::string& filename);

    // Reads the content of a file
    std::string readFile(const std::string& filename) const;

    // Writes content to a file
    void writeFile(const std::string& filename, const std::string& content);
};

#endif // BASIC_FILE_SYSTEM_H
