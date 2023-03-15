#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


// Runtime: 59 ms, faster than 88.52% of C++ online submissions for 4Sum.
// Memory Usage: 13.5 MB, less than 33.36% of C++ online submissions for 4Sum.

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> result;
        if(length < 4) return result;
        
        sort(nums.begin(), nums.end());

        for (int a = 0; a < length-3; a++) {
            if (nums[a] > target/4) break;
            if (a > 0 && nums[a] == nums[a-1]) continue;
            
            vector<vector<int>> threeSumRes = threeSum(nums, target - nums[a], a, length);
            for (int i = 0; i < threeSumRes.size(); i++) {
                vector<int> res = threeSumRes[i];
                res.insert(res.begin(), nums[a]);
                result.push_back(res);
            }
        }
        return result;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int target, int a, int length) {
        vector<vector<int>> result;
        for (int b = a + 1; b < length - 2; b++) {
            if (nums[b] > target/3) break;
            if (b > a + 1 && nums[b] == nums[b-1]) continue;
            
            int c = b + 1, d = length - 1;
            long sum = (long) target - nums[b];
            while (c < d) {
                if (nums[c] + nums[d] == sum) {
                    vector<int> res = {nums[b], nums[c], nums[d]};
                    result.push_back(res);
                    c++;
                    d--;
                }
                else if (nums[c] + nums[d] > sum) d--;
                else c++;

                while (c > b + 1 && nums[c]==nums[c-1] && c < d) c++;
                while (d < length-1 && nums[d]==nums[d+1] && c < d) d--;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-3,-2,-1,0,0,1,2,3};
    int target = 0;
    vector<vector<int>> result = solution.fourSum(nums, target);

    for (int i=0; i< result.size(); i++) {
        vector<int> v = result[i];
        for (int j=0; j<v.size(); j++) {
            cout << v[j] << "\t";
        }
        cout << "\n";
    }
    return 0;
}