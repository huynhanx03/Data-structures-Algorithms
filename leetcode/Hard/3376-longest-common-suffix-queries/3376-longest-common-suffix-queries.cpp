/*
 Problem: 3376. Longest Common Suffix Queries
 Language: cpp
 Runtime: 81 ms (82.35%)
 Memory: 147.4 MB (96.96%)
 Tags: Array, String, Trie
*/
class Solution {
public:
    static constexpr int N = 1000005;

    struct Node {
        int next[26];
        int id;
        int len;
    };

    static Node trie[N];

    int ptr = 1;

    Solution() {
        memset(trie[0].next, -1, sizeof(trie[0].next));
        trie[0].id = -1;
        trie[0].len = INT_MAX;
    }

    int newNode() {
        memset(trie[ptr].next, -1, sizeof(trie[ptr].next));
        trie[ptr].id = -1;
        trie[ptr].len = INT_MAX;
        return ptr++;
    }

    void update(int p, int i, int l) {
        if (l < trie[p].len) {
            trie[p].len = l;
            trie[p].id = i;
        }
    }

    void add(const string& s, int i) {
        int p = 0;

        update(p, i, s.size());

        for (int j = s.size() - 1; j >= 0; --j) {
            int c = s[j] - 'a';

            if (trie[p].next[c] == -1) {
                trie[p].next[c] = newNode();
            }

            p = trie[p].next[c];

            update(p, i, s.size());
        }
    }

    int get(const string& s) {
        int p = 0;

        for (int j = s.size() - 1; j >= 0; --j) {
            int c = s[j] - 'a';

            if (trie[p].next[c] == -1) {
                break;
            }

            p = trie[p].next[c];
        }

        return trie[p].id;
    }

    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        for (int i = 0; i < wc.size(); ++i) {
            add(wc[i], i);
        }

        vector<int> ans;
        ans.reserve(wq.size());

        for (const auto& s : wq) {
            ans.push_back(get(s));
        }

        return ans;
    }
};

Solution::Node Solution::trie[Solution::N];