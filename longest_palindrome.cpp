#include "longest_palindrome.h"

#include <vector>

// Definition of the longestPalindrome function
std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";  // Edge case: if the string is empty, return an empty string
    int n = s.size();
    int start = 0, maxLength = 1;  // Start index and max length of the longest palindrome found

    // Function to expand around the center and find the longest palindrome
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; i++) {
        // Odd-length palindromes (single character center)
        expandAroundCenter(i, i);

        // Even-length palindromes (two character center)
        expandAroundCenter(i, i + 1);
    }

    return s.substr(start, maxLength);
}

std::string longest_palindrome(const std::string &s)
{
    int n = s.length();
    if(n == 0) return "";
    int start = 0, max_length = 1;
    std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));
    for(int i =0; i<n;i++) {
        dp[i][i] = true;
    }
    for(int i = 0; i< n-1;i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            max_length = 2;
        }
    }

    for(int len = 3; len< n+1;len++) {
        for(int i = 0; i < n- len+1;i++) {
            int j = i+len-1;
            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if(len > max_length) {
                    max_length = len;
                    start = i;
                }
            }
        }
    }

    return s.substr(start, max_length);

}
