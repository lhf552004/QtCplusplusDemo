#include "atoi.h"
#include <limits.h>
Atoi::Atoi()
{

}

int Atoi::myAtoi(std::string s)
{
    long result = 0;
    bool isSignedFound = false;
    bool isDigitalStarted = false;
    int sign = 1;
    for(char ch : s) {
        if(isDigitalStarted) {
            if(isdigit(ch)) {
                int ditgal = ch - '0';
                result = result * 10 + ditgal;
            }else {
                break;
            }
        }else {
            if(ch == ' ') continue;

            if(ch == '-') {
                sign = -1;
            }else if(isdigit(ch)) {
                isDigitalStarted = true;
                result = ch - '0';
            }else {
                break;
            }
        }

    }
    result = result * sign;
    if(result > INT_MAX) {
        return INT_MAX;
    }
    if (result < INT_MIN) {
        return INT_MIN;
    }
    return static_cast<int>(result);
}
