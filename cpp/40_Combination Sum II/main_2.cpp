#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 4 ms, faster than 92.67% of C++ online submissions for Combination Sum II.
// Memory Usage: 10.5 MB, less than 90.99% of C++ online submissions for Combination Sum II.

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        Search(candidates, target, result, comb, candidates.size()-1, 0);
        return result;
    }
    void Search(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& comb, int pos, bool flag) {
        if(target == 0) {result.push_back(comb); return;}
        if(target < 0) return;
        for(int p = pos; p>=0; p--) {
            if(flag && candidates[p] == candidates[p+1]) continue;
            comb.push_back(candidates[p]);
            Search(candidates, target-candidates[p], result, comb, p-1, 0);
            comb.pop_back();
            flag = 1;
        }

    }
};

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
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

