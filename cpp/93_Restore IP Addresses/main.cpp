#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Restore IP Addresses.
// Memory Usage: 6.8 MB, less than 42.51% of C++ online submissions for Restore IP Addresses.

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if(s.size() < 4) return result;
        string str;
        str.push_back(s[0]);
        restoreIpAddressesKernel(s, result, str, 0, 1, 3);
        return result;
    }
    void restoreIpAddressesKernel(string& s, vector<string>& result, 
        string& str, int left, int right, int flag) {
        
        if(!checkValid(s, left, right)) return;
        if(right == s.size()) {if(flag == 0) result.push_back(str); return;}

        str.push_back(s[right]); right++;
        restoreIpAddressesKernel(s, result, str, left, right, flag);
        str.pop_back(); right--;

        if(flag == 0) return;

        str.push_back('.'); str.push_back(s[right]);
        left = right; right = left + 1;
        flag--;
        restoreIpAddressesKernel(s, result, str, left, right, flag);
        str.pop_back(); str.pop_back();
    }

    bool checkValid(string& s, int left, int right) {
        if(right - left == 1) return 1;
        if(s[left] == '0') return 0;
        int sum = 0;
        for(int i=left; i<right; i++) sum = sum * 10 + (s[i] - '0');
        if(sum>255) return 0;
        return 1;
    }
};

int main() {
    string s = "101023";
    Solution solution;
    vector<string> res = solution.restoreIpAddresses(s);
    for (int i=0; i<res.size(); i++) cout << res[i] << endl;
    return 0;
}