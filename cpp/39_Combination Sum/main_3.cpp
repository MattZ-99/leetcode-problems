#include <iostream>
#include <vector>

using namespace std;


// Runtime: 8 ms, faster than 70.26% of C++ online submissions for Combination Sum.
// Memory Usage: 10.6 MB, less than 99.77% of C++ online submissions for Combination Sum.

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> comb;
        Search(candidates, target, result, comb, 0);
        return result;
    }
    void Search(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& comb, int pos) {
        if(target == 0) {result.push_back(comb); return;}
        if(target < 0) return;
        for(int p = pos; p<candidates.size(); p++) {
            comb.push_back(candidates[p]);
            Search(candidates, target-candidates[p], result, comb, p);
            comb.pop_back();
        }

    }
};

int main() {
    vector<int> candidates = {2,3,5};
    int target = 8;
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