//  Design a data structure that supports the following two operations:

// void addWord(word)
// bool search(word)

// search(word) can search a literal word or a regular expression string
// containing only letters a-z or .. A . means it can represent any one letter.

// For example:

// addWord("bad")
// addWord("dad")
// addWord("mad")
// search("pad") -> false
// search("bad") -> true
// search(".ad") -> true
// search("b..") -> true

// Note:
// You may assume that all words are consist of lowercase letters a-z.

// click to show hint.
// You should be familiar with how a Trie works. If not, please work on this
// problem: Implement Trie (Prefix Tree) first.

// ref: 208
class TrieNode {
  public:
    array<TrieNode *, 26> next;
    bool is_word = false;

    TrieNode() { next.fill(nullptr); }
    ~TrieNode() {
        for (auto &n : next)
            if (n != nullptr)
                delete n;
    }
};

class WordDictionary {
  public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        auto *p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) { return find(word, 0, root); }

    ~WordDictionary() { delete root; }

  private:
    TrieNode *root;

    bool find(const string &key, int i, TrieNode *p) {
        if (!p)
            return false;

        if (i == key.size())
            return p->is_word;

        if (key[i] == '.') {
            for (int j = 0; j < 26; ++j)
                if (find(key, i + 1, p->next[j]))
                    return true;
            return false;
        } else
            return find(key, i + 1, p->next[key[i] - 'a']);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */