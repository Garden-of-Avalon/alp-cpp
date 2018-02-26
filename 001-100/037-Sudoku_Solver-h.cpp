// Write a program to solve a Sudoku puzzle by filling the empty cells.

// Empty cells are indicated by the character '.'.

// You may assume that there will be only one unique solution.

// back tracking
class Solution {
    bool isValid(vector<vector<char>> &board, int &i, int &j, char &c) {
        for (int p = 0; p < 9; ++p) {
            // positon in row, col, or block
            if (board[i][p] == c || board[p][j] == c ||
                board[i / 3 * 3 + p / 3][j / 3 * 3 + p % 3] == c)
                return false;
        }
        return true;
    }

    // backtracking
    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
        return true;
    }

  public:
    void solveSudoku(vector<vector<char>> &board) { solve(board); }
};

// optimized
// 1. use 3 maps
// 2. start from i, j
class Solution {
    array<bitset<9>, 9> row = array<bitset<9>, 9>(), col = row, block = row;

    bool isValid(const int &i, const int &j, const int &p) {
        return !row[i].test(p) && !col[j].test(p) &&
               !block[i / 3 * 3 + j / 3].test(p);
    }

    void set_reset(const int &i, const int &j, const int &p) {
        row[i].flip(p);
        col[j].flip(p);
        block[i / 3 * 3 + j / 3].flip(p);
    }

    // backtracking
    bool solvefromij(vector<vector<char>> &board, int i, int j) {
        while (i < 9) {
            while (j < 9) {
                if (board[i][j] == '.') {
                    for (int p = 0; p < 9; ++p)
                        if (isValid(i, j, p)) {
                            board[i][j] = '1' + p;
                            set_reset(i, j, p);
                            if (solvefromij(board, i, j + 1))
                                return true;
                            set_reset(i, j, p);
                            board[i][j] = '.';
                        }
                    // board[i][j] cannot be filled
                    return false;
                }
                ++j;
            }
            // reset j
            j = 0;
            ++i;
        }
        return true;
    }

  public:
    void solveSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')
                    set_reset(i, j, board[i][j] - '1');

        solvefromij(board, 0, 0);
    }
};
