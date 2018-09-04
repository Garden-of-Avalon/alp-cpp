// Given a list accounts, each element accounts[i] is a list of strings, where
// the first element accounts[i][0] is a name, and the rest of the elements are
// emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to
// the same person if there is some email that is common to both accounts. Note
// that even if two accounts have the same name, they may belong to different
// people as people could have the same name. A person can have any number of
// accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the
// first element of each account is the name, and the rest of the elements are
// emails in sorted order. The accounts themselves can be returned in any order.

// Example 1:
// Input:
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John",
// "johnnybravo@mail.com"], ["John", "johnsmith@mail.com",
// "john_newyork@mail.com"], ["Mary", "mary@mail.com"]] Output: [["John",
// 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John",
// "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]

// Explanation:
// The first and third John's are the same person as they have the common email
// "johnsmith@mail.com". The second John and Mary are different people as none
// of their email addresses are used by other accounts. We could return these
// lists in any order, for example the answer [['Mary', 'mary@mail.com'],
// ['John', 'johnnybravo@mail.com'],
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']]
// would still be accepted. Note:

// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].

// DFS
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acnts) {
        unordered_map<string, unordered_set<string>> graph; // email, neighbors
        unordered_map<string, string> e_name;               // email, name

        for (auto &&a : acnts)
            for (int i = 1; i < a.size(); ++i) {
                graph[a[i]].insert(a.begin() + 1, a.end());
                if (!e_name.count(a[i]))
                    e_name[a[i]] = a[0];
            }

        vector<vector<string>> ret;

        // lambda to update temp set
        // add current email, and dfs neighbors
        auto update = [&](auto &&self, auto &tmp, auto &&e) -> void {
            if (e_name[e] == "")
                return;
            tmp.insert(e);
            e_name[e] = "";
            for (auto &nbor : graph[e])
                self(self, tmp, nbor);
        };

        for (auto &e_n : e_name) {
            if (e_name[e_n.first] == "")
                continue;

            ret.push_back({e_n.second});

            set<string> tmp;
            update(update, tmp, e_n.first);

            copy(tmp.begin(), tmp.end(), back_inserter(ret.back()));
        }

        return ret;
    }
};

// Disjoint Set Union (DSU) structure
class Solution {
    struct DSU {
        vector<int> parent;

        DSU(int n = 1000) { 
            parent = vector<int>(n * 10 + 1);
            iota(parent.begin(), parent.end(), 0);
        }

        int findRoot(int x) {
            while (parent[x] != x)
                x = parent[x];
            return x;
        }

        void unionIds(int x, int y) { parent[findRoot(x)] = findRoot(y); }
    };

  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acnts) {
        DSU dsu(acnts.size());
        unordered_map<string, string> e_name; // email, name
        unordered_map<string, int> e_id;      // email, id
        int id = 0;

        for (auto &&a : acnts)
            for (int i = 1; i < a.size(); ++i) {
                if (!e_name.count(a[i]))
                    e_name[a[i]] = a[0];

                if (!e_id.count(a[i]))
                    e_id[a[i]] = id++;

                dsu.unionIds(e_id[a[1]], e_id[a[i]]);
            }

        unordered_map<int, set<string>> id_emails;
        for (auto &e_i : e_id) 
            id_emails[dsu.findRoot(e_i.second)].insert(e_i.first);

        vector<vector<string>> ret;
        for_each(id_emails.begin(), id_emails.end(), [&](auto &i_es) {
            auto &emails = i_es.second;
            ret.push_back({e_name[*emails.begin()]});
            copy(emails.begin(), emails.end(), back_inserter(ret.back()));
        });

        return ret;
    }
};