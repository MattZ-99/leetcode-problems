/* 344. Reverse String
Easy

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory. */

// Runtime: 23 ms, faster than 92.84% of C++ online submissions for Reverse String.
// Memory Usage: 23.2 MB, less than 75.63% of C++ online submissions for Reverse String.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0, second = s.size() - 1;

        while(first < second) {
            swap(s[first], s[second]);
            first++; second--;
        }
    }
};

template <typename T>
void print_vector(vector<T>& nums) {
    cout << "[ ";
    for (auto n: nums) cout << n << ' ';

    cout << ']';
}

int main() {
    // Inputs.
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    // Solution.
    Solution solution;
    solution.reverseString(s);
    print_vector(s); cout << '\n';   

    return 0;
}