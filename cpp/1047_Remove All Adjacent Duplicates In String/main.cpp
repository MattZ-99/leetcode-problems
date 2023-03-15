/* 1047. Remove All Adjacent Duplicates In String
Easy

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.
 */

// Runtime: 18 ms, faster than 91.90% of C++ online submissions for Remove All Adjacent Duplicates In String.
// Memory Usage: 11 MB, less than 69.72% of C++ online submissions for Remove All Adjacent Duplicates In String.

# include <iostream>
# include <string>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (char c: s) {
            if (res.length() == 0 || *(res.end()-1) != c) res.push_back(c);
            else res.pop_back();  
        }
        return res;
    }
};

int main() {
    // Inputs.
    string s = "abbaca";

    // Solution.
    Solution solution;
    cout << solution.removeDuplicates(s);

    return 0;
}