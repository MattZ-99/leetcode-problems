/* 151. Reverse Words in a String
Medium

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces. */


// Reverse words in place.
// Runtime: 4 ms, faster than 90.44% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 7 MB, less than 96.82% of C++ online submissions for Reverse Words in a String.


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    void removeExtraSpaces_v1(string & s) {
        for (int i = s.length() - 1; i > 0; i--) {
            if (s[i] == ' ' && s[i-1] == ' ') s.erase(i, 1);
        }
        if (*(s.end() - 1) == ' ') s.pop_back();
        if (*(s.begin()) == ' ') s.erase(s.begin());
    }

    void removeExtraSpaces_v2(string & s) {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

public:
    string reverseWords(string s) {
        // Move redundant space.
        // removeExtraSpaces_v1(s);
        removeExtraSpaces_v2(s);

        // Reverse the string.
        reverse(s.begin(), s.end());

        // Reverse each word, respectively.
        int first = 0, second = 0;
        for (; second <= s.length(); second++) {
            if (second == s.length() || s[second] == ' ') {
                reverse(s.begin() + first, s.begin() + second);
                first = second + 1;
            }
        }
        return s;
    }
};


int main() { 
    // Inputs.
    // string s =  "hello world  ";
    string s = "the sky is blue";

    // Solution.
    Solution solution;
    string s_reverse_words = solution.reverseWords(s);
    cout << s_reverse_words << endl;

    return 0;
}