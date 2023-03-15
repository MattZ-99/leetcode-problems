/* 30. Substring with Concatenation of All Words
Hard

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order. */

// Runtime: 74 ms, faster than 90.55% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 34.4 MB, less than 60.44% of C++ online submissions for Substring with Concatenation of All Words.

# include <iostream>
# include <vector>
# include <string>
# include <unordered_map>

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
    vector<int> findSubstring(string s, vector<string>& words) {
        int len_ws = words.size(), len_w = words[0].length(), len_s = s.length();
        if (len_s < len_w * len_ws) return {};

        unordered_map<string, int> word_count;
        for (auto & w: words) ++word_count[w];
      
        vector<int> res;
        for (int start_point = 0; start_point < len_w && start_point + len_w * len_ws <= len_s; ++start_point) {
            unordered_map<string, int> count_copy = word_count;

            // Create the sliding window.
            for (int pos = start_point; pos < start_point + len_w * len_ws; pos+=len_w) {
                if (--count_copy[s.substr(pos, len_w)] == 0) count_copy.erase(s.substr(pos, len_w));
            }
            if (count_copy.empty()) res.push_back(start_point);

            // Move the window.
            for (int pos = start_point; pos + len_w * (len_ws + 1) <= len_s; pos += len_w) {
                if (++count_copy[s.substr(pos, len_w)] == 0) count_copy.erase(s.substr(pos, len_w));              
                if (--count_copy[s.substr(pos + len_w * len_ws, len_w)] == 0) count_copy.erase(s.substr(pos + len_w * len_ws, len_w));
         
                if (count_copy.empty()) res.push_back(pos + len_w);
            }
        }
        return res;
    }
};

int main () {
    // Inputs.
    // string s = "barfoothefoobarman";
    // vector<string> words = {"foo","bar"};
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};

    // Solution.
    Solution solution;
    vector<int> res = solution.findSubstring(s, words);
    print_vector(res); cout << endl;

    return 0;
}