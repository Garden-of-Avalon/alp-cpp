//  Suppose you are at a party with n people (labeled from 0 to n - 1) and among
//  them, there may exist one celebrity. The definition of a celebrity is that
//  all the other n - 1 people know him/her but he/she does not know any of
//  them.

// Now you want to find out who the celebrity is or verify that there is not
// one. The only thing you are allowed to do is to ask questions like: "Hi, A.
// Do you know B?" to get information of whether A knows B. You need to find out
// the celebrity (or verify there is not one) by asking as few questions as
// possible (in the asymptotic sense).

// You are given a helper function bool knows(a, b) which tells you whether A
// knows B. Implement a function int findCelebrity(n), your function should
// minimize the number of calls to knows.

// Note: There will be exactly one celebrity if he/she is in the party. Return
// the celebrity's label if there is a celebrity in the party. If there is no
// celebrity, return -1.

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
  public:
    int findCelebrity(int n) {
        vector<int> cnt(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j && cnt[j] >= i - 1)
                    cnt[j] += knows(i, j);

        int celei = -1;
        for (int i = 0; i < n; ++i)
            if (cnt[i] == n - 1)
                if (celei == -1)
                    celei = i;
                else
                    return -1;

        if (celei != -1)
            for (int j = 0; j < n; ++j)
                if (celei != j && knows(celei, j))
                    return -1;

        return celei;
    }
};

// O(n)
class Solution {
  public:
    int findCelebrity(int n) {
        int celei = 0; // candidate

        for (int i = 1; i < n; ++i)
            if (knows(celei, i))
                celei = i;

        for (int i = 0; i < celei; ++i)
            if (knows(celei, i))
                return -1;

        for (int i = 0; i < n; ++i)
            if (i != celei && !knows(i, celei))
                return -1;

        // 2 pass method, actually same
        // For a valid celei:
        // Previous method 2nd and 3rd 'for' call knows() celei + n - 1 times;
        // Following one call knows() 2 * (n - 1) times.
        // for (int i = 0; i < n; ++i)
        //     if (i != celei && (!knows(i, celei) || knows(celei, i)))
        //         return -1;

        return celei;
    }
};