#include <iostream>
#include <vector>

using namespace std;

template <typename T> class HeapSort {
    // make A[root-end) a heap
    void heapify(vector<T> &A, int root, int end) {
        int left = 2 * root + 1, right = left + 1;

        int max_of_three = root; // max of root and its childs
        if (left < end && A[left] > A[max_of_three])
            max_of_three = left;
        if (right < end && A[right] > A[max_of_three])
            max_of_three = right;

        if (max_of_three != root) {
            swap(A[root], A[max_of_three]);
            heapify(A, max_of_three, end);
        }
    }

  public:
    void hs(vector<T> &A) {
        // pre-build whole vector as heap, O(n)
        for (int i = A.size() / 2 - 1; i >= 0; --i)
            heapify(A, i, A.size());

        // O(nlogn)
        // for each step:
        // select max, move down root to correct position
        for (int i = A.size() - 1; i >= 0; --i) {
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