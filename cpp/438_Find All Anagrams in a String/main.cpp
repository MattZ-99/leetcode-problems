/* 438. Find All Anagrams in a String
Medium

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 */

// Runtime: 8 ms, faster than 98.81% of C++ online submissions for Find All Anagrams in a String.
// Memory Usage: 8.5 MB, less than 91.02% of C++ online submissions for Find All Anagrams in a String.

# include <iostream>
# include <string>
# include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>& nums) {
    cout << "[ ";
    for (auto n: nums) {
        cout << n << ' ';
    }
    cout << ']';
}

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        if (len_p > len_s) return {};

        vector<int> res, letter_differ(26, 0);
        
        // Count the difference of letters between p and the first len_p letters of s.
        for (int i = 0; i < len_p; ++i) {
            letter_differ[s[i] - 'a']++;
            letter_differ[p[i] - 'a']--;
        }

        // Count the number of letters that are different.
        int num_differ = 0;
        for (int i = 0; i < 26; ++i) {
            if (letter_differ[i] != 0) num_differ++;
        }

        // If the number of letters that are different is 0, then the first len_p letters of s is an anagram of p.
        if (num_differ == 0) res.push_back(0);

        // Check the rest of the letters in s.
        for (int i = len_p; i < len_s; ++i) {
            // Delete the first letter in the sliding window.
            if (letter_differ[s[i - len_p] - 'a']-- == 0) num_differ++;
            else if (letter_differ[s[i - len_p] - 'a'] == 0) num_differ--;

            // Add the last letter to the sliding window.
            if (letter_differ[s[i] - 'a']++ == 0) num_differ++;
            else if  (letter_differ[s[i] - 'a'] == 0) num_differ--;
            
            // Add the window index into the result array, if num_differ == 0;
            if (num_differ == 0) res.push_back(i - len_p + 1);
        }

        return res;
    }
};

int main () {
    // Inputs.
    string s = "cbaebabacd", p = "abc";
    // string s = "bpaa", p = "aa";

    // Solution.
    Solution solution;
    vector<int> res = solution.findAnagrams(s, p);
    print_vector(res); cout << endl;

    return 0;
}