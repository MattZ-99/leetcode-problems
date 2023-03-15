#include <iostream>
#include <string>

using namespace std;

// Runtime: 648 ms, faster than 5.05% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 7.5 MB, less than 15.26% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if(length <= 1) return 0;
        return ValidParenthesesKernel(s, 0, length);
    }

    int ValidParenthesesKernel(string& s, int left, int& length) {
        if(left > length-2) return 0;
        int sum = 0;
        int p = left;
        int res;
        while(p < length) {
            if(sum == 0) res = p;
            if(sum < 0) break;
            if(s[p] == '(') sum++;
            else sum--;
            p++;
        }
        if(sum == 0) res = p;
        res -= left;

        int next = ValidParenthesesKernel(s, left+1, length);
        res = (res>next)?res:next;
        return res;
    }
};

int main() {
    string s = "";
    Solution solution;
    cout << solution.longestValidParentheses(s) << endl;

    return 0;
}