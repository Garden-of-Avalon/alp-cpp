//  Implement a trie with insert, search, and startsWith methods.

// Note:
// You may assume that all inputs are consist of lowercase letters a-z.

// different from Java, don't forget destrctor
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

class Trie {
  public:
    /** Initialize your data structure here. */
    Trie() { root = new TrieNode(); }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto *p = root;
        for (int i = 0; i < word.size(); ++i) {
            if (p->next[word[i] - 'a'] == nullptr)
                p->next[word[i] - 'a'] = new TrieNode();
            p = p->next[word[i] - 'a'];
        }
        p->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto *p = find(word);
        return p != nullptr && p->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) { return find(prefix) != nullptr; }

    ~Trie() { delete root; }

  private:
    TrieNode *root;

    TrieNode *find(const string &key) {
        auto *p = root;
        for (int i = 0; i < key.size() && p != nullptr; ++i)
            p = p->next[key[i] - 'a'];
        return p;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */