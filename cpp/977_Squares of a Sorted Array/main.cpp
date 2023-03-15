/* 977. Squares of a Sorted Array
Easy
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 */

// Runtime: 27 ms, faster than 98.73% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 27.1 MB, less than 5.85% of C++ online submissions for Squares of a Sorted Array.

#include <iostream>
#include <vector>
#include<cmath>
#include <climits>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> nums_sqr;

        if (nums.size() == 0) return nums_sqr;

        int start=0, end=nums.size()-1, medium=(start+end)/2;
        while (start<end) {
            if (nums[medium] == 0) break;
            if (nums[medium] < 0 && nums[medium+1]>=0) break;
            if (nums[medium] < 0) {start=medium+1; medium=(start+end)/2; continue;}
            end = medium; medium=(start+end)/2;
        }
        if (start == end) medium = start;
        else if (-nums[medium] > nums[medium+1]) medium += 1;
        vector<int>::iterator it = nums.begin() + medium, it_left = it - 1, it_right = it + 1;

        nums_sqr.push_back(pow(*it, 2));
        int val_left, val_right;
        while (it_left>=nums.begin() || it_right < nums.end()) {
            if (it_left < nums.begin()) val_left = INT_MAX;
            else val_left = pow(*it_left, 2);
            if(it_right < nums.end()) val_right = pow(*it_right, 2);
            else val_right = INT_MAX;

            if (val_left < val_right) {nums_sqr.push_back(val_left); it_left--;}
            else {nums_sqr.push_back(val_right); it_right++;}
        }
        return nums_sqr;
    }
};

template <typename T>
void print_vector(vector<T>& nums) {
    cout << "[ ";
    for (auto n: nums) cout << n << ' ';

    cout << ']';
}

int main() {
    // Inputs.
    vector<int> nums = {-2, -1, 3};

    cout << "nums = "; print_vector(nums); cout << "\n\n";

    // Solution.
    Solution solution;
    vector<int> nums_square = solution.sortedSquares(nums);
    cout << "Squared nums = "; print_vector(nums_square); cout << "\n\n";


    return 0;
}