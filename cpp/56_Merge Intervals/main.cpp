#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), sortFunc);
//         vector<vector<int>>::iterator it = intervals.begin();
//         while(it < intervals.end() - 1) {
//             if((*it)[1] < (*(it + 1))[0]) {it++; continue;}
//             (*(it + 1))[0] = (*it)[0];
//             (*(it + 1))[1] = max((*(it + 1))[1], (*it)[1]);
//             it = intervals.erase(it);         
//         }
//         return intervals;
//     }

//     static bool sortFunc(const vector<int>& v1, const vector<int>& v2) {
//         return v1.front() < v2.front();
//     }
// };

// Runtime: 16 ms, faster than 87.73% of C++ online submissions for Merge Intervals.
// Memory Usage: 14.2 MB, less than 80.00% of C++ online submissions for Merge Intervals.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int length = intervals.size();
        if(length == 0) return res;
        sort(intervals.begin(), intervals.end(), sortFunc);

        int start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < length; i++) {
            if(end < intervals[i][0]) {
                vector<int> tmp = {start, end};    
                res.push_back(tmp);
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            if(end < intervals[i][1]) end = intervals[i][1];
        }
        vector<int> tmp = {start, end};    
        res.push_back(tmp);
        return res;
    }

    static bool sortFunc(const vector<int>& v1, const vector<int>& v2) {
        return v1.front() < v2.front();
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    Solution solution;
    vector<vector<int>> result = solution.merge(intervals);

    for(int i=0; i<result.size(); i++) {
        vector<int> r = result[i];
        for (int j=0; j<r.size(); j++) cout << r[j] << ' ';
        cout << '\n';
    }

    return 0;
}