#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <vector>
#include "treenode.h"
using namespace std;

class Utils
{
public:
    Utils();

    void readFiles(std::string file1);
    double celsiusToFahrenheit(double celsius);
    bool isPalinedrome(const std::string& s);
    std::string reverseWords(const std::string& s);
    void mirror(TreeNode* root);
    std::vector<std::string> generatePermutations(const std::string& s);
    std::string serialize(TreeNode* root);
    TreeNode* deserialize(std::string result);
    void printTree(TreeNode* root);
    std::string intToRoman(int num);
    std::string longestCommonPrefix(vector<string>& strs);
};

#endif // UTILS_H
