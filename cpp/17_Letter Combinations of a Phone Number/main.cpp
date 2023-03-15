#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 6.5 MB, less than 62.49% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int digits_length = digits.size(); 
        if (digits_length == 0) {vector<string> result; return result;}

        vector<string> result = digit2char(digits[0]);

        for (int i = 1; i < digits_length; i++) {
            vector<string> tmp = digit2char(digits[i]);
            vector<string> newRes;

            for (int m = 0; m < result.size(); m++) 
                for (int n = 0; n < tmp.size(); n++) newRes.push_back(result[m] + tmp[n]);
            result = newRes;
        }
        return result;
    }   
    vector<string> digit2char(char digit) {
        vector<string> result;
        int val = digit - '0';
        if(val < 2 || val > 9) return result;
        char begin = (val - 2) * 3 + 'a';
        if(val > 7) begin++;
        for (int i = 0; i < 3; i++) {
            string s_begin(1,begin);
            result.push_back(s_begin);
            begin++;
        }
        if (val == 9 || val == 7) {string s_begin(1,begin); result.push_back(s_begin);}
        return result;
    }
};

int main() {
    string digits = "8";
    Solution solution;
    vector<string> result = solution.letterCombinations(digits);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}