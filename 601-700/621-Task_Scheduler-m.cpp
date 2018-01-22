// Given a char array representing tasks CPU need to do. It contains capital
// letters A to Z where different letters represent different tasks.Tasks could
// be done without original order. Each task could be done in one interval. For
// each interval, CPU could finish one task or just be idle.

// However, there is a non-negative cooling interval n that means between two
// same tasks, there must be at least n intervals that CPU are doing different
// tasks or just be idle.

// You need to return the least number of intervals the CPU will take to finish
// all the given tasks.

// Example 1:

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

// Note:

//     The number of tasks is in the range [1, 10000].
//     The integer n is in the range [0, 100].

// method 1: sort
class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        if (!n)
            return tasks.size();

        vector<int> task_cnt(26);

        for (auto &t : tasks)
            ++task_cnt[t - 'A'];

        // from big to small
        sort(task_cnt.rbegin(), task_cnt.rend());
        // remove(task_cnt.begin(), task_cnt.end(), 0);

        int ret = 0;

        while (task_cnt[0] > 0) {
            for (int i = 0; i <= n && task_cnt[0] > 0; ++i) {
                ++ret; // task or idle
                if (i < task_cnt.size() && task_cnt[i] > 0)
                    --task_cnt[i];
            }
            sort(task_cnt.rbegin(), task_cnt.rend());
        }

        return ret;
    }
};

// method 2
class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> task_cnt(26);
        for (auto &t : tasks)
            ++task_cnt[t - 'A'];

        int max_val = *max_element(task_cnt.begin(), task_cnt.end());

        int period = (max_val - 1) * (n + 1);

        for (auto &tc : task_cnt)
            if (tc == max_val)
                ++period;

        return max(static_cast<int>(tasks.size()), period); // think about why
    }
};

// method 3: priority queue, similar to sort
class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> task_cnt(26);
        for (auto &t : tasks)
            ++task_cnt[t - 'A'];

        priority_queue<int> pq;
        // actually sort and remove 0
        for (auto &tc : task_cnt)
            if (tc > 0) // here !tc is wrong, have not figured out why
                pq.push(tc);

        int ret = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cnt = 0;
            for (int i = 0; i <= n && !pq.empty(); ++i) {
                ++cnt; // non idle counter
                temp.push_back(pq.top());
                pq.pop();
            }

            for (auto &t : temp)
                if (--t)
                    pq.push(t);

            ret += pq.empty() ? cnt : (n + 1);
        }

        return ret;
    }
};