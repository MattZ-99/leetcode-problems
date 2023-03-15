# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.2 MB, less than 70.47% of C++ online submissions for Sort Colors.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p_zero = 0, p_two = nums.size() - 1, pos = 0;
        while (pos <= p_two) {
            if (nums[pos] == 0) {
                swap(nums[pos], nums[p_zero]); p_zero++; 
                if (pos < p_zero) {pos++; continue;}
            }
            if (nums[pos] == 2) {swap(nums[pos], nums[p_two]); p_two--; }
            if (nums[pos] == 1) pos++;
        }
    }
};

int main() {
    printf("#%s\n\n", "75. Sort Colors");

    vector<int> nums{2, 0, 2, 1, 1, 0};
    Solution s;
    s.sortColors(nums);
    for (int num:nums) {cout << num << ' ';}

    return 1;
}
