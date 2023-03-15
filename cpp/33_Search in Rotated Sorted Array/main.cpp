#include <iostream>
#include <vector>
using namespace std;

// Runtime: 4 ms, faster than 80.83% of C++ online submissions for Search in Rotated Sorted Array.
// Memory Usage: 11.1 MB, less than 79.57% of C++ online submissions for Search in Rotated Sorted Array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search_kernel(nums, target, 0, nums.size() - 1);
    }

    int search_kernel(vector<int>& nums, int target, int left, int right) {
        if(left > right) return -1;
        if(target == nums[left]) return left;
        if(target == nums[right]) return right;
        if (target < nums[left] && target > nums[right]) return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        if (left == right) return -1;
        if (target < nums[mid]) {
            if(target > nums[left]) return search_kernel(nums, target, left + 1, mid - 1);
            if(nums[mid] < nums[right]) return search_kernel(nums, target, left + 1, mid - 1);
            return search_kernel(nums, target, mid + 1, right - 1);
        }
        if(target < nums[right]) return search_kernel(nums, target, mid + 1, right - 1);
        if(nums[mid] < nums[right]) return search_kernel(nums, target, left + 1, mid - 1);
        return search_kernel(nums, target, mid + 1, right - 1);
    }
};

int main() {
    vector<int> nums = {4,5,6,7,8,1,2,3};
    int target = 8;
    Solution solution;
    cout << solution.search(nums, target);
    return 0;
}