#include "longest_palindrome.h"

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
