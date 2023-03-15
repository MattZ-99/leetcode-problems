#include <iostream>
#include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
// Memory Usage: 7.6 MB, less than 82.78% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        permuteRecursion(res, perm, nums);
        return res;
    }
    void permuteRecursion(vector<vector<int>>& res, vector<int>& perm, vector<int>& nums) {
        int nl = nums.size();
        if(nl == 0) {res.push_back(perm); return;}
        for(int i = 0; i<nl; i++) {
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
    vector<int> nums = {1,2,3, 4,5};
    Solution solution;
    vector<vector<int>> res = solution.permute(nums);
    cout << res.size()<<endl;
    for(int i=0; i<res.size(); i++) {
        vector<int> r = res[i];
        for(int j=0; j<r.size(); j++) cout << r[j] << ' ';
        cout << '\n';
    }
    return 0;
}