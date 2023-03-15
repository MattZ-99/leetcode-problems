# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sort Colors.
// Memory Usage: 8.3 MB, less than 70.47% of C++ online submissions for Sort Colors.

class Solution {
private:
    void set_color_value(vector<int>::iterator& it_n, int n, int val) {
        while (n>0) {(*it_n) = val; n--; it_n++; }
    }

public:
    void sortColors(vector<int>& nums) {
        vector<int> count_color{0, 0, 0};
        for (int num : nums) {count_color[num] += 1; }
        
        vector<int>::iterator it_n = nums.begin();

        for (int i=0; i<count_color.size(); i++) {set_color_value(it_n, count_color[i], i); }
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
