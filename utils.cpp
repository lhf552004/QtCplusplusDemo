#include "utils.h"

#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <functional>

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

bool Utils::isPalinedrome(const std::string &s)
{
    int left = 0;
    int right = s.length() -1;
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}


std::vector<std::string> splitStringBySpace(const std::string &str) {
    std::istringstream iss(str);  // Initialize a string stream with the input string
    std::vector<std::string> result; // Vector to store the split parts
    std::string word;

    while (iss >> word) {  // Read each word separated by spaces
        result.push_back(word);  // Add the word to the result vector
    }

    return result;
}

std::string Utils::reverseWords(const std::string &s)
{
    std::vector<std::string> words = splitStringBySpace(s);
    std::reverse(words.begin(), words.end());
    std::ostringstream reversedStream;
    for (size_t i = 0; i < words.size(); ++i) {
        if (i > 0) {
            reversedStream << " "; // Add a space between words
        }
        reversedStream << words[i];
    }
    return reversedStream.str();
}

void Utils::mirror(TreeNode *root)
{

}

std::string Utils::serialize(TreeNode *root)
{

    if(root == nullptr) {
       return "#";
    }
    std::queue<TreeNode*> queue;
    std::string result;
    queue.push(root);
    while(!queue.empty()) {
        TreeNode* node = queue.front();
        queue.pop();
        if(node!=nullptr) {
             result += std::to_string(node->key) + ",";
             queue.push(node->left);
             queue.push(node->right);
        }else {
            result += "#,";
        }
    }
    // Remove the trailing comma
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

TreeNode *Utils::deserialize(std::string data)
{
    if(data == "#") return nullptr;
    std::stringstream ss(data);
    std::string item;
    std::getline(ss, item, ',');
    TreeNode* root = new TreeNode(std::stoi(item));
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // Left
        if(std::getline(ss, item, ',')){
            if(item != "null") {
                node->left = new TreeNode(std::stoi(item));
                q.push(node->left);
            }
        }

        if(std::getline(ss, item, ',')){
            if(item != "null") {
                node->right = new TreeNode(std::stoi(item));
                q.push(node->right);
            }
        }
    }
    return root;
}

void Utils::printTree(TreeNode *root)
{
    if(!root) return;
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(node) {
            std::cout << node->key << " ";
            q.push(root->left);
            q.push(root->right);
        }else {
            std::cout << "null";
        }
    }
    std::cout << std::endl;
}

std::vector<std::string> Utils::generatePermutations(const std::string &s)
{

}


std::vector<std::string> Utils::generatePermutations(const std::string &s)
{
   std::vector<std::string> result;
   std::string current = s;
   std::sort(current.begin(), current.end());
   std::vector<bool> used(s.size(), false);
   std::string temp;
   std::function<void()> backtrack = [&]() {
        if(temp.size() == s.size()) {
            result.push_back(temp);
            return;
        }
        for(int i =0; i < s.size(); ++i) {
            if(used[i]) continue;
            if(i > 0 && current[i] == current[i-1] && !used[i-1]) continue;
            used[i] = true;
            temp.push_back(current[i]);
            backtrack();
            temp.pop_back();
            used[i] = false;
        }
   };
   backtrack();
   return result;
}
