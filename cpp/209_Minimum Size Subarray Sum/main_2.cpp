# include <iostream>
# include <vector>

using namespace std;

// Runtime: 4 ms, faster than 98.68% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 10.5 MB, less than 59.81% of C++ online submissions for Minimum Size Subarray Sum.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();
        int result = length + 1;
        int left = 0;
        int right = -1;
        int sum = 0;
        while (true) {
            if(sum<target) {
                right++;
                if(right>=length) break;
                sum += nums[right];
                continue;
            }
            result = min(result, right-left+1);
            if(result == 1) return 1;
            sum -= nums[left];
            left++;
        }
        if (result <= length) return result;
        return 0;
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution solution;
    cout << solution.minSubArrayLen(target, nums) << endl;
    return 0;
}