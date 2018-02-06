// Given the running logs of n functions that are executed in a nonpreemptive
// single threaded CPU, find the exclusive time of these functions.

// Each function has a unique id, start from 0 to n-1. A function may be called
// recursively or by another function.

// A log is a string has this format : function_id:start_or_end:timestamp. For
// example, "0:start:0" means function 0 starts from the very beginning of time
// 0. "0:end:0" means function 0 ends to the very end of time 0.

// Exclusive time of a function is defined as the time spent within this
// function, the time spent by calling other functions should not be considered
// as this function's exclusive time. You should return the exclusive time of
// each function sorted by their function id.

// Example 1:

// Input:
// n = 2
// logs =
// ["0:start:0",
//  "1:start:2",
//  "1:end:5",
//  "0:end:6"]
// Output:[3, 4]
// Explanation:
// Function 0 starts at time 0, then it executes 2 units of time and reaches the
// end of time 1. Now function 0 calls function 1, function 1 starts at time 2,
// executes 4 units of time and end at time 5. Function 0 is running again at
// time 6, and also end at the time 6, thus executes 1 unit of time. So function
// 0 totally execute 2 + 1 = 3 units of time, and function 1 totally execute 4
// units of time.

// Note:

//     Input logs will be sorted by timestamp, NOT log id.
//     Your output should be sorted by function id, which means the 0th element
//     of your output corresponds to the exclusive time of function 0. Two
//     functions won't start or end at the same time. Functions could be called
//     recursively, and will always end. 1 <= n <= 100

// WTF the problem description is
class Solution {
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> ret(n);

        vector<vector<int>> ilogs(logs.size(), vector<int>(3));
        // ilogs[i] == {id, start or end, time}, with unified timestamp

        for (int i = 0; i < logs.size(); ++i) {
            auto c = logs[i].find(':');
            ilogs[i][0] = stoi(logs[i].substr(0, c));
            ilogs[i][1] = logs[i][c + 1];
            ilogs[i][2] = stoi(logs[i].substr(logs[i].rfind(':') + 1)) +
                          (ilogs[i][1] == 'e');
        }

        stack<vector<int>> s;

        for (int i = 0; i < ilogs.size(); ++i) {
            if (s.empty()) {
                s.push(ilogs[i]);
                continue;
            }

            ret[s.top()[0]] += ilogs[i][2] - s.top()[2];
            if (ilogs[i][0] == s.top()[0] && ilogs[i][1] == 'e') {
                int t = ilogs[i][2];
                s.pop();
                if (!s.empty())
                    s.top()[2] = t;
            } else
                s.push(ilogs[i]);

            // cout << ret[0] << ' ' << ret[1] << endl;
        }

        return ret;
    }
};

// simplified
class Solution {
  public:
    vector<int> exclusiveTime(int n, vector<string> &logs) {
        vector<int> ret(n);

        stack<array<int, 3>> s;
        int id, status, t; // {id, status, unified timestamp}

        for (auto &&lg : logs) {
            auto c = lg.find(':');
            id = stoi(lg.substr(0, c));
            status = lg[c + 1];
            t = stoi(lg.substr(lg.rfind(':') + 1)) + (status == 'e');

            if (s.empty()) {
                s.push({id, status, t});
                continue;
            }

            ret[s.top()[0]] += t - s.top()[2];
            if (id == s.top()[0] && status == 'e') {
                s.pop();
                if (!s.empty())
                    s.top()[2] = t;
            } else
                s.push({id, status, t});
        }

        return ret;
    }
};