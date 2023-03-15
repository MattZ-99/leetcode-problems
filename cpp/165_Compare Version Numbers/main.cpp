#include <iostream>
#include <string>

using namespace std;

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
// Memory Usage: 5.9 MB, less than 98.04% of C++ online submissions for Compare Version Numbers.

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1 = version1.length(), l2 = version2.length();
        int v1_left = 0, v1_right = 0, v2_left = 0, v2_right = 0;
        int v1_val, v2_val;
        while(true) {
            if(v1_right == l1 && v2_right == l2) break;
            v1_val = 0, v2_val = 0;
            while(v1_right < l1) {
                if(version1[v1_right] == '.') {
                    v1_right++;
                    v1_left = v1_right;
                    break;
                }
                v1_val = v1_val * 10 + (version1[v1_right] - '0');
                v1_right++;
            }
            while(v2_right < l2) {
                if(version2[v2_right] == '.') {
                    v2_right++;
                    v2_left = v2_right;
                    break;
                }
                v2_val = v2_val * 10 + (version2[v2_right] - '0');
                v2_right++;
            }
            if(v1_val < v2_val) return -1;
            if(v1_val > v2_val) return 1;
        }
        return 0;
    }
};

int main() {
    string version1 = "7.5.2.4", version2 = "7.5.3";
    Solution solution;
    cout << solution.compareVersion(version1, version2) << endl;
    return 1;
}