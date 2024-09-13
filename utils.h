#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "treenode.h"

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
};

#endif // UTILS_H
