#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return 0;
        return isInterleaveKernel(s1, s2, s3, 0, 0);
    }
    bool isInterleaveKernel(string& s1, string& s2, string& s3, int i, int j) {
        if (i == s1.length() && j == s2.length()) return 1;
        bool res = 0;
        if(i < s1.length()) res = res || (s1[i] == s3[i + j] && isInterleaveKernel(s1, s2, s3, i+1, j));
        if(j < s2.length()) res = res || (s2[j] == s3[i + j] && isInterleaveKernel(s1, s2, s3, i, j+1));
        return res;
    }
};

int main() {
    string s1 = "", s2 = "", s3 = "";
    Solution solution;
    bool a = solution.isInterleave(s1, s2, s3);
    cout << a << endl;
    return 0;
}