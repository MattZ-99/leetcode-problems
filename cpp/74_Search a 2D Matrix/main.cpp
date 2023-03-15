# include <iostream>
# include <cstdio>
# include <vector>

using namespace std;

// Runtime: 3 ms, faster than 88.23% of C++ online submissions for Search a 2D Matrix.
// Memory Usage: 9.3 MB, less than 99.98% of C++ online submissions for Search a 2D Matrix.

void outprint_matrix(vector<vector<int>>& matrix) {
    // print matrix.
    for (vector<int> row : matrix) {
        for (int i : row) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

class Solution {
private:
    bool bipartiteSearch_column(vector<vector<int>>& matrix, int target, 
        vector<vector<int>>::iterator it_begin, int search_length) {

            if (search_length == 0) return false;

            vector<vector<int>>::iterator it_mid = it_begin + search_length/2;
            int row_min = (*it_mid).front(); int row_max = (*it_mid).back();

            if (row_min <= target && row_max >= target) 
                return bipartiteSearch_row((*it_mid), target);
            if (row_min > target) 
                return bipartiteSearch_column(matrix, target, it_begin, search_length/2);
            if (row_max < target)
                return bipartiteSearch_column(matrix, target, it_mid+1, search_length - search_length/2 - 1);
            return false;
        }
    
    bool bipartiteSearch_row(vector<int> & row, int target) {

        int search_length = row.size();
        vector<int>::iterator it_begin=row.begin(), it_mid;

        while (search_length > 0) {
            it_mid = it_begin + search_length/2;
            if ((*it_mid) == target) return true;
            if ((*it_mid) > target) {search_length /= 2; continue; }
            if ((*it_mid) < target) {
                it_begin = it_mid + 1;
                search_length = search_length - search_length/2 - 1;
            }
        }
        return false;
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return bipartiteSearch_column(matrix, target, matrix.begin(), matrix.size());
    }
};

int main(int argc, char *argv[]) {
    printf("#%s\n\n", "74. Search a 2D Matrix");

    vector<vector<int>> matrix{vector<int>{1,3,5,7}, vector<int>{10,11,16,20}, vector<int>{23,30,34,60}};
    outprint_matrix(matrix);
    
    int target = 3;
    if (argc>1) target = atoi(argv[1]);
    printf("target: %d\n", target);

    Solution s;
    printf("target=%d in matrix: %s", target, s.searchMatrix(matrix, target)?"true":"false");

    return 1;
}