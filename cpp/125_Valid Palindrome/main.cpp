#include <iostream>
#include <string>

using namespace std;

// Runtime: 4 ms, faster than 94.53% of C++ online submissions for Valid Palindrome.
// Memory Usage: 7.3 MB, less than 76.64% of C++ online submissions for Valid Palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        string::iterator left = s.begin(), right = s.end() - 1;
        while(left < right) {
            if(!isalnum(*left)) {left++; continue;}
            if(!isalnum(*right)) {right--; continue;}
            if(tolower(*left) != tolower(*right)) return 0;
            left++; right--;
        }
        return 1;
    }
};

int main() {
    string s = "race a car";
    Solution solution;
    cout << solution.isPalindrome(s) << endl;
    return 0;
}