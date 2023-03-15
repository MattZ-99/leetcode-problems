#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


// Runtime: 8 ms, faster than 91.21% of C++ online submissions for 3Sum Closest.
// Memory Usage: 9.8 MB, less than 94.01% of C++ online submissions for 3Sum Closest.

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        int length = nums.size();
        for (int i=0; i<length-2; i++) {
            int sum = target - nums[i];

            int j = i+1;
            int k = length - 1;

            while (j<k) {
                int value = nums[j] + nums[k];
                if(abs(value-sum) == 0) return target;
                if(abs(value-sum) < abs(result-target)) result = value + nums[i];
                if(value-sum>0) k--;
                else j++;
            }

            while (j>i+1 && nums[j]==nums[j-1] && j<k) j++;
            while (k<length-1 && nums[k]==nums[k+1] && j<k) k--;
        }
        return result;
    }
};


int main() {
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution solution;
    int res = solution.threeSumClosest(nums, target);
    cout << res << endl;

    return 0;
}