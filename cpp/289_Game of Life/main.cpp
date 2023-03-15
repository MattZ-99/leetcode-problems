/* 289. Game of Life

According to Wikipedia's article: "The Game of Life, also known simply as Life,
 is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state:
 live (represented by a 1) or dead (represented by a 0). 
 Each cell interacts with its eight neighbors (horizontal, vertical, diagonal)
 using the following four rules (taken from the above Wikipedia article):

- Any live cell with fewer than two live neighbors dies as if caused by under-population.
- Any live cell with two or three live neighbors lives on to the next generation.
- Any live cell with more than three live neighbors dies, as if by over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell 
 in the current state, where births and deaths occur simultaneously. 
 Given the current state of the m x n grid board, return the next state.
 */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
// Memory Usage: 6.9 MB, less than 84.44% of C++ online submissions for Game of Life.

# include <iostream>
# include <vector>

using namespace std;

void outputBoard(vector<vector<int>>& board);

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size(), left, right, up, down;
        vector<vector<int>> liveNeighbours(m, vector<int>(n, 0));

        for (int e_i=0; e_i<m; e_i++) {
            if (e_i == 0) left = 0; else left = e_i - 1;
            if (e_i == m-1) right = e_i; else right = e_i + 1;

            for (int e_j=0; e_j<n; e_j++) {
                if (e_j == 0) up = 0; else up = e_j - 1;
                if (e_j == n-1) down = e_j; else down = e_j + 1;

                for (int n_i=left; n_i<=right; n_i++) {
                    for (int n_j=up; n_j<=down; n_j++) liveNeighbours[e_i][e_j] += board[n_i][n_j];
                }
            }
        }
        for (int e_i=0; e_i<m; e_i++) {
            for (int e_j=0; e_j<n; e_j++) {
                if(board[e_i][e_j] && (liveNeighbours[e_i][e_j] < 3 || liveNeighbours[e_i][e_j] > 4))
                    board[e_i][e_j] = 0;
                else if (!board[e_i][e_j] && liveNeighbours[e_i][e_j] == 3) 
                    board[e_i][e_j] = 1;
            }
        }
    }
};

void outputBoard(vector<vector<int>>& board) {
    for (vector<int> row: board) {
        for (int e: row) cout << e << ' ';
        cout << '\n';
    }
    cout << '\n';
}
int main() {
    printf("#%s\n\n", "289. Game of Life");
    vector<vector<int>> board{vector<int>{0,1,0}, vector<int>{0,0,1},
        vector<int>{1,1,1}, vector<int>{0,0,0}
    };
    outputBoard(board);

    Solution s;
    s.gameOfLife(board);
    outputBoard(board);

    return 1;
}