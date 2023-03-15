#include <iostream>
#include <vector>
using namespace std;


// Runtime: 8 ms, faster than 82.39% of C++ online submissions for Find First and Last Position of Element in Sorted Array.
// Memory Usage: 13.6 MB, less than 73.91% of C++ online submissions for Find First and Last Position of Element in Sorted Array.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size()-1;
        int pos = binarySearch(nums, target, 0, length);
        if (pos == -1) {vector<int> res = {-1, -1}; return res;}

        vector<int> res;

        int left = 0, right = pos, mid;
        while (left<right) {
            mid = (left + right) / 2;
            if(nums[mid] == target) right = mid;
            else left = mid + 1;
        }
        res.push_back(right);

        left = pos;
        right = length;
        while (left<right) {
            mid = (left + right  + 1) / 2;
            if(nums[mid] == target) left = mid;
            else right = mid - 1;
        }
        res.push_back(left);

        return res;
    }

    int binarySearch(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (target == nums[mid]) return mid;
        if(target > nums[mid]) return binarySearch(nums, target, mid+1, right);
        return binarySearch(nums, target, left, mid-1);
    }
};

int main() {
    vector<int> nums = {5,7,7,8,8,10};
    int target = 6;
    Solution solution;
    vector<int> res = solution.searchRange(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }

    return 0;
}