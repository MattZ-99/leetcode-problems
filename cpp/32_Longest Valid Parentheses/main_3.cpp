#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 6.8 MB, less than 89.91% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = longestValidParenthesesLeft(s);
        int right = longestValidParenthesesRight(s);
        return (left>right)?left:right;
    }
    int longestValidParenthesesLeft(string& s) {
        int left = 0, right = 0;
        int res = 0;
        int length = s.size();
        for(int i = 0; i < length; i++) {
            if(s[i] == '(') left++;
            else right++;
            if(left == right) res = (res > left * 2) ? res : left * 2;
            if(left < right) {left = 0; right = 0;}
        }
        return res;
    }
    int longestValidParenthesesRight(string& s) {
        int left = 0, right = 0;
        int res = 0;
        int length = s.size();
        for(int i=length-1; i>=0; i--) {
            if(s[i] == '(') left++;
            else right++;
            if(left == right) res = (res > left * 2) ? res : left * 2;
            if(left > right) {left = 0; right = 0;}
        }
        return res;
    }
};

int main() {
    string s = "";
    Solution solution;
    cout << solution.longestValidParentheses(s) << endl;

    return 0;
}