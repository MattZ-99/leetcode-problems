/* 209. Minimum Size Subarray Sum
Medium

Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 */

// Runtime: 92 ms, faster than 24.71% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 28.2 MB, less than 88.40% of C++ online submissions for Minimum Size Subarray Sum.

# include <iostream>
# include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result=INT32_MAX, sum=0;  
        auto it_left = nums.begin(), it_right = nums.begin();

        while (true) {
            if (sum < target) {
                if (it_right == nums.end()) break;
                sum += *it_right; it_right++;
            }
            else {
                result = result > (it_right - it_left) ? (it_right - it_left) : result;
                sum -= *it_left; it_left++;
            }
        }
        return result == INT32_MAX ? 0 : result;    
    }
};

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution solution;
    cout << solution.minSubArrayLen(target, nums) << endl;
    return 0;
}