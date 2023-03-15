#include <iostream>
#include <climits>
#include <bitset>
using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Divide Two Integers.
// Memory Usage: 5.9 MB, less than 30.24% of C++ online submissions for Divide Two Integers.

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) {
            if(dividend < 0) return INT_MIN;
            return INT_MAX;
        }
        if(divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        if(dividend == 0) return 0;

        int res = 0;
        int flag = 0;
        if(dividend > 0 && divisor > 0) flag = 1;
        else if (dividend > 0 && divisor < 0) {
            flag = 0;
            if (divisor == INT_MIN) return 0;
            divisor = -divisor;
        }
        else if(divisor < 0) {
            flag = 1;
            if (divisor == INT_MIN && dividend == INT_MIN) return 1;
            if (divisor == INT_MIN) return 0;
            divisor = -divisor;
            if (dividend == INT_MIN) {
                dividend += divisor;
                res++;
            }
            dividend = -dividend;
        }     
        else{
            flag = 0;
            if (dividend == INT_MIN) {
                dividend += divisor;
                res++;
            }
            dividend = -dividend;
        }

        while (dividend >= divisor) {
            int second = divisor;
            int t = 1;
            while ((dividend>>2) >= second) {
                second <<= 2;
                t <<= 2;
            }
            dividend -= second;
            res += t;
        }
        if (flag) return res;
        return -res;
    }
};

int main() {
    int dividend = 2147483647;
    int divisor = 2;
    Solution solution;
    cout << solution.divide(dividend, divisor) << endl;

    // int a = INT_MIN;
    // a = a>>2;
    // cout << a <<endl;
    // cout<<bitset<sizeof(int)*8>(a)<<endl;

    return 0;
}