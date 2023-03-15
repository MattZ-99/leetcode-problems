#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Permutation.
// Memory Usage: 12.1 MB, less than 78.33% of C++ online submissions for Next Permutation.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length = nums.size();
        if(length <= 1) return;
        int pos = length - 1;
        while (pos >= 0) {
            if (pos == 0 || nums[pos] > nums[pos-1]) {
                pos--;
                break;
            }
            pos--;
        }
        if(pos == -1) {
            reverseList(nums, 0, length-1);
            return;
        }
        for (int i = length-1; i>pos; i--) {
            if(nums[i] > nums[pos]) {
                int tmp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = tmp;

                reverseList(nums, pos + 1, length-1);
                return;
            }
        }
        return;
    }
    void reverseList(vector<int>& nums, int left, int right) {
        int tmp;
        while(left < right) {
            tmp = nums[right];
            nums[right] = nums[left];
            nums[left] = tmp;
            left++;
            right--;
        }
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2,3,1};
    solution.nextPermutation(nums);
    for (int i=0;i<nums.size();i++) {
        cout << nums[i] << " ";
    }

    return 0;
}