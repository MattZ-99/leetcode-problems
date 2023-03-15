#include <iostream>
#include <string>

using namespace std;

// Runtime: 12 ms, faster than 19.20% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 7 MB, less than 77.62% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int length = s.size();
        int left = 0, right = 0;
        while (true) {
            if(right == length) {stringInsertWord(s, res, left, right); break;}
            if(s[right] == ' ') {
                stringInsertWord(s, res, left, right); 
                left = right + 1;
            }
            right++;
        }
        res.erase(res.begin());
        return res;
    }
    void stringInsertWord(string& s, string& res, int left, int right) {
        if (left == right) return;
        res.insert(res.begin(), s.begin() + left, s.begin() + right);
        res.insert(res.begin(), ' ');
    }
};

int main() {
    string s = "Alice does not even like bob";
    Solution solution;
    cout << solution.reverseWords(s) << 1 << endl;

    return 0;
}