/* 239. Sliding Window Maximum
Hard


You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window. */

// Runtime: 713 ms, faster than 39.31% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 134.7 MB, less than 63.19% of C++ online submissions for Sliding Window Maximum.

# include <iostream>
# include <vector>
# include <deque>

using namespace std;

class MonotonousQueue {
    deque<int> monotonous_queue;

public:
    void push(int value) {
        while (true) {
            if (monotonous_queue.size() == 0 || monotonous_queue.back() >= value) {
                monotonous_queue.push_back(value);
                break;
            }
            monotonous_queue.pop_back();
        }
    }

    void pop(int value) {
        if (monotonous_queue.front() == value) monotonous_queue.pop_front();
    }

    int front() {
        return monotonous_queue.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MonotonousQueue monotonous_queue;
        for (int i=0; i<k; i++) monotonous_queue.push(nums[i]);
        result.push_back(monotonous_queue.front());

        for (int i=k; i<nums.size(); i++) {
            monotonous_queue.pop(nums[i-k]);
            monotonous_queue.push(nums[i]);
            result.push_back(monotonous_queue.front());
        }

        return result;
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
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    // Solution.
    Solution solution;
    vector<int> result = solution.maxSlidingWindow(nums, k); 
    print_vector(result); cout << endl;

    return 0;
}