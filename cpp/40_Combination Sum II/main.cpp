#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 12 ms, faster than 42.16% of C++ online submissions for Combination Sum II.
// Memory Usage: 23.6 MB, less than 8.71% of C++ online submissions for Combination Sum II.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int length = candidates.size();
        vector<vector<int>> result;
        if(length == 0) return result;
        sort(candidates.begin(), candidates.end());
        return combinationSumKernel(candidates, target, 0, length, 0);

    }
    vector<vector<int>> combinationSumKernel(vector<int>& candidates, int target, int left, int& length, bool flag) {
        vector<vector<int>> result;
        if(left == length) return result;
        int val = candidates[left];
        if(flag && val == candidates[left-1]) return combinationSumKernel(candidates, target, left+1, length, 1);
        if(val > target) return result;
        if(val == target) {
            vector<int> res;
            res.push_back(val);
            result.push_back(res);
            return result;
        }
        vector<vector<int>> first = combinationSumKernel(candidates, target-val, left+1, length, 0);
        for (vector<vector<int>>::iterator p=first.begin(); p<first.end(); p++) (*p).insert((*p).begin(), val);
        vector<vector<int>> second = combinationSumKernel(candidates, target, left+1, length, 1);
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        return result;
    }
};

int main() {
    vector<int> candidates = {2,5,2,1,2};
    int target = 5;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum2(candidates, target);
    for (int i = 0; i<res.size(); i++) {
        vector<int> r = res[i];
        for(int j=0; j<r.size(); j++) {
            cout << r[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}