#include <iostream>
#include <string>

using namespace std;

// Runtime: 196 ms, faster than 5.66% of C++ online submissions for Shortest Palindrome.
// Memory Usage: 6.9 MB, less than 96.41% of C++ online submissions for Shortest Palindrome.

class Solution {
public:
    string shortestPalindrome(string s) {
        int length = s.length();
        string res;
        if(length == 0) return res;
        int left, right;
        int p;
        for(p = length - 1; p >= 0; p--) {
            left = p/2; right = p%2 + left;
            if(checkValid(s, left, right)) break;
        }
        for(int i=length-1; i>p; i--) res.push_back(s[i]);
        res.append(s);
        return res;
    }
    bool checkValid(string& s, int left, int right) {
        while(left >= 0) {
            if(s[left] != s[right]) return 0;
            left--; right++;
        }
        return 1;
    }
};

int main() {
    string s = "aacecaaa";
    Solution solution;
    cout << solution.shortestPalindrome(s) << endl;

    return 0;
}