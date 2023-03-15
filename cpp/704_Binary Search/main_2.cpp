/*
704. Binary Search
Easy

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

// Runtime: 71 ms, faster than 46.52% of C++ online submissions for Binary Search.
// Memory Usage: 27.4 MB, less than 99.73% of C++ online submissions for Binary Search.


# include <iostream>
# include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, medium, val;

        while (start <= end) {
            medium = (start + end) / 2;
            val = nums[medium];
            if (val == target) return medium;
            else if (val > target) end = medium - 1;
            else start = medium + 1;            
        }
        return -1;
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

int main(){
    cout << "704. Binary Search" << endl;
    
    // Input vector of nums.
    // vector<int> nums = {-1, 0, 3, 5, 9, 12};
    vector<int> nums; int a;
    cout << "Cin nums: ";
    while(true){
        if (cin.get() == '\n') break;
        cin >> a;
        nums.push_back(a);
    }


    // Input target.
    int target;
    cout << "Cin target: ";
    cin >> target;
    cout << "\n";
    
    // Print input info.
    cout << "Input: " << "nums = "; print_vector(nums);
    cout << "\t" << "target = " << target << endl;

    // Solution.
    Solution solution;

    cout << "Output: " << solution.search(nums, target) << endl;
    
    return 0;
}