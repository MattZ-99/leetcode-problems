#include <iostream>
#include <vector>

using namespace std;

// Runtime: 32 ms, faster than 5.76% of C++ online submissions for Permutations.
// Memory Usage: 7.6 MB, less than 62.49% of C++ online submissions for Permutations.

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>(1, nums[0]));

        for(int i=1; i<nums.size(); i++) {
            int rl = res.size();
            for(int j=0; j<rl; j++) {
                vector<int> perm = *(res.end() - 1);
                res.pop_back();
                for(int k=0; k<=perm.size(); k++) {
                    perm.insert(perm.begin()+k, nums[i]);
                    res.insert(res.begin(), perm);
                    perm.erase(perm.begin()+k);
                }
            }
        }
        return res;
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