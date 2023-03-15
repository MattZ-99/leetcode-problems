/*
448. Find All Numbers Disappeared in an Array
Easy

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/

//Runtime: 143 ms, faster than 42.62% of C++ online submissions for Find All Numbers Disappeared in an Array.
//Memory Usage: 33.6 MB, less than 94.60% of C++ online submissions for Find All Numbers Disappeared in an Array.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int nums_len = nums.size(), pos=0, val=-1;
        while (pos < nums_len) {
            val = nums[pos] - 1;
            if (val == -1) {pos++; continue; }

            if (nums[val] == 0) pos++;
            else {
                nums[pos] = nums[val];
                nums[val] = 0;
            }
        }

        vector<int> res;
        for (int i = 0; i < nums_len; i++) {
            if (nums[i] == 0) continue;
            res.push_back(i+1);
        }
        return res;
  }
};

void print_vector(vector<int>& nums) {
    for (auto i: nums) {
        cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    // Inputs.
    vector<int> nums = {4,3,2,7,8,2,3,1};
    cout << "nums: "; print_vector(nums);

    // Solution.
    Solution solution;
    vector<int> disappeared_nums = solution.findDisappearedNumbers(nums);
    cout << "disappeared nums: "; print_vector(disappeared_nums);
}