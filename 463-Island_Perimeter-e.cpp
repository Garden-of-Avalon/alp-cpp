// You are given a map in form of a two-dimensional integer grid where 1
// represents land and 0 represents water. Grid cells are connected
// horizontally/vertically (not diagonally). The grid is completely surrounded
// by water, and there is exactly one island (i.e., one or more connected land
// cells). The island doesn't have "lakes" (water inside that isn't connected to
// the water around the island). One cell is a square with side length 1. The
// grid is rectangular, width and height don't exceed 100. Determine the
// perimeter of the island.
// Example:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
// Answer: 16

class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int height = grid.size(), width = height ? grid[0].size() : 0;
        if (!(height && width))
            return 0;

        int result = 0;
        int i, j, startx, starty;
        [&] {
            for (i = 0; i < height; ++i)
                for (j = 0; j < width; ++j)
                    if (grid[i][j]) {
                        startx = --i;
                        starty = --j;
                        return; // break 2 loops
                    }
        }();

        char dir = 'r'; // direction left, right, up, down
        do {
            switch (dir) {
            case 'r':
                ++j;
                while (j < width && grid[i + 1][j] &&
                       (i > -1 ? !grid[i][j] : 1)) {
                    ++result;
                    ++j;
                }
                if (j == width || !grid[i + 1][j]) {
                    dir = 'd';
                } else {
                    dir = 'u';
                    ++i;
                    --j;
                }
                break;

            case 'd':
                ++i;
                while (i < height && grid[i][j - 1] &&
                       (j < width ? !grid[i][j] : 1)) {
                    ++result;
                    ++i;
                }
                if (i == height || !grid[i][j - 1]) {
                    dir = 'l';
                } else {
                    dir = 'r';
                    --i;
                    --j;
                }
                break;

            case 'l':
                --j;
                while (j > -1 && grid[i - 1][j] &&
                       (i < height ? !grid[i][j] : 1)) {
                    ++result;
                    --j;
                }
                if (j == -1 || !grid[i - 1][j]) {
                    dir = 'u';
                } else {
                    dir = 'd';
                    --i;
                    ++j;
                }
                break;

            case 'u':
                --i;
                while (i > -1 && grid[i][j + 1] && (j > -1 ? !grid[i][j] : 1)) {
                    ++result;
                    --i;
                }
                if (i == -1 || !grid[i][j + 1]) {
                    dir = 'r';
                } else {
                    dir = 'l';
                    ++i;
                    ++j;
                }
                break;
            }
        } while (i != startx || j != starty);
        return result;
    }
};