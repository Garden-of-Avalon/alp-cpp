// This problem is an interactive problem new to the LeetCode platform.

// We are given a word list of unique words, each word is 6 letters long, and
// one word in this list is chosen as secret.

// You may call master.guess(word) to guess a word.  The guessed word should
// have type string and must be from the original list with 6 lowercase letters.

// This function returns an integer type, representing the number of exact
// matches (value and position) of your guess to the secret word.  Also, if your
// guess is not in the given wordlist, it will return -1 instead.

// For each test case, you have 10 guesses to guess the word. At the end of any
// number of calls, if you have made 10 or less calls to master.guess and at
// least one of these guesses was the secret, you pass the testcase.

// Besides the example test case below, there will be 5 additional test cases,
// each with 100 words in the word list.  The letters of each word in those
// testcases were chosen independently at random from 'a' to 'z', such that
// every word in the given word lists is unique.

// Example 1:
// Input: secret = "acckzz", wordlist = ["acckzz","ccbazz","eiowzz","abcczz"]

// Explanation:

// master.guess("aaaaaa") returns -1, because "aaaaaa" is not in wordlist.
// master.guess("acckzz") returns 6, because "acckzz" is secret and has all 6
// matches. master.guess("ccbazz") returns 3, because "ccbazz" has 3 matches.
// master.guess("eiowzz") returns 2, because "eiowzz" has 2 matches.
// master.guess("abcczz") returns 4, because "abcczz" has 4 matches.

// We made 5 calls to master.guess and one of them was the secret, so we pass
// the test case. Note:  Any solutions that attempt to circumvent the judge will
// result in disqualification.

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
    int match(const string &a, const string &b) {
        int ret = 0;
        for (int i = 0; i < 6; ++i)
            if (a[i] == b[i])
                ++ret;
        return ret;
    }

  public:
    void findSecretWord(vector<string> &wordlist, Master &master) {
        int guessCnt = 10, guessRes = 0;
        while (guessCnt-- > 0) {
            // find most "popular", min(cnt(matchRes == 0)) word
            unordered_map<string, int> freq;
            for (auto &&w1 : wordlist)
                for (auto &&w2 : wordlist)
                    if (match(w1, w2) == 0)
                        ++freq[w1];
            pair<string, int> minimax = {wordlist[0], 100};
            for (auto &&w : wordlist)
                if (freq[w] <= minimax.second)
                    minimax = {w, freq[w]};

            // guess
            if ((guessRes = master.guess(minimax.first)) == 6)
                return;

            // reset wordlist
            vector<string> wordlist2;
            for (auto &&w : wordlist)
                if (match(minimax.first, w) == guessRes)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }
};