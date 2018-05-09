#include <iostream>
#include <vector>

using namespace std;

template <typename T> class QuickSort {
    int partition(vector<T> &A, int l, int r) {
        // element less than the pivot will be put here
        int store_i = l;
        // (randomly) select pivot and put pivot at r
        swap(A[l + rand() % (r - l + 1)], A[r]);
        for (int i = l; i < r; ++i)
            if (A[i] < A[r])
                swap(A[store_i++], A[i]);
        // move pivot to the correct place
        swap(A[r], A[store_i]);
        // return pivot
        return store_i;
    }

  public:
    void qs(vector<T> &A, int l, int r) {
        if (l < r) {
            int pivot_i = partition(A, l, r);
            qs(A, l, pivot_i - 1);
            qs(A, pivot_i + 1, r);
        }
    }

    void qs(vector<T> &A) { qs(A, 0, A.size() - 1); }
};

int main() {
    vector<int> unsorted = {3, 2, 1, 5, 9, 7, 4};
    QuickSort<int> sorter;
    sorter.qs(unsorted);
    for (auto x : unsorted)
        cout << x << ' ';
    cout << endl;

    return 0;
}