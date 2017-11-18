//  Initially, there is a Robot at position (0, 0). Given a sequence of its
//  moves, judge if this robot makes a circle, which means it moves back to the
//  original place.
// The move sequence is represented by a string. And each move is represent by a
// character. The valid robot moves are R (Right), L (Left), U (Up) and D
// (down). The output should be true or false representing whether the robot
// makes a circle.
// Example 1:
// Input: "UD"
// Output: true
// Example 2:
// Input: "LL"
// Output: false

class Solution {
  public:
    bool judgeCircle(string moves) {
        // unordered_set<pair<int, int>> path;
        // path.insert({0, 0});
        int i = 0, j = 0;
        for (auto &c : moves) {
            switch (c) {
            case 'L':
                --j;
                break;
            case 'R':
                ++j;
                break;
            case 'U':
                ++i;
                break;
            case 'D':
                --i;
                break;
            }
            // if (!path.insert({i, j}).second)
            //     return true;
        }
        // return false;
        return i == 0 && j == 0;
    }
};