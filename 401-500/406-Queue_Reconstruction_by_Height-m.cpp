// Suppose you have a random list of people standing in a queue. Each person is
// described by a pair of integers (h, k), where h is the height of the person
// and k is the number of people in front of this person who have a height
// greater than or equal to h. Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// method 1
class Solution {
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        auto ret = people;

        // vector<int> index(people.size());
        // iota(index.begin(), index.end(), 0);
        set<int> index;
        for (int i = 0; i < ret.size(); ++i)
            index.insert(i);

        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        // for(auto &&a : people)
        //     cout << '['  << a.first << ' ' << a.second << "] ";
        // cout << endl;
        // for input [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        // sorted to  [4 4] [5 0] [5 2] [6 1] [7 0] [7 1]

        int prevh = -1, cnt;
        for (int i = 0; i < people.size(); ++i) {
            if (people[i].first == prevh)
                ++cnt;
            else
                cnt = 0;
            prevh = people[i].first;

            auto index_it = index.begin();
            advance(index_it, people[i].second - cnt); // reti_order

            ret[*index_it] = people[i];

            index.erase(index_it);
        }

        return ret;
    }
};

// method 2
class Solution {
  public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        // for input [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
        // sorted to  [7 0] [7 1] [6 1] [5 0] [5 2] [4 4]

        vector<pair<int, int>> ret;

        for (auto &&p : people)
            ret.insert(ret.begin() + p.second, p);

        return ret;
    }
};