#include <iostream>
#include <vector>

using namespace std;

// Runtime: 8 ms, faster than 82.55% of C++ online submissions for Minimum Path Sum.
// Memory Usage: 9.6 MB, less than 81.59% of C++ online submissions for Minimum Path Sum.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=m-2; i>=0; i--) grid[i][n-1] += grid[i+1][n-1];
        for(int j=n-2; j>=0; j--) grid[m-1][j] += grid[m-1][j+1];

        for(int i=m-2; i>=0; i--)
            for(int j=n-2; j>=0; j--)
                grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
        
        return grid[0][0];
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    Solution solution;
    cout << solution.minPathSum(grid);
    return 0;
}