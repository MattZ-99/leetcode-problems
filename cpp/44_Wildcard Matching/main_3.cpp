#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector<vector<int>>
// Runtime: 32 ms, faster than 66.23% of C++ online submissions for Wildcard Matching.
// Memory Usage: 17.6 MB, less than 26.87% of C++ online submissions for Wildcard Matching.

// vector<vector<bool>>
// Runtime: 44 ms, faster than 56.26% of C++ online submissions for Wildcard Matching.
// Memory Usage: 8.9 MB, less than 64.58% of C++ online submissions for Wildcard Matching.

class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length(), lp = p.length();
        int right = 1;
        while(ls-right>=0 && lp-right>=0) {
            if(p[lp-right] == '*') break;
            if(p[lp-right] == '?' || p[lp-right] == s[ls-right]) {right++; continue;}
            return 0;
        }
        s.erase(s.end()-right+1, s.end());
        p.erase(p.end()-right+1, p.end());

        ls = s.length(), lp = p.length();
        right = 0;
        while(right<ls && right<lp) {
            if(p[right] == '*') break;
            if(p[right] == '?' || p[right] == s[right]) {right++; continue;}
            return 0;
        }
        s.erase(s.begin(), s.begin()+right);
        p.erase(p.begin(), p.begin()+right);

        ls = s.length(), lp = p.length();
        string::iterator it = p.begin()+1;
        while(it < p.end()) {
            if(*it == '*' && *(it-1) == '*') {it = p.erase(it); continue;}
            it++;
        }
        ls = s.length(), lp = p.length();

        vector<vector<bool>> matchMatrix(ls+1, vector<bool>(lp+1, 0));
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