#include <iostream>
#include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
// Memory Usage: 6.8 MB, less than 84.30% of C++ online submissions for Spiral Matrix.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0 || matrix[0].size()==0) return result;
        int left = 0, right = matrix[0].size() - 1, top = 0, bottom = matrix.size() - 1;
        int dir = 0; 
        int m = 0, n = 0;
        while(left<=right && top<=bottom) {
            switch (dir) {
            case 0:
                if(n<right) {result.push_back(matrix[m][n]); n++;}
                else {dir++; top++;}
                break;
            case 1:
                if(m<bottom) {result.push_back(matrix[m][n]); m++;}
                else {dir++;right--;}
                break;
            case 2:
                if(n>left) {result.push_back(matrix[m][n]); n--;}
                else{dir++; bottom--;}
                break;
            case 3:
                if(m>top) {result.push_back(matrix[m][n]); m--;}
                else{dir = 0; left++;}
                break;
            default:
                break;
            }
        }
        result.push_back(matrix[m][n]);
        return result;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}}; //{{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    vector<int> res = solution.spiralOrder(matrix);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}