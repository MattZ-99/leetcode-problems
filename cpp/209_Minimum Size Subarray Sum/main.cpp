# include <iostream>
# include <vector>

using namespace std;

// Runtime: 632 ms, faster than 5.02% of C++ online submissions for Minimum Size Subarray Sum.
// Memory Usage: 10.6 MB, less than 59.81% of C++ online submissions for Minimum Size Subarray Sum.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = nums.size();
        int result = length + 1;
        int tmp_val = 0;
        for (int i=0; i<length; i++) {
            tmp_val = calminlen(i, target, nums, length, result);
            if (tmp_val == 0) break;
            result = tmp_val;
        }
        if (result <= length) return result;
        return 0;
    }

    int calminlen(const int i, int & target, vector<int>& nums, int & length,int & result) {
        int sum = 0;
        for (int j=i; j<length; j++) {
            if(j>=i+result) return result;
            sum += nums[j];
            if(sum >= target) return j-i+1;  
        }
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