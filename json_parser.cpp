#include "json_parser.h"

// Method to read and parse JSON from a file
json JsonParser::readJsonFromFile(const std::string& filename) {
    std::ifstream file(filename); // Open the JSON file
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    json j;
    try {
        file >> j; // Parse JSON from the file
    } catch (const json::parse_error& e) {
        throw std::runtime_error("JSON parse error: " + std::string(e.what()));
    }

    return j; // Return the parsed JSON object
}

// Method to handle JSON data
void JsonParser::handleJson(const json& j) {
    try {
        // Access JSON data with error handling
        std::string name = j.at("name").get<std::string>();
        int age = j.at("age").get<int>();
        bool is_student = j.at("is_student").get<bool>();
        std::vector<std::string> skills = j.at("skills").get<std::vector<std::string>>();

        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Is Student: " << (is_student ? "Yes" : "No") << "\n";
        std::cout << "Skills: ";
        for (const auto& skill : skills) {
            std::cout << skill << " ";
        }
        std::cout << "\n";

        // Access nested JSON object
        json address = j.at("address");
        std::string street = address.at("street").get<std::string>();
        std::string city = address.at("city").get<std::string>();
        std::string zip = address.at("zip").get<std::string>();

        std::cout << "Address: " << street << ", " << city << ", " << zip << "\n";
    } catch (const json::out_of_range& e) {
        std::cerr << "JSON key error: " << e.what() << std::endl;
    } catch (const json::type_error& e) {
        std::cerr << "JSON type error: " << e.what() << std::endl;
    }
}
