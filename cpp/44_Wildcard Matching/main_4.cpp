#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Wildcard Matching.
// Memory Usage: 6.5 MB, less than 83.59% of C++ online submissions for Wildcard Matching.

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, ls = s.length(), lp = p.length(), iStar = -1, jStar = -1;
        while(i < ls) {
            if(j<lp) {
                if(p[j] == '?' || p[j] == s[i]) {i++; j++; continue;}
                if(p[j] == '*') {iStar = i; jStar = j++; continue; }
            }
            if(iStar >= 0) {i = ++iStar; j = jStar + 1; continue;}
            return 0;
        }
        while(j<lp && p[j] == '*') j++;
        return (j==lp);
    }
};

int main() {
    // string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", 
    // p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    string s="abcabczzzde", p = "*abc???de*";

    Solution solution;
    cout << solution.isMatch(s, p) << endl;
    return 0;
}