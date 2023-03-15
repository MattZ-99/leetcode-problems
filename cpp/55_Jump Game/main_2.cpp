#include <iostream>
#include <vector>

using namespace std;

// Runtime: 8 ms, faster than 84.97% of C++ online submissions for Jump Game.
// Memory Usage: 12.7 MB, less than 93.43% of C++ online submissions for Jump Game.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int p = 0;
        int target = nums.size() - 1;
        while(p < target) {
            reach = max(reach, p + nums[p]);
            if(reach>=target) return 1;
            p++;
            if(p>reach) return 0;
        }
        return 1;
    }
};

int main() {
    vector<int> nums = {3,2,1,0,4};
    Solution solution;
    cout << solution.canJump(nums) << endl;
    return 0;
}