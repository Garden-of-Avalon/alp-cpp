//  According to the Wikipedia's article: "The Game of Life, also known simply
//  as Life, is a cellular automaton devised by the British mathematician John
//  Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or
// dead (0). Each cell interacts with its eight neighbors (horizontal, vertical,
// diagonal) using the following four rules (taken from the above Wikipedia
// article):

//     Any live cell with fewer than two live neighbors dies, as if caused by
//     under-population. Any live cell with two or three live neighbors lives on
//     to the next generation. Any live cell with more than three live neighbors
//     dies, as if by over-population.. Any dead cell with exactly three live
//     neighbors becomes a live cell, as if by reproduction.

// Write a function to compute the next state (after one update) of the board
// given its current state.

// Follow up:

//     Could you solve it in-place? Remember that the board needs to be updated
//     at the same time: You cannot update some cells first and then use their
//     updated values to update other cells. In this question, we represent the
//     board using a 2D array. In principle, the board is infinite, which would
//     cause problems when the active area encroaches the border of the array.
//     How would you address these problems?

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

class Solution {
  public:
    void gameOfLife(vector<vector<int>> &board) {
        int m = board.size(), n = m > 0 ? board[0].size() : 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                bool live = board[i][j] ? true : false;

                // check 8 neighbors
                for (int ii = 0; ii < 3; ++ii)
                    for (int jj = 0; jj < 3; ++jj)
                        if (i - 1 + ii >= 0 && i - 1 + ii < m &&
                            j - 1 + jj >= 0 && j - 1 + jj < n &&
                            !(ii == 1 && jj == 1) &&
                            board[i - 1 + ii][j - 1 + jj] > 0)
                            ++cnt;

                if (cnt)
                    board[i][j] = live ? cnt : -cnt;
            }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                switch (board[i][j]) {
                case 2:
                case 3:
                case -3:
                    board[i][j] = 1;
                    break;
                default:
                    board[i][j] = 0;
                }

        return;
    }
};

// other method
// use the 2nd-bit to store the new state