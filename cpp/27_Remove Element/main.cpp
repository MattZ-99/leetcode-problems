/* 27. Remove Element

Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.
Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
Return k after placing the final result in the first k slots of nums.
Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
 */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.6 MB, less than 91.79% of C++ online submissions for Remove Element.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) return 0;
        auto it_start = nums.begin(), it_end = nums.end() - 1;
        // int tmp;
        
        while (it_start <= it_end) {
            if (*it_end == val) {it_end--; continue;}
            if (*it_start != val) {it_start++; continue;}

            // tmp = *it_end; *it_end = *it_start; *it_start = tmp;
            *it_start = *it_end;
            it_start++; it_end--;
        }
        return it_end - nums.begin() + 1;
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
    // vector<int> nums = {3,2,2,3};
    // int val = 3;
    vector<int> nums;
    int val, tmp;
    cout << "nums: ";
    while(true) {
        if (cin.get() == '\n') break;
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << "val: ";
    cin >> val;

    cout << "nums = "; print_vector(nums); cout << "\n\n";

    // Solution.
    Solution solution;

    cout << "k = " << solution.removeElement(nums, val) << endl;
    cout << "nums = "; print_vector(nums); cout << '\n';

    return 0;
}