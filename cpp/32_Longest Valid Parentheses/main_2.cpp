#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime: 4 ms, faster than 80.73% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 7.4 MB, less than 21.82% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
    int longestValidParentheses(string s) {
        int length = s.size();
        if(length <= 1) return 0;
        vector<int> conuter(length, 0);
        int res = 0;
        for (int p = 1; p < length; p++) {
            if(s[p] == '(') continue;
            int start = p - 1 - conuter[p - 1];
            if(start < 0) continue;
            if(s[start] == '(') {
                if(start>0) conuter[p] += conuter[start-1];
                conuter[p] += (conuter[p - 1] + 2);
                res = (res>conuter[p])?res:conuter[p];
            }
        }
        return res;
    }
};

int main() {
    string s = "(()())";
    Solution solution;
    cout << solution.longestValidParentheses(s) << endl;

    return 0;
}