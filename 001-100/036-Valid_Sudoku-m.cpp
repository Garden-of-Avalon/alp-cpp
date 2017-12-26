// Determine if a Sudoku is valid, according to: Sudoku Puzzles
//
// The Rules:
// Each row must have the numbers 1-9 occuring just once.
// Each column must have the numbers 1-9 occuring just once.
// 1-9 must occur just once in each of the 9 sub-boxes of the grid.
//
// The Sudoku board could be partially filled, where empty cells are filled with
// the character '.'.
// Note: A valid Sudoku board (partially filled) is not necessarily solvable.
// Only the filled cells need to be validated.

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        vector<bitset<9>> rows(9), cols(9), boxes(9);
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.') {
                    int t = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    if (rows[i].test(t) || cols[j].test(t) || boxes[k].test(t))
                        return false;
                    rows[i].set(t);
                    cols[j].set(t);
                    boxes[k].set(t);
                }
        return true;
    }
};