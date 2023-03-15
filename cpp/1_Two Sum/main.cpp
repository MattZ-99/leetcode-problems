/* 1. Two Sum
Easy

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order. */

// Runtime: 32 ms, faster than 53.68% of C++ online submissions for Two Sum.
// Memory Usage: 11.9 MB, less than 13.66% of C++ online submissions for Two Sum.


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> memory;
        for (int i=0; i<nums.size(); i++) memory.insert({nums[i], i});
        
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            auto search_res = memory.find(target - nums[i]);
            if (search_res != memory.end() && search_res->second != i)
                {res.push_back(i); res.push_back(search_res->second); break; }
        }
        return res;
    }
};

template <typename T>
void print_vector(vector<T>& nums) {
    cout << "[ ";
    for (auto n: nums) {
        cout << n << ' ';
    }
    cout << ']';
}

int main() {
    // Inputs.
    vector<int> nums = {3,2,4};
    int target = 6;

    // Solutions.
    Solution solution;
    vector<int> res = solution.twoSum(nums, target);
    cout << "Index:"; print_vector(res);
}