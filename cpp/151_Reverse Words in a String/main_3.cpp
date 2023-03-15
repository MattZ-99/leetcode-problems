/* 151. Reverse Words in a String
Medium

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces. */


// Runtime: 2 ms, faster than 96.26% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 7.1 MB, less than 91.68% of C++ online submissions for Reverse Words in a String.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string s_res;
        int idx_first = s.size() - 1, idx_second = s.size();

        while(idx_first >= -1) {
            if (idx_first == -1 || s[idx_first] == ' ') {
                if (idx_second - idx_first > 1) {
                    s_res.insert(s_res.end(), s.begin() + idx_first + 1, s.begin() + idx_second);
                    s_res.push_back(' ');
                }
                idx_second = idx_first;
            }
            idx_first--;
        }

        if (s_res.size() > 0) s_res.pop_back();
        return s_res;
    }
};


int main() { 
    // Inputs.
    string s =  "hello world  ";

    // Solution.
    Solution solution;
    string s_reverse_words = solution.reverseWords(s);
    cout << s_reverse_words << endl;

    return 0;
}