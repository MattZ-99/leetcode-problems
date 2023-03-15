#include <iostream>
#include <vector>

using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
// Memory Usage: 6.3 MB, less than 94.20% of C++ online submissions for Spiral Matrix II.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int left = 0, right=n-1, top=0, bottom=n-1;
        int m=0, p=0;
        int dir = 0;
        int val = 1;
        
        while(left<=right && top<=bottom) {
            result[m][p] = val;
            val++;
            if(dir==0) {
                if(p==right) {dir++; m++; top++;} else p++;
                continue;
            }
            if(dir==1) {
                if(m==bottom) {dir++; p--; right--;} else m++;
                continue;
            }
            if(dir==2) {
                if(p==left) {dir++; m--; bottom--;} else p--;
                continue;
            }
            if(dir==3) {
                if(m==top) {dir = 0; p++; left++;} else m--;
            }
        }
        return result;
    }
};

int main() {
    int n = 3;
    Solution solution;
    vector<vector<int>> res = solution.generateMatrix(n);
    for(int i = 0; i < res.size(); i++) {
        vector<int> r = res[i];
        for(int j = 0; j < r.size(); j++) {
            cout << r[j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}