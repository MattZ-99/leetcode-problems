/* 383. Ransom Note
Easy

Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote. */

// Runtime: 21 ms, faster than 66.81% of C++ online submissions for Ransom Note.
// Memory Usage: 8.7 MB, less than 90.18% of C++ online submissions for Ransom Note.

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() < ransomNote.size()) return false;
        
        unordered_map<char, int> memory_map;
        unordered_map<char, int>::iterator it;
        for (auto c: magazine) {
            it = memory_map.find(c);
            if (it == memory_map.end()) memory_map.insert({c, 1});
            else it->second++;
        }

        for (auto c: ransomNote) {
            it = memory_map.find(c);
            if (it == memory_map.end()) return false;
            else {
                if (it->second == 1) memory_map.erase(it);
                else it->second--;
            }
        }
        return true;
    }
};

int main() {
    // Inputs.
    // string ransomNote = "a", magazine = "b";
    string ransomNote = "aa", magazine = "aab";

    // Solution.
    Solution solution;
    cout << "Can construct? : " << solution.canConstruct(ransomNote, magazine) << endl;
}