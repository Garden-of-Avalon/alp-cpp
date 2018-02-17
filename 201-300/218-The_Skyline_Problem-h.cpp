// A city's skyline is the outer contour of the silhouette formed by all the
// buildings in that city when viewed from a distance. Now suppose you are given
// the locations and height of all the buildings as shown on a cityscape photo
// (Figure A), write a program to output the skyline formed by these buildings
// collectively (Figure B).

// The geometric information of each building is represented by a triplet of
// integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and
// right edge of the ith building, respectively, and Hi is its height. It is
// guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. You
// may assume all buildings are perfect rectangles grounded on an absolutely
// flat surface at height 0.

// For instance, the dimensions of all buildings in Figure A are recorded as: [
// [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

// The output is a list of "key points" (red dots in Figure B) in the format of
// [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key
// point is the left endpoint of a horizontal line segment. Note that the last
// key point, where the rightmost building ends, is merely used to mark the
// termination of the skyline, and always has zero height. Also, the ground in
// between any two adjacent buildings should be considered part of the skyline
// contour.

// For instance, the skyline in Figure B should be represented as:[ [2 10], [3
// 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

// Notes:

//     The number of buildings in any input list is guaranteed to be in the
//     range [0, 10000]. The input list is already sorted in ascending order by
//     the left x position Li. The output list must be sorted by the x position.
//     There must be no consecutive horizontal lines of equal height in the
//     output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...]
//     is not acceptable; the three lines of height 5 should be merged into one
//     in the final output as such: [...[2 3], [4 5], [12 7], ...]

// Credits:
// Special thanks to @stellari for adding this problem, creating these two
// awesome images and all test cases.

// ref: meeting room 252, 253
class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        // hts: (left, -h) & (right, h)
        vector<pair<int, int>> hts;

        for (auto &&b : buildings) {
            hts.push_back({b[0], -b[2]});
            hts.push_back({b[1], b[2]});
        }

        // left at first, lower at first
        sort(hts.begin(), hts.end(), [](auto &&p1, auto &&p2) {
            if (p1.first != p2.first)
                return p1.first < p2.first;
            return p1.second < p2.second;
        });

        // for Java we can use priority_queue
        // because C++ pq don't have remove method, we use multiset
        multiset<int, greater<int>> currh;
        currh.insert(0);

        vector<pair<int, int>> ret;
        int prevh = 0;
        for (auto &&p : hts) {
            if (p.second < 0)
                currh.insert(-p.second);
            else
                currh.erase(currh.find(p.second)); // only erase one element

            if (prevh != *currh.begin()) {
                ret.push_back(make_pair(p.first, *currh.begin()));
                prevh = *currh.begin();
            }
        }

        return ret;
    }
};

// method 2
class Solution {
  public:
    vector<pair<int, int>> getSkyline(vector<vector<int>> &buildings) {
        priority_queue<pair<int, int>> currh; // current height, right_x
        currh.push({0, INT_MAX}); // make the beginning and ending work
        vector<pair<int, int>> ret;

        auto godown = [&]() {
            auto p = currh.top();
            currh.pop();
            if (p.first >= currh.top().first) {
                // remove old finished right_x
                while (p.second > currh.top().second)
                    currh.pop();
                // down
                if (currh.top().first < ret.back().second)
                    // already have the x value, update
                    if (p.second == ret.back().first)
                        ret.back().second = currh.top().first;
                    else
                        ret.push_back({p.second, currh.top().first});
            }
        };

        auto goup = [&](auto &&left_x) {
            // up
            if (ret.empty() || currh.top().first > ret.back().second)
                // already have the x value, update
                if (!ret.empty() && left_x == ret.back().first)
                    ret.back().second = currh.top().first;
                else
                    ret.push_back({left_x, currh.top().first});
        };

        for (auto &&b : buildings) {
            // previous highest right_x < curr_left_x
            // go down
            while (currh.top().second < b[0])
                godown();

            currh.push({b[2], b[1]});

            // go up
            goup(b[0]);
        }

        while (currh.size() > 1)
            godown();

        return ret;
    }
};