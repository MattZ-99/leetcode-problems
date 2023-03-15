#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 8 ms, faster than 70.26% of C++ online submissions for Combination Sum.
// Memory Usage: 22.9 MB, less than 19.53% of C++ online submissions for Combination Sum.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int length = candidates.size();
        vector<vector<int>> result;
        if(length == 0) return result;
        sort(candidates.begin(), candidates.end());
        return combinationSumKernel(candidates, target, 0, length);

    }
    vector<vector<int>> combinationSumKernel(vector<int>& candidates, int target, int left, int& length) {
        vector<vector<int>> result;
        if(left == length) return result;
        int val = candidates[left];
        if(val > target) return result;
        if(val == target) {
            vector<int> res;
            res.push_back(val);
            result.push_back(res);
            return result;
        }
        vector<vector<int>> first = combinationSumKernel(candidates, target-val, left, length);
        for (vector<vector<int>>::iterator p=first.begin(); p<first.end(); p++) (*p).insert((*p).begin(), val);
        vector<vector<int>> second = combinationSumKernel(candidates, target, left+1, length);
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        return result;
    }
};

int main() {
    vector<int> candidates = {1};
    int target = 2;
    Solution solution;
    vector<vector<int>> res = solution.combinationSum(candidates, target);
    for (int i = 0; i<res.size(); i++) {
        vector<int> r = res[i];
        for(int j=0; j<r.size(); j++) {
            cout << r[j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}