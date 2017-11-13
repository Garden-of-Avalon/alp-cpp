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
        sum += val;
        vals.push(val);

        if (vals.size() > sz) {
            sum -= vals.front();
            vals.pop();
        }

        // return cnt ? static_cast<double>(sum) / cnt : DBL_MAX;
        return sum / vals.size();
    }

  private:
    int sz = 0;
    double sum = 0;
    queue<int> vals;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */