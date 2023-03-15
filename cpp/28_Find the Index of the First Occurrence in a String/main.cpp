/* 28. Find the Index of the First Occurrence in a String
Medium

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Index of the First Occurrence in a String.
// Memory Usage: 6.3 MB, less than 28.04% of C++ online submissions for Find the Index of the First Occurrence in a String.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP algorithm.
// TC: O(m+n)
// SC: O(m)
class Solution {
    vector<int> get_the_prefix_function(string & s) {
        int s_len = s.length(), j=0;
        vector<int> next(s_len, 0);

        for (int i=1; i<s_len; i++) {
            while (j > 0 && s[i] != s[j]) j = next[j-1];
            if (s[i] == s[j]) j++;
            next[i] = j;
        }
        return next;
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.length() > haystack.length()) return -1;

        vector<int> next = get_the_prefix_function(needle);

        int j = 0;
        for (int i=0; i < haystack.length(); i++) {
            while(j > 0 && haystack[i] != needle[j]) j = next[j - 1];
            if (haystack[i] == needle[j]) j++;

            if (j == needle.length()) return i - j + 1;
        }
        return -1;
    }
};

int main() {
    // Inputs.
    string haystack = "sadbutsad", needle = "sad";

    // Solution.
    Solution solution;
    cout << solution.strStr(haystack, needle) << endl;


    return 0;
}