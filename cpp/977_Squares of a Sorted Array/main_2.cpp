/* 977. Squares of a Sorted Array
Easy
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 */

// Runtime: 42 ms, faster than 83.63% of C++ online submissions for Squares of a Sorted Array.
// Memory Usage: 25.7 MB, less than 94.66% of C++ online submissions for Squares of a Sorted Array.

#include <iostream>
#include <vector>
#include<cmath>
#include <climits>

using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int k = nums.size(), val_left, val_right;
        vector<int> nums_sqr(k, 0);
        vector<int>::iterator it_left=nums.begin(), it_right=nums.end()-1;
        while (k > 0) {
            k--;
            val_left = (*it_left) * (*it_left); val_right = (*it_right) * (*it_right);
            if (val_left < val_right) {nums_sqr[k] = val_right; it_right--;}
            else {nums_sqr[k] = val_left; it_left++;}
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