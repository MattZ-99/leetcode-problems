/* 349. Intersection of Two Arrays
Easy

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order. */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Intersection of Two Arrays.
// Memory Usage: 10.3 MB, less than 61.10% of C++ online submissions for Intersection of Two Arrays.

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> element_set(nums1.begin(), nums1.end());
        vector<int> intersection;

        for (auto n: nums2) {
            if (element_set.find(n) != element_set.end()) {
                intersection.push_back(n);
                element_set.erase(n);
            }
        }

        return intersection; 
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
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};

    // Solution.
    Solution solution;
    vector<int> intersection = solution.intersection(nums1, nums2);
    print_vector(intersection);
    return 0;
}