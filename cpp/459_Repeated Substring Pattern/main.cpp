/* 459. Repeated Substring Pattern
Easy

Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. */

// Brute force.
// TC: O(n^2)
// SC: O(1)
// Runtime: 14 ms, faster than 98.33% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 9.5 MB, less than 93.08% of C++ online submissions for Repeated Substring Pattern.

// String search.
// TC: O(n)
// SC: O(n)
// Runtime: 16 ms, faster than 97.09% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 11.9 MB, less than 83.35% of C++ online submissions for Repeated Substring Pattern.

// KMP algorithm.
// TC: O(n)
// SC: O(n)
// Runtime: 35 ms, faster than 72.81% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 15.1 MB, less than 41.56% of C++ online submissions for Repeated Substring Pattern.

// KMP boost. (Use the prefix table only.)
// TC: O(n)
// SC: O(n)
// Runtime: 62 ms, faster than 46.80% of C++ online submissions for Repeated Substring Pattern.
// Memory Usage: 12.5 MB, less than 79.15% of C++ online submissions for Repeated Substring Pattern.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<int> get_prefix_table(string & s) {
        vector<int> pi(s.length()); pi[0] = 0;
        int j = 0;
        for (int i=1; i<s.length(); i++) {
            while (j>0 && s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    int find_first_substring(string & t, string & s) {
        vector<int> next = get_prefix_table(s);

        int j = 0;
        for (int i = 0; i < t.length(); i++) {
            while (j > 0 && t[i] != s[j]) j = next[j - 1];
            if (t[i] == s[j]) j++;

            if (j == s.length()) return i;
        }
        return -1;
    }
    
    bool brute_force(string & s) {
        int max_len_block = s.length() / 2;
        bool flag = 1;
        for (int i = 1; i <= max_len_block; i++) {
            if (s.length() % i != 0) continue;
            
            for(int j = i; j < s.length(); j++) {
                if (s[j] != s[j - i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) return true;
            flag = 1;
        }
        return false;
    }

    bool string_match(string & s) {
        string t = s;
        t.erase(t.begin()) ; t += s; t.pop_back();
        auto n = t.find(s);
        if (n == string::npos) return false;
        return true;
    }

    bool kmp(string & s) {
        string t = s;
        t.erase(t.begin()) ; t += s; t.pop_back(); 
        auto n = find_first_substring(t, s);
         if(n == -1) return false;
         return true;
    }

    bool kmp_boost(string & s) {
        vector<int> next = get_prefix_table(s);
        int len_s = s.length(), len_block = len_s - next[len_s - 1];
        if (len_block < len_s && len_s % len_block == 0) return true;
        return false;
    }

public:
    bool repeatedSubstringPattern(string s) {
        if (s.length() <= 1) return false;

        // return brute_force(s);
        // return string_match(s);
        // return kmp(s);
        return kmp_boost(s);
    }
};

int main() {
    // Inputs.
    string s = "abab";

    // Solution.
    Solution solution;
    cout << solution.repeatedSubstringPattern(s) << endl;

    return 0;
}