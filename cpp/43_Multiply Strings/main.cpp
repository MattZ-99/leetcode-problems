#include <iostream>
#include <string>

using namespace std;

// Runtime: 4 ms, faster than 89.06% of C++ online submissions for Multiply Strings.
// Memory Usage: 6.3 MB, less than 92.91% of C++ online submissions for Multiply Strings.

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int l1 = num1.size(), l2 = num2.size();
        int l = l1 + l2;
        string res(l, '0');
        int val;
        for(int i=0; i<l1; i++) {
            for(int j=0; j<l2; j++) {
                int p = l - 1 - i - j;
                val = (num1[l1 - i - 1] - '0') * (num2[l2 - j - 1] - '0');
                while(p >= 0) {
                    val += res[p] - '0';
                    res[p] = (val % 10) + '0';
                    if(val < 10) break;
                    val /= 10;
                    p--;
                }
            }
        }
        if(res[0] == '0') res.erase(res.begin());
        return res;
    }
};

int main() {
    string num1 = "2", num2 = "3";
    Solution solution;
    cout << solution.multiply(num1, num2) << endl;
    return 0;
}