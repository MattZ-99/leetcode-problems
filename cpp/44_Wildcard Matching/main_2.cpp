#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Runtime: 52 ms, faster than 51.99% of C++ online submissions for Wildcard Matching.
// Memory Usage: 27.8 MB, less than 14.66% of C++ online submissions for Wildcard Matching.

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length(), lp = p.length();
        vector<vector<int>> matchMatrix(ls+1, vector<int>(lp+1, 0));
        matchMatrix[0][0] = 1;
        for(int i = 1; i<=lp; i++) {
            if(p[i-1] != '*') break;
            matchMatrix[0][i] = 1; 
        }
        for(int j=1; j<=lp; j++) {
            for(int i=1; i<=ls; i++) {
                if(p[j-1] == '*') {
                    matchMatrix[i][j] = matchMatrix[i-1][j] || matchMatrix[i-1][j-1] || matchMatrix[i][j-1];
                    continue;
                }
                if(p[j-1] == '?') {
                    matchMatrix[i][j] = matchMatrix[i-1][j-1];
                    continue;
                }
                matchMatrix[i][j] = matchMatrix[i-1][j-1] && (s[i-1] == p[j-1]);
            }
        }
        return matchMatrix[ls][lp];
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