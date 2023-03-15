#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int length = intervals.size();
//         if(length == 0) {intervals.push_back(newInterval); return intervals;}
//
//         vector<vector<int>>::iterator it = intervals.begin();
//         while (it<intervals.end()) {
//             if(newInterval[0] > (*it)[1]) {it++; continue;}
//             if(newInterval[1] < (*it)[0]) {intervals.insert(it, newInterval); return intervals;}
//             newInterval[0] = min(newInterval[0], (*it)[0]);
//             newInterval[1] = max(newInterval[1], (*it)[1]);
//             intervals.erase(it);
//         }
//         intervals.insert(it, newInterval);
//         return intervals;
//     }
// };

// Runtime: 12 ms, faster than 89.51% of C++ online submissions for Insert Interval.
// Memory Usage: 17 MB, less than 62.40% of C++ online submissions for Insert Interval.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int length = intervals.size();
        if(length == 0) {intervals.push_back(newInterval); return intervals;}
        vector<int> result(2);
        binarySearch(intervals, newInterval, 0 , length-1, result);
        intervals.erase(intervals.begin()+result[0], intervals.begin()+result[1]+1);
        intervals.insert(intervals.begin()+result[0], newInterval);
        return intervals;

    }

    void binarySearch(vector<vector<int>>& intervals, vector<int>& newInterval, int left, int right, vector<int>& result) {
        if(left > right) {result[0] = left; result[1] = right; return;}
        int mid = (left+right)/2;
        if(newInterval[0] > intervals[mid][1]) {binarySearch(intervals, newInterval, mid+1, right, result); return;}
        if(newInterval[1] < intervals[mid][0]) {binarySearch(intervals, newInterval, left, mid - 1, result); return;}
        if(newInterval[0] >= intervals[mid][0]) {newInterval[0] = intervals[mid][0]; result[0] = mid;}
        else searchLeft(intervals, newInterval, left, mid-1, result);
        if(newInterval[1]<= intervals[mid][1]) {newInterval[1] = intervals[mid][1]; result[1] = mid;}
        else searchRight(intervals, newInterval, mid+1, right, result);
    }
    void searchLeft(vector<vector<int>>& intervals, vector<int>& newInterval, int left, int right, vector<int>& result) {
        if(left>right) {result[0] = left; return;}
        int mid = (left+right)/2;
        if(newInterval[0] > intervals[mid][1]) {searchLeft(intervals, newInterval, mid+1, right, result); return;}
        if(newInterval[0] < intervals[mid][0]) {searchLeft(intervals, newInterval, left, mid-1, result); return;}
        newInterval[0] = intervals[mid][0]; result[0] = mid;
    }
    void searchRight(vector<vector<int>>& intervals, vector<int>& newInterval, int left, int right, vector<int>& result) {
        if(left>right) {result[1] = right; return;}
        int mid = (left+right)/2;
        if(newInterval[1] > intervals[mid][1]) {searchRight(intervals, newInterval, mid+1, right, result); return;}
        if(newInterval[1] < intervals[mid][0]) {searchRight(intervals, newInterval, left, mid-1, result); return;}
        newInterval[1] = intervals[mid][1]; result[1] = mid;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2, 5};
    Solution solution;
    vector<vector<int>> result = solution.insert(intervals, newInterval);

    for(int i=0; i<result.size(); i++) {
        vector<int> r = result[i];
        for (int j=0; j<r.size(); j++) cout << r[j] << ' ';
        cout << '\n';
    }

    return 0;
}