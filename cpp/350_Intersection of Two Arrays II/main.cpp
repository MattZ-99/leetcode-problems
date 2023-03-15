/* 350. Intersection of Two Arrays II
Easy

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
 */

// Runtime: 3 ms, faster than 97.50% of C++ online submissions for Intersection of Two Arrays II.
// Memory Usage: 10.6 MB, less than 37.78% of C++ online submissions for Intersection of Two Arrays II.
 
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> element_set(nums1.begin(), nums1.end());

        vector<int> intersection;

        for (auto n: nums2) {
            multiset<int>::iterator it_n = element_set.find(n);
            if (it_n != element_set.end()) {
                intersection.push_back(n);
                element_set.erase(it_n);
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
    vector<int> intersection = solution.intersect(nums1, nums2);
    print_vector(intersection);
    return 0;
}