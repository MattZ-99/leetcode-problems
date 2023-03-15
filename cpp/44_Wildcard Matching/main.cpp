#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchKernel(s, p, 0, 0);
    }
    bool isMatchKernel(string& s, string& p, int ls, int lp) {
        if(ls == s.length()) {   
            if(lp == p.length()) return 1;
            if(p[lp] == '*') return isMatchKernel(s, p , ls, lp+1);
            return 0;
        }
        if(lp == p.length()) return 0;
        
        if(p[lp] == '*') {
            if(lp > 0 && p[lp-1] == '*') return isMatchKernel(s, p , ls, lp+1);
            return (isMatchKernel(s, p , ls, lp+1) || isMatchKernel(s, p , ls+1, lp));
        }
        if(comp2char(s[ls], p[lp])) return (isMatchKernel(s, p , ls+1, lp+1));
        return 0;
    }

    bool comp2char(char a, char b) {
        if(b == '?') return 1;
        return (a == b);
    }
};

int main() {
    string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", 
    p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    Solution solution;
    cout << solution.isMatch(s, p) << endl;
    return 0;
}