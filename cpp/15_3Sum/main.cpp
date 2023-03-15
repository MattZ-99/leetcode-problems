#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Runtime: 80 ms, faster than 74.78% of C++ online submissions for 3Sum.
// Memory Usage: 21.2 MB, less than 43.26% of C++ online submissions for 3Sum.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int length = nums.size();
        if(length<3) return result;

        sort(nums.begin(), nums.end());

        int value = 0;

        for (int i=0; i<length-2; i++) {
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int sum = 0 - nums[i];

            int j = i + 1;
            int k = length - 1; 
            while (j<k) {
                int b = nums[j];
                int c = nums[k];
                if(b+c>sum) k -= 1;
                else if(b+c<sum) j += 1;
                else {
                    vector<int> res = {nums[i], b, c};
                    result.push_back(res);
                    j++;
                    k--;
                }
                while (j>i+1 && nums[j]==nums[j-1] && j<k) j++;
                while (k<length-1 && nums[k]==nums[k+1] && j<k) k--;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};

    Solution solution;
    vector<vector<int>> res = solution.threeSum(nums);
    for (int i=0; i< res.size(); i++) {
        vector<int> v = res[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}