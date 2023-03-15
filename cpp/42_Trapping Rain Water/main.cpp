#include <iostream>
#include <vector>

using namespace std;


// Runtime: 4 ms, faster than 88.40% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 14.1 MB, less than 92.52% of C++ online submissions for Trapping Rain Water.

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int left = 0;
        int right = length - 1;
        int left_max = 0, right_max = 0;
        int sum = 0;

        while(left <= right) {
            if(left_max > right_max) {
                if(height[right] < right_max) sum += right_max - height[right];
                else right_max = height[right];
                right--;
                continue;
            }
            if(height[left] < left_max) sum += left_max - height[left];
            else left_max = height[left];
            left++;
        }
        return sum;
    }
};


int main() {
    vector<int> height = {4,2,0,3,2,5};
    Solution solution;
    cout << solution.trap(height) <<endl;

    return 0;
}