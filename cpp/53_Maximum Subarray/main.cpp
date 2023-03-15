#include <iostream>
#include <vector>
using namespace std;

/*
Runtime: 8 ms, faster than 73.28% of C++ online submissions for Maximum Subarray.
Memory Usage: 13.1 MB, less than 91.85% of C++ online submissions for Maximum Subarray.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int  max = nums[0];
        int sum = 0;
        vector<int>::iterator it;
        for (it=nums.begin(); it!=nums.end(); it++){
            sum += *it;
            if (sum>max) max = sum;
            if (sum<0) sum = 0;
        }

        return max;
    }
};



int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = solution.maxSubArray(nums);
    cout<< res << endl;
    return 0;
}