#include "zigzag.h"

#include <vector>

Zigzag::Zigzag()
{

}

std::string Zigzag::convert(std::string s, int numRows)
{
    if (numRows == 1) return s;

    // Initialize an array of strings for each row
    std::vector<std::string> rows(std::min(numRows, (int)s.size()));
    int curRow = 0;
    bool goingDown = false;

    // Traverse the string characters
    for (char ch : s) {
        rows[curRow] += ch;
        if (curRow == 0 || curRow == numRows - 1) {
            goingDown = !goingDown;
        }
        curRow += goingDown ? 1 : -1;
    }

    // Combine all rows to form the final zigzag string
    std::string result;
    for (const std::string& row : rows) {
        result += row;
    }

    return result;
}
