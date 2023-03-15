/* 541. Reverse String II
Easy

Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.

If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original. */

// Runtime: 18 ms, faster than 10.17% of C++ online submissions for Reverse String II.
// Memory Usage: 7.6 MB, less than 13.40% of C++ online submissions for Reverse String II.

#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Solution {
    void _string_copy(string::iterator it_first, string::iterator it_second, string & s, int i) {
        if (i % 2 == 0) copy(make_reverse_iterator(it_second), make_reverse_iterator(it_first), back_inserter(s));
        else copy(it_first, it_second, back_inserter(s));
    }

public:
    string reverseStr(string s, int k) {
        int block_num = s.length() / k, i=0;
        string s_reverse;
        string::iterator it_first, it_second;

        for (i = 0; i < block_num; i++) {
            it_first = s.begin() + i * k;
            it_second = it_first + k;
            _string_copy(it_first, it_second, s_reverse, i);
        }

        it_first = s.begin() + block_num * k;
        it_second = s.end();
        _string_copy(it_first, it_second, s_reverse, block_num);

        return s_reverse;
    }
};

int main() {
    // Inputs.
    string s = "abcdefg";
    int k = 2;

    // Solution.
    Solution solution;
    string s_reverse = solution.reverseStr(s, k);
    cout << s_reverse << endl;

    return 0;
}