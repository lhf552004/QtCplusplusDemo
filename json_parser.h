#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp> // Include the nlohmann/json library

using json = nlohmann::json; // Alias for the JSON library

class JsonParser {
public:
    // Method to read and parse JSON from a file
    static json readJsonFromFile(const std::string& filename);

    // Method to handle JSON data
    static void handleJson(const json& j);
};

#endif // JSON_PARSER_H
