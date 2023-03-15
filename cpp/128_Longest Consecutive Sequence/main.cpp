// 128. Longest Consecutive Sequence
// 
// Given an unsorted array of integers nums, 
// return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

// Runtime: 70 ms, faster than 81.34% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 28.7 MB, less than 84.02% of C++ online submissions for Longest Consecutive Sequence.

# include <iostream>
# include <cstdio>
# include <vector>
# include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int max_length = 0;

        for (int n : num_set) {
            if (num_set.count(n-1)) continue;
            int cnt = n + 1;
            while (num_set.count(cnt)) cnt++;
            max_length = max(max_length, cnt - n);
        }
        return max_length;
    }
};

int main() {
    printf("#%s\n\n", "128. Longest Consecutive Sequence");

    vector<int> nums{0,3,7,2,5,8,4,6,0,1};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    return 1;
}