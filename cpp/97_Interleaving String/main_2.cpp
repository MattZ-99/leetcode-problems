#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Runtime: 4 ms, faster than 68.22% of C++ online submissions for Interleaving String.
// Memory Usage: 6.5 MB, less than 67.80% of C++ online submissions for Interleaving String.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3) return 0;
        vector<vector<bool>> DPMatrix(l1+1, vector<bool>(l2+1, 0));
        DPMatrix[l1][l2] = 1;
        for(int k=l3-1; k>=0; k--) {
            for(int i=min(k, l1); i>=max(0, k-l2); i--) {
                int j = k - i;
                if(i<l1) DPMatrix[i][j] = (s1[i] == s3[k] && DPMatrix[i+1][j]);
                if(j<l2) DPMatrix[i][j] = DPMatrix[i][j] || (s2[j] == s3[k] && DPMatrix[i][j+1]);
            }
        }
        return DPMatrix[0][0];
    }
};

int main() {
    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution solution;
    bool a = solution.isInterleave(s1, s2, s3);
    cout << a << endl;
    return 0;
}