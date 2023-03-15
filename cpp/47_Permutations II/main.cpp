#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations II.
// Memory Usage: 8.4 MB, less than 87.42% of C++ online submissions for Permutations II.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> perm;
        permuteRecursion(res, perm, nums);
        return res;
    }
    void permuteRecursion(vector<vector<int>>& res, vector<int>& perm, vector<int>& nums) {
        int nl = nums.size();
        if(nl == 0) {res.push_back(perm); return;}
        for(int i = 0; i<nl; i++) {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int val = nums[i];
            perm.push_back(val);
            nums.erase(nums.begin() + i);
            permuteRecursion(res, perm, nums);
            nums.insert(nums.begin() + i, val);
            perm.pop_back();
        }
    }
};

int main() {
    vector<int> nums = {1,1,2};
    Solution solution;
    vector<vector<int>> res = solution.permuteUnique(nums);
    cout << res.size()<<endl;
    for(int i=0; i<res.size(); i++) {
        vector<int> r = res[i];
        for(int j=0; j<r.size(); j++) cout << r[j] << ' ';
        cout << '\n';
    }
    return 0;
}