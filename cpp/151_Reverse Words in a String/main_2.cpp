#include <iostream>
#include <string>

using namespace std;

// Runtime: 4 ms, faster than 90.35% of C++ online submissions for Reverse Words in a String.
// Memory Usage: 7 MB, less than 91.68% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int begin, end;
        int i = s.size() - 1;
        while (1) {
            while(i >= 0 && s[i] == ' ') i--;
            if(i < 0) break;
            end = i + 1;

            while(i >= 0 && s[i] != ' ') i--;
            begin = i + 1;
            
            res.insert(res.end(), s.begin() + begin, s.begin() + end);
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};

int main() {
    string s = "Alice does not even like bob";
    Solution solution;
    cout << solution.reverseWords(s) << 1 << endl;

    return 0;
}