#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6 MB, less than 95.23% of C++ online submissions for Decode Ways.

class Solution {
public:
    int numDecodings(string s) {
        int length = s.size() - 1;
        if(length == 0) return checkValid1(s, 0);
        if(length == 1) return checkValid2(s, 0) + checkValid1(s, 0) * checkValid1(s, 1);
        vector<int> memory(length + 1, 0);
        memory[0] = checkValid1(s, length);
        memory[1] = checkValid2(s, length - 1) + checkValid1(s, length - 1) * checkValid1(s, length);

        for(int i=2; i<=length; i++) {
           memory[i] = checkValid1(s, length - i) * memory[i-1] + checkValid2(s, length - i) * memory[i-2];
        }
        return memory[length];
    }
    int checkValid1(string & s, int left) {
        if(s[left] == '0') return 0;
        return 1;
    }
    int checkValid2(string & s, int left) {
        if(s[left] == '0') return 0;
        if(((s[left] - '0') * 10 + (s[left+1] - '0')) < 27) return 1;
        return 0;
    }   
};

int main() {
    string s = "2101";
    Solution solution;
    cout << solution.numDecodings(s) << endl;
    return 0;
}