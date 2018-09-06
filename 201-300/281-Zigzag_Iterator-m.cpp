// Given two 1d vectors, implement an iterator to return their elements
// alternately.

// Example:

// Input:
// v1 = [1,2]
// v2 = [3,4,5,6]

// Output: [1,3,2,4,5,6]

// Explanation: By calling next repeatedly until hasNext returns false,
//              the order of elements returned by next should be: [1,3,2,4,5,6].
// Follow up: What if you are given k 1d vectors? How well can your code be
// extended to such cases?

// Clarification for the follow up question:
// The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases.
// If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For
// example:

// Input:
// [1,2,3]
// [4,5,6,7]
// [8,9]

// Output: [1,4,8,2,5,9,3,6,7].

class ZigzagIterator {
    vector<vector<int>::iterator> its, ends;
    int V = 1;

  public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        its.push_back(v1.begin());
        its.push_back(v2.begin());
        ends.push_back(v1.end());
        ends.push_back(v2.end());
    }

    int next() { return *its[V]++; }

    bool hasNext() {
        V ^= 1;

        bool ret = false;
        ret = its[V] != ends[V];

        if (!ret) {
            V ^= 1;
            ret = its[V] != ends[V];
        }

        return ret;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */