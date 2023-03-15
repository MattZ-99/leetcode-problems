#include <iostream>
#include <string>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Valid Number.
// Memory Usage: 5.8 MB, less than 97.61% of C++ online submissions for Valid Number.

class Solution {
public:
    bool isNumber(string s) {
        int sLength = s.length();
        bool result = 0, sign_check = 1, dot_check = 1, e_check = 0, e_check_num = 1;
        for (int i=0; i<sLength; i++) {
            char c = s[i];
            if(signCheck(c)) {
                if(sign_check) {
                    result = 0; sign_check = 0; continue;
                }
                return 0;
            }
            if(dotCheck(c)) {
                if(dot_check) {
                    dot_check = 0; sign_check = 0; continue;
                }
                return 0;
            }
            if(digitCheck(c)) {
                result = 1; sign_check = 0; e_check = 1; continue;
            }
            if(eCheck(c) && e_check_num && e_check) {
                result = 0; dot_check = 0; sign_check = 1; e_check = 0; e_check_num = 0;
                continue;
            }
            return 0;
        }
        return result;
    }

    bool signCheck(char c) { return !((c-'+')&&(c-'-')); }
    bool dotCheck(char c) { return !((c-'.')); }
    bool eCheck(char c) {return !((c-'e')&&(c-'E')); }
    bool digitCheck(char c) {
        if(c-'0' >= 0 && c-'0' <= 9) return 1;
        return 0;
    }
};

int main() {
    string s = "92e1740e91";
    Solution solution;
    cout << solution.isNumber(s) << endl;

    return 0;
}