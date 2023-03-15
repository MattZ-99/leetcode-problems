#include <iostream>
#include <string>

using namespace std;


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
// Memory Usage: 6.4 MB, less than 78.68% of C++ online submissions for Length of Last Word.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int TotalLength = s.size();
        int LastWord = 0;
        int result = 0;

        for(int i=0; i<TotalLength; i++) {
            if (s[i]==' ') {result = cmpLength(result, LastWord); LastWord = 0;}
            else LastWord++;
        }
        result = cmpLength(result, LastWord);
        return result;
    }

    int cmpLength(int & result, int & LastWord) {
        if (LastWord == 0) return result;
        return LastWord;
    }
};


int main() {
    string s = "Today is a nice day";
    Solution solution;
    int result = solution.lengthOfLastWord(s);
    cout << result << endl;
    return 0;
}