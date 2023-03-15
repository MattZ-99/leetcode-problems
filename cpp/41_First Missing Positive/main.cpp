#include <iostream>
#include <vector>
using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Missing Positive.
// Memory Usage: 9.7 MB, less than 90.76% of C++ online submissions for First Missing Positive.

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        if(length == 0) return 1;
        return quickSortAndFind(nums, 0, length-1, 0) + 1;

    }

    int quickSortAndFind(vector<int>& nums, int left, int right, int prior_value) {
        if (left > right) return prior_value;
        if(left == right) {
            if (newSubtract(nums[left], prior_value) <= 1) return returnZero(nums[left]);
            return prior_value;
        }
        int mid = quickSortOnce(nums, left, right);
        int val = nums[mid];
        if(val > 0) {
            int res = quickSortAndFind(nums, left, mid-1, prior_value);
            if (newSubtract(val, res) > 1) return res;
            return quickSortAndFind(nums, mid+1, right, val);
        }
        return quickSortAndFind(nums, mid+1, right, 0);
    }

    int quickSortOnce(vector<int>& nums, int left, int right) {
        int val = nums[(left+right)/2];
        nums[(left+right)/2] = nums[left];
        int lf = left + 1;
        while (lf<right) {
            if(newCompare(nums[lf], val)) {lf++; continue;}
            if(!newCompare(nums[right], val)) {right--; continue;}
            int tmp = nums[lf];
            nums[lf] = nums[right];
            nums[right] = tmp;
        }
        if(newCompare(nums[lf], val)) {
            nums[left] = nums[lf];
            nums[lf] = val;
            return lf;
        }
        else {
            nums[left] = nums[lf-1];
            nums[lf-1] = val;
            return lf - 1;
        }
        return 0;
    }

    int returnZero(int val) {
        if (val < 0) return 0;
        return val;
    }

    int newSubtract(int left, int right) {
        if (left < 0) left = 0;
        if(right < 0) right = 0;
        return left - right;
    }
    bool newCompare(int left, int right) {
        if(left <= right || left <= 0) return 1;
        return 0;
    }
};

int main() {
    vector<int> nums = {1,2,0};
    Solution solution;
    cout<< solution.firstMissingPositive(nums) << endl;

    return 0;
}