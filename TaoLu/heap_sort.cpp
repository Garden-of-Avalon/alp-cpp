#include <iostream>
#include <vector>

using namespace std;

template <typename T> class HeapSort {
    // make A[root] the max value of the subtree
    void heapify(vector<T> &A, int root, int end) {
        int max_val_idx = root;
        int left = 2 * root + 1, right = left + 1;

        if (left < end && A[left] > A[max_val_idx])
            max_val_idx = left;
        if (right < end && A[right] > A[max_val_idx])
            max_val_idx = right;

        if (max_val_idx != root) {
            swap(A[root], A[max_val_idx]);
            heapify(A, max_val_idx, end);
        }
    }

  public:
    void hs(vector<T> &A) {
        for(int i = A.size() / 2 - 1; i >= 0; --i) 
            heapify(A, i, A.size());
        
        for(int i = A.size() - 1; i >= 0; --i) {
            swap(A[0], A[i]);
            heapify(A, 0, i);
        }
    }
};

int main() {
    vector<int> unsorted = {3, 2, 1, 5, 9, 7, 4};
    HeapSort<int> sorter;
    sorter.hs(unsorted);
    for (auto x : unsorted)
        cout << x << ' ';
    cout << endl;

    return 0;
}