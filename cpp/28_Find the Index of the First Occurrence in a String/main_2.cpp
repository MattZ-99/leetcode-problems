/* 28. Find the Index of the First Occurrence in a String
Medium

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Index of the First Occurrence in a String.
// Memory Usage: 6.2 MB, less than 90.61% of C++ online submissions for Find the Index of the First Occurrence in a String.


#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Rabin-Karp (Rolling hash).
// TC: O(m+n)
// SC: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_needle = needle.length(), len_haystack = haystack.length();
        if (len_needle > haystack.length()) return -1;

        int hash_s = 0, hash_l = 0;
        int d = 29, q = 683303, power = 1;

        for (int i = 0; i < len_needle; i++) {
            hash_s = (hash_s * d + needle[i]) % q;
            hash_l = (hash_l * d + haystack[i]) % q; 
            if (i != 0) power = (power * d) % q;
        }

        for (int i = 0; i <= len_haystack - len_needle; i++) {
            if (hash_l < 0) hash_l += q;
            if (hash_l == hash_s && haystack.substr(i, len_needle) == needle) return i;
            
            hash_l = ((hash_l - power * haystack[i]) * d + haystack[i + len_needle]) % q;
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