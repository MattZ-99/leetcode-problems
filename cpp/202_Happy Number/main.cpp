/* 202. Happy Number
Easy

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
 */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Happy Number.
// Memory Usage: 6.3 MB, less than 25.78% of C++ online submissions for Happy Number.

#include <iostream>
#include <math.h>
#include <unordered_set>

using namespace std;

class Solution {
    int calculate_digital_square(int n) {
        int res = 0;
        while(n > 0) {
            res += pow((n % 10), 2);
            n /= 10;
        }
        return res;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> vals;
        while (n != 1) {
            if (vals.find(n) != vals.end()) return false;

            vals.insert(n);
            n = calculate_digital_square(n);
        }
        return true;
    }
};

int main() {
    // Inputs.
    int n;
    cout << "Input n: "; cin >> n;

    // Solution.
    Solution solution;
    cout << "Is happy number? : " << solution.isHappy(n) << endl;

}
