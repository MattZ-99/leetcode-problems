/* 541. Reverse String II
Easy

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original. */

// Runtime: 7 ms, faster than 71.91% of C++ online submissions for Reverse String II.
// Memory Usage: 7.2 MB, less than 71.42% of C++ online submissions for Reverse String II.

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            if (i + k < s.size()) reverse(s.begin() + i, s.begin() + i + k);
            else reverse(s.begin() + i, s.end());
        }
        return s;
    }
};

int main() {
    // Inputs.
    string s = "abcd";
    int k = 4;

    // Solution.
    Solution solution;
    string s_reverse = solution.reverseStr(s, k);
    cout << s_reverse << endl;

    return 0;
}