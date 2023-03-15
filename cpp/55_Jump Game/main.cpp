#include <iostream>
#include <vector>

using namespace std;

// Runtime: 548 ms, faster than 18.10% of C++ online submissions for Jump Game.
// Memory Usage: 12.7 MB, less than 73.13% of C++ online submissions for Jump Game.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        if(length == 1) return 1;
        vector<bool> res(length);
        res[length-1] = true;
        for (int p = length - 2; p>=0; p--) {
            int val = p+nums[p];
            if(val >= length-1) {res[p] = 1; continue;}
            for (int i=val; i>p; i--) if(res[i]) {res[p] = 1; break;}
        } 
        return res[0];
    }
};

int main() {
    vector<int> nums = {3,2,1,0,4};
    Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}