# include <iostream>
# include <vector>
# include <cstdio>

using namespace std;

// Runtime: 12 ms, faster than 91.60% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.1 MB, less than 81.90% of C++ online submissions for Set Matrix Zeroes.

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
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // judge whether 0 in first column.
        bool first_col_zero = false;
        for (vector<int> & row : matrix) {
            if (row[0] == 0) {first_col_zero = true; break;}
        }

        // go through the matrix, check zero and set row-0 and column-0 as flag pos.
        for (vector<int> & it_row : matrix) {
            for (int i_col=1; i_col<it_row.size(); i_col++) {
                if (it_row[i_col] == 0) {
                    it_row[0] = 0;
                    matrix[0][i_col] = 0;
                }
            }
        }

        // set columns zero.
        vector<int> & row_0 = matrix[0];
        for (int i_col=1; i_col<row_0.size(); i_col++) {
            if (row_0[i_col] == 0) {
                for (vector<int> & row : matrix) {row[i_col] = 0;}
            }
        }
        // set rows zero.
        for (vector<int> & row : matrix) {
            if (row[0] == 0) {
                for (int & col : row) {col = 0; }
            }
        }
        // set first column zero.
        if (first_col_zero) {
            for (vector<int> & row : matrix) {row[0] = 0; }
        }

        outprint_matrix(matrix);
    }
};

int main() {
    printf("#%s", "73. Set Matrix Zeroes\n\n");

    vector<vector<int>> matrix{vector<int>{0,1,2,0}, vector<int>{3,4,5,2}, vector<int>{1,3,1,5}};
    outprint_matrix(matrix);

    Solution s;
    s.setZeroes(matrix);
}