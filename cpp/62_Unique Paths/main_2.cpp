#include <iostream>
#include <vector>

using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Paths.
// Memory Usage: 6.2 MB, less than 47.29% of C++ online submissions for Unique Paths.

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) return 1;
        if(m>n) {int tmp = m; m = n; n = tmp;}
        vector<vector<int>> result(m, vector<int>(n));
        for(int q=0; q<n; q++) result[0][q] = 1;
        for(int p=1; p<m; p++) {
            result[p][p] = 2 * result[p-1][p];
            for(int q=p+1; q<n; q++) {
                result[p][q] = result[p-1][q] + result[p][q-1];
            }
        }
        return result[m-1][n-1];
    }
};

int main() {
    int m = 3, n = 7;
    Solution solution;
    cout << solution.uniquePaths(m,n);
    return 0;
}