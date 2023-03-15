#include <iostream>
#include <vector>

using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jump Game II.
// Memory Usage: 8.2 MB, less than 71.93% of C++ online submissions for Jump Game II.

class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        vector<int> results(length, 1001);
        results[length-1] = 0;

        int pointer = length - 1;
        while (pointer > 0) {
            pointer--;
            results[pointer] = calculateMinStep(nums, results, pointer, length);
        }
        return results[0];
    }

    int calculateMinStep(vector<int>& nums, vector<int>& results, int pointer, int length) {
        int end = pointer + nums[pointer];
        if (end >= length) end = length - 1;
        int res = results[pointer];
        for (int i = pointer + 1; i<=end; i++) {
            if(res > results[i]) res = results[i];
        }
        return res + 1;
    }
};

int main() {
    vector<int> nums = {2,3,0,1,4};
    Solution solution;
    cout << solution.jump(nums) << endl;
    return 0;
}