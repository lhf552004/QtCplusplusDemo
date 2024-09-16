#include "zigzag.h"

#include <vector>

Zigzag::Zigzag()
{

}

std::string Zigzag::convert(std::string s, int numRows)
{
    if(numRows == 1) return s;
    std::string result;
    try {
        std::vector<std::string> rows(std::min(numRows, (int)s.size()));

        int curRow = 0;
        bool goingDown = false;

        for(auto &ch : s) {
            rows[curRow] += ch;
            if(curRow == 0 || curRow == numRows +1) {
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1: -1;
        }

        for(const std::string& row: rows) {
            result += row;
        }
    }  catch (int myNum) {
        std::cout << "Access denied - You must be at least 18 years old.\n";
    }



    return result;
}
