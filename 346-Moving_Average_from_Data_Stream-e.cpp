// Given a stream of integers and a window size, calculate the moving average of
// all integers in the sliding window.
// For example,
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3

class MovingAverage {
  public:
    /** Initialize your data structure here. */
    MovingAverage(int size) : sz(size) {}

    double next(int val) {
        if (cnt < sz)
            ++cnt;
        else {
            sum -= vals.front();
            vals.pop_front();
        }
        sum += val;
        vals.push_back(val);
        // return cnt ? static_cast<double>(sum) / cnt : DBL_MAX;
        return static_cast<double>(sum) / cnt;
    }

  private:
    int sz = 0, cnt = 0, sum = 0;
    deque<int> vals;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */