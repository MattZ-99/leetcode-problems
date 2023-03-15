/* 347. Top K Frequent Elements
Medium

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order. */

// Runtime: 37 ms, faster than 41.38% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.5 MB, less than 90.45% of C++ online submissions for Top K Frequent Elements.

# include <iostream>
# include <vector>
# include <queue>
# include <unordered_map>

using namespace std;


class Solution {
    class myComparisonGreater {
    public:
        bool operator() (pair<int, int>& first, pair<int, int>& second) {return first.second > second.second;}
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent_map;
        for (auto n: nums) frequent_map[n]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparisonGreater> min_heap;
        for (auto e: frequent_map) {
            min_heap.push(e);
            if (min_heap.size() > k) min_heap.pop();
        }

        vector<int> res;
        for (int i=0; i<k; i++) {
            res.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return res;
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
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    // Solution.
    Solution solution;
    vector<int> result = solution.topKFrequent(nums, k);
    print_vector(result); cout << endl;

    return 0;
}