#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Runtime: 4 ms, faster than 92.11% of C++ online submissions for Simplify Path.
// Memory Usage: 6.7 MB, less than 99.27% of C++ online submissions for Simplify Path.

class Solution {
public:
    string simplifyPath(string path) {
        stack<int> file;
        int length = path.length(), startFlag = 0; 
        for(int i=0; i<length; i++) {
            if(startFlag == 0) {
                if(path[i] == '/') {file.push(i); startFlag = 1;}
                else if(i == length-1) file.push(i+1);
                continue;
            }
            
            if(path[i] == '/') continue;
            if(path[i] == '.') {
                if(i == length-1 || path[i+1] == '/') {i++; continue;}
                if(path[i+1] == '.') {
                    if(i == length-2 || path[i+2] == '/') {
                        i += 2;
                        if(file.top() != 0) {file.pop(); file.pop();}
                        continue;
                    }
                }
            }
            startFlag = 0; file.push(i-1);
            if(i == length-1) file.push(i+1);
        }
        file.push(length);
        int left, right;
        while(!file.empty()) {
            right = file.top(); file.pop(); left = file.top(); file.pop();
            path.erase(path.begin()+left, path.begin()+right);
        }
        if(path.length() == 0) path = "/";
        return path;
    }
};

int main() {
    string path = "/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e" ; // ;
    Solution s;
    cout << s.simplifyPath(path) << endl;
}