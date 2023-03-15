#include <iostream>
#include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6.5 MB, less than 26.07% of C++ online submissions for Unique Paths.

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        vector<vector<int>> result(m, vector<int>(n, 0));
        for(int p=0; p<m; p++) result[p][n-1] = 1;
        for(int q=0; q<n; q++) result[m-1][q] = 1;
        for(int p=m-2; p>=0; p--) {
            for(int q=n-2; q>=0; q--) {
                result[p][q] = result[p+1][q] + result[p][q+1];
            }
        }
        return result[0][0];
    }
};

int main() {
    int m = 3, n = 3;
    Solution solution;
    cout << solution.uniquePaths(m,n);
    return 0;
}