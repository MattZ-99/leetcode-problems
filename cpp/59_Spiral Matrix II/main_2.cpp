/* 59. Spiral Matrix II
Medium

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 6.5 MB, less than 62.81% of C++ online submissions for Spiral Matrix II.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral_matrix(n, vector<int>(n, 0));
        int left=0, right=n-1, top=0, bottom=n-1, direction=0; // 0: to right, 1: to bottom, 2: to left, 3: to top.
        int row=0, col=0;
        for (int val=1; val<=n*n; val++) {
            spiral_matrix[row][col] = val;
            switch(direction) {
            case 0:
                if (col == right) {direction++; row++; top++;} else col++;
                break;
            case 1:
                if (row == bottom) {direction++; col--; right--;} else row++;
                break;
            case 2:
                if (col == left) {direction++; row--; bottom--;} else col--;
                break;
            case 3:
                if (row == top) {direction = 0; col++; left++;} else row--;
            }
        }
        return spiral_matrix;
    }
};


int main() {
    // Input.
    int n = 3;

    // Solution.
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(n);
    
    // Print.
    for(int i = 0; i < res.size(); i++) {
        vector<int> r = res[i];
        for(int j = 0; j < r.size(); j++) {
            cout << r[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}