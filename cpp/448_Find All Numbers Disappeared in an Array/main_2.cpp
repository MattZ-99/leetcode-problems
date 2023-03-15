/*
448. Find All Numbers Disappeared in an Array
Easy

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
*/

//Runtime: 70 ms, faster than 86.09% of C++ online submissions for Find All Numbers Disappeared in an Array.
//Memory Usage: 33.5 MB, less than 94.60% of C++ online submissions for Find All Numbers Disappeared in an Array.


#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int nums_len = nums.size(), pos=0, val, temp;

        while (true) {
            val = nums[pos] - 1;
            if (nums[val] == nums[pos]) {
                pos++;
                if (pos >= nums_len) break;
            }
            else {temp = nums[val]; nums[val] = nums[pos]; nums[pos] = temp; }
        }

        vector<int> disappeared_nums;
        for (int i = 0; i < nums_len; i++) {
            if (i != nums[i] - 1) disappeared_nums.push_back(i+1);
        }
        return disappeared_nums;
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