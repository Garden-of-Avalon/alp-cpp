//  There are N gas stations along a circular route, where the amount of gas at
//  station i is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to
// travel from station i to its next station (i+1). You begin the journey with
// an empty tank at one of the gas stations.

// Return the starting gas station's index if you can travel around the circuit
// once, otherwise return -1.

// Note:
// The solution is guaranteed to be unique.

class Solution {
  public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> net(gas.size());

        for (int i = 0; i < gas.size(); ++i)
            net[i] = gas[i] - cost[i];

        int first_minus_net_i = -1;
        for (int i = 0; i < net.size(); ++i)
            if (net[i] < 0) {
                first_minus_net_i = i;
                break;
            }
        if (first_minus == -1)
            return 0;

        vector<int> begins;

        for (int i = first_minus + 1; i % net.size() != first_minus; ++i) {
            int ti = i % net.size();
            if (net[ti] > 0) {
                begins.push_back(ti);
                while (net[ti % net.size()] > 0)
                    ++ti;
                i = ti - 1; // i will increase 1 later
            }
        }

        // test begins
        for (auto &&beg : begins) {
            int test_net = net[beg];
            for (int i = beg + 1; i % net.size() != beg; ++i)
                if ((test_net += net[i % net.size()]) < 0)
                    break;
            if (test_net >= 0)
                return beg;
        }

        return -1;
    }
};

// ref: O(n), O(1)
// class Solution {
//   public:
//     int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
//         int start = gas.size() - 1, end = 0;
//         int sum = gas[start] - cost[start];
//         while (start > end) {
//             if (sum >= 0) {
//                 sum += gas[end] - cost[end];
//                 ++end;
//             } else {
//                 --start;
//                 sum += gas[start] - cost[start];
//             }
//         }
//         // start == end
//         return sum >= 0 ? start : -1;
//     }
// };

// ref2
// class Solution {
//   public:
//     int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
//         int start = 0, total_minus = 0, tank = 0;
//         for (int i = 0; i < gas.size(); i++)
//             if ((tank += gas[i] - cost[i]) < 0) {
//                 start = i + 1;
//                 total_minus += tank;
//                 tank = 0;
//             }
//         return (total_minus + tank < 0) ? -1 : start;
//     }
// };