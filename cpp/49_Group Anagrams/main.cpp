// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.

// Runtime: 32 ms, faster than 92.05% of C++ online submissions for Group Anagrams.
// Memory Usage: 19.6 MB, less than 81.01% of C++ online submissions for Group Anagrams.

# include <iostream>
# include <cstdio>
# include <vector>
# include <string>
# include <algorithm>
# include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string & str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto & i_pair : map) result.push_back(i_pair.second);
        return result;
    }
};

void output_string_vector(vector<string> & strs) {
    for (string str:strs) cout << str << ' ';
}

int main() {
    printf("#%s\n\n", "49. Group Anagrams");

    vector<string> strs{(string) "eat", (string) "tea", (string) "tan", (string) "ate", (string) "nat", (string) "bat"};
    // vector<string> strs;

    for (string & str:strs) {
        cout << str << ' ';
    }
    cout << '\n' << endl;

    Solution s;
    vector<vector<string>> result = s.groupAnagrams(strs);
    for (vector<string> & r : result) {
        output_string_vector(r);
        cout << '\n';
    }

    return 1;
}