#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Shortest Palindrome.
// Memory Usage: 7.6 MB, less than 61.05% of C++ online submissions for Shortest Palindrome.

class Solution {
public:
    string shortestPalindrome(string s) {
        string res;
        int sLength = s.length();
        if(sLength == 0) return res;

        res = s;
        res.push_back('#');
        string revS = s;
        reverse(revS.begin(), revS.end());
        res.append(revS);

        int pos = sLength - PMTLookUp(res);
        res.erase(res.begin() + sLength, res.end());
        res.insert(res.begin(), revS.begin(), revS.begin() + pos);

        return res;
    }

    int PMTLookUp(string& s) {
        int length = s.length();
        vector<int> PMT(length);
        PMT[0] = 0;
        int i = 0, j = 1;
        while(j < length) {
            if(s[i] == s[j]) {i++; PMT[j] = i; j++; continue;}
            if(i == 0) { PMT[j] = 0; j++; continue;}
            i = PMT[i - 1];
        }
        return PMT[length - 1];
    }
};

int main() {
    string s = "abcd";
    Solution solution;
    cout << solution.shortestPalindrome(s) << endl;

    return 0;
}