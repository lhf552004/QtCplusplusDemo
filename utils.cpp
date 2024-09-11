#include "utils.h"

#include <map>
#include <algorithm>
#include <cctype>


Utils::Utils()
{

}
// Function to convert a string to lowercase
std::string toLowerCase(const std::string& word) {
    std::string result = word;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

// Function to check if a character is punctuation
bool isPunctuation(char c) {
    return std::ispunct(static_cast<unsigned char>(c));
}

// Function to remove punctuation from a word
std::string removePunctuation(const std::string& word) {
    std::string result;
    std::remove_copy_if(word.begin(), word.end(), std::back_inserter(result), isPunctuation);
    return result;
}
void Utils::readFiles(std::string file1)
{
    std::ifstream inputFile(file1);
    if (!inputFile.is_open()) {  // Check if the file was successfully opened
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    std::map<std::string, int> wordCount;
    std::string word;

    while (inputFile >> word) {
        // Convert word to lowercase and remove punctuation
        word = toLowerCase(removePunctuation(word));
        if (!word.empty()) {
            wordCount[word]++;
        }
    }
    std::ofstream outputFile("output.txt");
    for (const auto& pair : wordCount) {
        outputFile << pair.first << ": " << pair.second << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return;
}

double Utils::celsiusToFahrenheit(double celsius)
{
    return celsius* (9/5) +32;
}
