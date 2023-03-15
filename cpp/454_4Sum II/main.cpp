/* 454. 4Sum II
Medium

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0 */

// Runtime: 344 ms, faster than 74.43% of C++ online submissions for 4Sum II.
// Memory Usage: 24.4 MB, less than 78.88% of C++ online submissions for 4Sum II.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> memory_map;
        unordered_map<int, int>::iterator it_pos;
        for (auto n1: nums1) {
            for(auto n2: nums2) {
                it_pos = memory_map.find(n1 + n2);
                if (it_pos == memory_map.end()) memory_map.insert({n1 + n2, 1});
                else it_pos->second++;
            }
        }

        int res = 0;
        for (auto n3: nums3) {
            for (auto n4: nums4) {
                it_pos = memory_map.find(-n3 - n4);
                if (it_pos != memory_map.end()) res += it_pos->second;
            }
        }
        return res;
    }
};

int main() {
    // Inputs.
    vector<int>nums1{1, 2}, nums2{-2, -1}, nums3{-1, 2}, nums4 = {0,2};

    // Solution.
    Solution solution;
    cout << "Number of tuples: " << solution.fourSumCount(nums1, nums2, nums3, nums4) << endl;
}