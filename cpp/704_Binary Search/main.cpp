/*
704. Binary Search
Easy

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

// Runtime: 42 ms, faster than 89.78% of C++ online submissions for Binary Search.
// Memory Usage: 27.5 MB, less than 92.10% of C++ online submissions for Binary Search.

# include <iostream>
# include <vector>
using namespace std;


class Solution {
private:
    int search_kernel(vector<int>& nums, int target, int start, int end) {
        if (start > end || nums[start] > target || nums[end] < target) return -1;
        
        int medium = (start + end) / 2;
        if (nums[medium] < target) return search_kernel(nums, target, medium + 1, end);
        else if (nums[medium] > target) return search_kernel(nums, target, start, medium - 1);
        return medium;
    }

public:
    int search(vector<int>& nums, int target) {
        return search_kernel(nums, target, 0, nums.size() - 1);
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