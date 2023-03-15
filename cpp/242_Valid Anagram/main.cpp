/* 242. Valid Anagram
Easy

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. */

// Runtime: 10 ms, faster than 83.60% of C++ online submissions for Valid Anagram.
// Memory Usage: 7.3 MB, less than 56.28% of C++ online submissions for Valid Anagram.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if (len_s != len_t) return false; 

        vector<int> freq (26, 0);
        for (auto c: s) freq[c - 'a'] ++;
        for (auto c: t) 
            if (--freq[c - 'a'] < 0) return false;
        return true;
    }
};

int main() {
    // Inputs.
    // string s = "anagram", t = "nagaram";
    string s, t;
    cout << "Input first word s: "; cin >> s;
    cout << "Input second word t: "; cin >> t;
    cout << "--------------------" << endl;

    cout << "String s = " << s << endl;
    cout << "String t = " << t << endl;

    // Solution.
    Solution solution;
    cout << "Is Anagram:" << solution.isAnagram(s, t) << endl;

    return 0;
}